/*******************************************************************************
 * Name: cave5d.c    Config_No: 1.22    Date: 08/01/01
 ******************************************************************************
 *
 * Cave5d: Version 2.0 - August 2001
 * Copyright (C) 1996-1998
 * Copyright (C) 2001
 *
 * Sheri A. Mickelson and John Taylor
 *     Argonne National Laboratory
 *     Argonne, Illinois 60439
 *     http://www-climate.mcs.anl.gov/
 * 
 * Glen Wheless and Cathy Lascara
 *     Center for Coastal Physical Oceanography
 *     Old Dominion University, Norfolk, VA 23539
 * Bill Hibbard and Brian Paul
 *     Space Science and Engineering Center
 *     University of Wisconsin, Madison, WI 53706
 *
 * Cave5d is integrated with:
 *     1) VIS-5D Version 5.2 (http://www.ssec.wisc.edu/~billh/vis5d.html)
 *     2) CAVE Library Version 2.7.1 (http://evlweb.eecs.uic.edu/EVL/VR/)
 * 
 * Contributions by:
 *     Brandon Hill
 *     Larry E. Ramey (ramey@ccpo.odu.edu)
 *     Center for Coastal Physical Oceanography
 *     Old Dominion University, Norfolk, VA 23539
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation. 
 * This program is distributed WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 * See the GNU General Public License for more details.
 */


/*******************************************************************************
 * 
 * Compilation Unit: cave5d.c
 *
 * init_gl
 * SetNavMatrix 
 * display
 * per_frame
 * cave5d_nav_init
 * init_vis5d
 * init_ui
 * event_loop
 * main
 *
 */

/* utility */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <malloc.h>
/* 05Dec05  Phil McDonald */
#include <math.h>
#include <sys/time.h>
/* 09Nov06  Phil McDonald */
#include "X11/Xlib.h"
/* end PM */

/* vis5d support */
#include "api.h"
#include "v5d.h"
//#include "gui.h"

/* application specific */
#include "cave5d.h"
#include "panelUI.h"
#include "puiSupport.h"
/* 20Jul07  Phil McDonald */
#include "vrlib.h"
/* 30Oct06  Phil McDonald */
#ifdef CPP
#  include "c5d_vector.h"
#  include "c5d_bar_graph.h"
#  include "c5d_surface.h"
#endif
/* end PM */



/* Structure containing shared data for application */
static APP_MGR *amgr;



#ifndef HAVE_PTHREADS
/* 23Jul07  Phil McDonald */
int cave5d_mutex_init (void)
{
    fprintf (stderr, "CAVE5D: not using pthreads.\n");
    return 1;
}
/* end PM */
#else
/* 25Apr07  Phil McDonald */
#  include <pthread.h>
#  include <semaphore.h>



/* With pthreads enabled, the pthread mutexes are statically allocated as  */
/* pthread_mutex_t data structures.  However, we want the mutexes to be    */
/* in shared memory so that all of the renderers can have access to them.  */
/* To accomplish this, we'll allocate a semaphore structure in shared      */
/* memory and store the pointer to this structure in the pthread mutex     */
/* structure.  This should only cause a problem if the size of the pthread */
/* mutex structure is less than the size of a pointer.  Since the pthread  */
/* mutex structure holds 3 ints and some other stuff, it should be plenty  */
/* big enough to hold a pointer.                                           */

int cave5d_mutex_alloc (pthread_mutex_t * p_pthread_mutex,
                        const pthread_mutexattr_t * p_mutex_attr)
{

    sem_t      *p_sem;



    p_sem = vis5d_mem_malloc (sizeof (sem_t));
    sem_init (p_sem, 1, 1);

    *(sem_t **) p_pthread_mutex = p_sem;


    return 0;
}



int cave5d_mutex_free (pthread_mutex_t * p_pthread_mutex)
{
    sem_destroy (*(sem_t **) p_pthread_mutex);
    vis5d_mem_free (*(sem_t **) p_pthread_mutex);


    return 0;
}



int cave5d_mutex_lock (pthread_mutex_t * p_pthread_mutex)
{
    sem_wait (*(sem_t **) p_pthread_mutex);


    return 0;
}



int cave5d_mutex_unlock (pthread_mutex_t * p_pthread_mutex)
{
    sem_post (*(sem_t **) p_pthread_mutex);


    return 0;
}



/* 23Jul07  Phil McDonald */
int cave5d_mutex_init (void)
{
    fprintf (stderr, "CAVE5D: using pthreads.\n");
    vis5d_sync_set_funcs (&cave5d_mutex_alloc, &cave5d_mutex_free,
                          &cave5d_mutex_lock, &cave5d_mutex_unlock);
    return 1;
}
/* end PM */
#endif



/*******************************************************************************
 *
 *  Cave5D utility functions
 *
 *******************************************************************************
 */

/* 20Dec05 Phil McDonald	find data context index and var number */
int cave5d_find_var (int idispctx, char *var_name, int *p_idatactx, int *p_ivar)
{
    int         i, ivar, idatactx, ndatactx, datactx[VIS5D_MAX_CONTEXTS];
    char       *p_tmp;


    if (var_name == NULL) return CAVE5D_UNKNOWN;


/*
 *  See if the data context index has been appended to the variable name
 *  (e.g. VAR.0), the same form used by the Vis5D GUI.
 */

    if ((p_tmp = strrchr (var_name, '.')) != NULL)
    {
        if (sscanf ((p_tmp + 1), "%d", &idatactx) == 1)
        {
            *p_tmp = '\0';
            ivar = vis5d_find_var (idatactx, var_name);
            *p_tmp = '.';
            if (ivar >= 0)
            {
                if (p_idatactx != NULL) *p_idatactx = idatactx;
                if (p_ivar     != NULL) *p_ivar     = ivar;
                return ivar;
            }
        }
    }


/*
 *  Try to find the variable name in each of the data contexts.
 *  This will work fine if the variable names in each data context
 *  are unique, but identical variable names in multiple data contexts
 *  are ambiguous.
 */

    if (vis5d_get_num_of_ctxs_in_display (idispctx, &ndatactx, datactx) == 0)
    {
        for (i = 0; i < ndatactx; i++)
        {
            idatactx = datactx[i];
            if ((ivar = vis5d_find_var (idatactx, var_name)) >= 0)
            {
                if (p_idatactx != NULL) *p_idatactx = idatactx;
                if (p_ivar     != NULL) *p_ivar     = ivar;
                return ivar;
            }
        }
    }
    fprintf (stderr, "CAVE5D: ERROR: %s cannot be found in data context(s).\n",
             var_name);

    if (p_idatactx != NULL) *p_idatactx = CAVE5D_UNKNOWN;
    if (p_ivar     != NULL) *p_ivar     = CAVE5D_UNKNOWN;


    return CAVE5D_UNKNOWN;
}
/* end PM */



/* 01Sep06  Phil McDonald */
static int cave5d_time_usec (void)
{
    struct timeval time_now;



    gettimeofday (&time_now, NULL);

    return (((time_now.tv_sec % 1000) * 1000000) + time_now.tv_usec);
}
/* end PM */



/* 16Jul07  Phil McDonald */
static int cave5d_diff_scale (float *p_val, float val_base, int accentuate)
{
    float       val, val_sign;



    if (p_val == NULL) return 0;
    val = *p_val;

    if (val_base == 0.0) val_base = 1.0;

    val     /= val_base;
    val_sign = (val < 0.0) ? -1.0 : 1.0;
    if (accentuate)
    {
        val = sqrt (val * val_sign) * val_sign;
    }
    else
    {
        val = val * val * val_sign;
    }
    val *= val_base;

    *p_val = val;


    return 1;
}
/* end PM */



/*******************************************************************************
 *
 *  Cave5D rendering functions
 *
 *******************************************************************************
 */
/* 01Feb08  Phil McDonald */
static void cave5d_render_sync (APP_MGR *amgr, int mode)
{
    int         irend;
    RENDER_INFO *p_info;



    p_info = amgr->render_info;


    /* Renderer mode */

    if (mode == CAVE5D_STATUS_FRAME)
    {
        int        pid, itime;

        pid = getpid ();
        vis5d_get_dtx_timestep (amgr->dx, &itime);

        for (irend = 0; irend < amgr->nrender; irend++)
        {
            if (p_info[irend].pid == pid) break;
        }
        if (irend >= amgr->nrender)
        {
            p_info[irend].pid = pid;
            amgr->nrender++;
        }

        p_info[irend].status = CAVE5D_STATUS_PAUSE;

        while (amgr->status == CAVE5D_STATUS_PAUSE) usleep (10);

        p_info[irend].status = CAVE5D_STATUS_OK;
    }


    /* Simulation modes */

    else if (mode == CAVE5D_STATUS_PAUSE)
    {
        amgr->status = CAVE5D_STATUS_PAUSE;

        for (irend = 0; irend < amgr->nrender; irend++)
        {
            while (p_info[irend].status != CAVE5D_STATUS_PAUSE) usleep (10);
        }
    }
    else if (mode == CAVE5D_STATUS_RESUME)
    {
        amgr->status = CAVE5D_STATUS_OK;

        for (irend = 0; irend < amgr->nrender; irend++)
        {
            while (p_info[irend].status == CAVE5D_STATUS_PAUSE) usleep (10);
        }
    }


    return;
}
/* end PM */




/* 11Jul07  Phil McDonald */
static void cave5d_render_lightsaber (APP_MGR *amgr)
{
    float       wand_pos[3], wand_vec[3];
    GLfloat     v[3];



    glPushMatrix ();

    if (amgr->nav_style == CAVE5D_AIRPLANE_NAV)
    {
        glColor4f (1.0, 1.0, 0.0, 1.0);
    }
    else
    {
        glColor4f (1.0, 1.0, 1.0, 1.0);
    }
    glLineWidth (4.0);

    /* move graphic origin to sensor location  */
    vrlib_wand_posvec (wand_pos, wand_vec, 0);
    glTranslatef (wand_pos[0], wand_pos[1], wand_pos[2]);
    wand_vec[0] *= 10.0, wand_vec[1] *= 10.0, wand_vec[2] *= 10.0;
    v[0]         = v[1] = v[2] = 0.0;

    glBegin (GL_LINES);
    if (amgr->scaleMode > 0)
    {
        int    iseg, nseg = 30;

        wand_vec[0] /= 2.0 * (float) nseg;
        wand_vec[1] /= 2.0 * (float) nseg;
        wand_vec[2] /= 2.0 * (float) nseg;
        for (iseg = 0; iseg < nseg; iseg++)
        {
            glVertex3fv (v);
            v[0] += wand_vec[0], v[1] += wand_vec[1], v[2] += wand_vec[2];
            glVertex3fv (v);
            v[0] += wand_vec[0], v[1] += wand_vec[1], v[2] += wand_vec[2];
        }
    }
    else
    {
        glVertex3fv (v);
        glVertex3fv (wand_vec);
    }
    glEnd ();

    glPopMatrix ();
    glLineWidth (1.0);


    return;
}
/* end PM */



/* 30Oct06  Phil McDonald */
static void cave5d_render_c5d (APP_MGR *amgr)
{
#ifdef CPP
    GOVIS5D    *cur;



    for (int gcnt = 0; gcnt < amgr->gobjCnt; ++gcnt)
    {
        cur = &amgr->gobj[gcnt];
        if (cur->mode != 0)
        {
            switch (cur->grType)
            {
                case CAVE5D_VECTOR:
                    c5d_vector * v;
                    v = (c5d_vector *) cur->hook;
                    v->render (amgr);
                    break;
                case CAVE5D_BAR_GRAPH:
                    c5d_bar_graph * bg;
                    bg = (c5d_bar_graph *) cur->hook;
                    bg->render (amgr);
                    break;
                case CAVE5D_SURFACE:
                    c5d_surface * sur;
                    sur = (c5d_surface *) cur->hook;
                    sur->render (amgr);
                    break;

            } /* switch */
        } /* mode if*/
    } /* for */
#endif


    return;
}
/* end PM */



/*
 * Subroutine: Application's graphics initialization callback
 * Identified to CAVE libraries thru CAVEInitApplication()
 */

void cave5d_render_init_GL (int create_dmy)
{
    if (create_dmy)
    {
/* 09Nov06  Phil McDonald	create a GL context for the simulation so  */
/*				that it can use GL functions, if necessary */
/*				(like for texture image scaling).          */

        int         attr_list[] = { GLX_RGBA, None };
        Display     *dummy_dpy;
        int         dummy_scr;
        Window      dummy_win;
        XVisualInfo *dummy_vis;
        GLXContext  dummy_ctx;

        dummy_dpy = XOpenDisplay (NULL);
        dummy_scr = DefaultScreen (dummy_dpy);
        dummy_win = XCreateSimpleWindow (dummy_dpy,
                                         DefaultRootWindow (dummy_dpy),
                                         0, 0, 10, 10, 0,
                                         BlackPixel (dummy_dpy, dummy_scr),
                                         BlackPixel (dummy_dpy, dummy_scr));
        dummy_vis = glXChooseVisual (dummy_dpy, dummy_scr, attr_list);
        dummy_ctx = glXCreateContext (dummy_dpy, dummy_vis, NULL, True);
        if (glXMakeCurrent (dummy_dpy, dummy_win, dummy_ctx))
        {
            fprintf (stderr, "Cave5D: GL: direct connection = True\n");
        }
        else
        {
            glXDestroyContext (dummy_dpy, dummy_ctx);
            dummy_ctx = glXCreateContext (dummy_dpy, dummy_vis, NULL, False);
            if (glXMakeCurrent (dummy_dpy, dummy_win, dummy_ctx))
            {
                fprintf (stderr, "Cave5D: GL: direct connection = False\n");
            }
            else
            {
                fprintf (stderr,
                         "ERROR:  Couldn't make dummy GL context current\n");
            }
        }
    }
/* end PM */

    else
    {
        GLfloat     light0_pos[]     = { amgr->tmp->position_0[0],
                                         amgr->tmp->position_0[1],
                                         amgr->tmp->position_0[2],
                                         0.0
        };
        GLfloat     light_ambient[]  = { amgr->tmp->ambient_0[0],
                                         amgr->tmp->ambient_0[1],
                                         amgr->tmp->ambient_0[2],
                                         1.0
        };
        GLfloat     light_diffuse[]  = { amgr->tmp->diffuse_0[0],
                                         amgr->tmp->diffuse_0[1],
                                         amgr->tmp->diffuse_0[2],
                                         1.0
        };
        GLfloat     light_specular[] = { amgr->tmp->specular_0[0],
                                         amgr->tmp->specular_0[1],
                                         amgr->tmp->specular_0[2],
                                         1.0
        };
        GLfloat     model_ambient[]  = { amgr->tmp->ambient[0],
                                         amgr->tmp->ambient[1],
                                         amgr->tmp->ambient[2],
                                         1.0
        };

        glLightfv (GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv (GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv (GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv (GL_LIGHT0, GL_POSITION, light0_pos);
        glLightModelfv (GL_LIGHT_MODEL_AMBIENT, model_ambient);
        glLightModeli (GL_LIGHT_MODEL_TWO_SIDE, 0);
        glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, 0);
        glEnable (GL_LIGHT0);
        glEnable (GL_NORMALIZE);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

/* 2Jan08  Phil McDonald	save light position for render_display */
        amgr->light0_pos[0] = light0_pos[0];
        amgr->light0_pos[1] = light0_pos[1];
        amgr->light0_pos[2] = light0_pos[2];
        amgr->light0_pos[3] = light0_pos[3];
/* end PM */
    }


    return;
}



/*
 * Subroutine: Application's frame callback function
 * Identified to CAVE libraries thru CAVEFrameFunction()
 * Called once per frame.
 */

/* 23Jan08  Phil McDonald */
void cave5d_render_frame (void *vrlib_data)
{
/* 01Sep06  Phil McDonald	time-stepping code moved to the simulation's */
/*				event loop.                                  */
/* end PM */

    if (amgr->status == CAVE5D_STATUS_QUIT) return;

    cave5d_render_sync (amgr, CAVE5D_STATUS_FRAME);


    return;
}
/* end PM */



/*
 * Subroutine: Application's display callback function 
 * Identified to CAVE libraries thru CAVEDisplay()
 * In stereo, called twice per frame: In mono, called once per frame.
 */

/* 13Jul07  Phil McDonald */
void cave5d_render_display (void *vrlib_data)
{
    float	red, grn, blu, alf;



    if (amgr->status == CAVE5D_STATUS_QUIT) return;


    vis5d_get_color (amgr->dx, VIS5D_BACKGROUND, 0, &red, &grn, &blu, &alf);
    glClearColor (red, grn, blu, alf);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/* 22Jan08  Phil McDonald */
    glLightfv (GL_LIGHT0, GL_POSITION, amgr->light0_pos);
/* end PM */

    if (amgr->clock) draw_clock (1, 1, 1, amgr);
    cave5d_render_lightsaber (amgr);
    pmgr_renderUI (amgr->panel);

    vrlib_nav_transform (vrlib_data);

    vis5d_signal_redraw (amgr->dx, 1);
    vis5d_draw_3d_only (amgr->dx, amgr->animFlag);
    cave5d_render_c5d (amgr);

    glFinish ();

    usleep (1000); /* take a little nap and let the sim do some work */


    return;
}
/* end PM */



/* 11Jul07  Phil McDonald */
static void cave5d_nav_set (float x_cen, float y_cen, float z_cen)
{
    vrlib_nav_lock ();

    if (amgr->scaleMode > 0)
    {
        vrlib_nav_translate (-x_cen, -y_cen, -z_cen);
        vrlib_nav_scale     (&amgr->xyz_tmp[0],
                             &amgr->xyz_tmp[1],
                             &amgr->xyz_tmp[2], (amgr->scaleMode-1));
        vrlib_nav_translate ( x_cen,  y_cen,  z_cen);

        amgr->xyz_fac[0] *= amgr->xyz_tmp[0];
        amgr->xyz_fac[1] *= amgr->xyz_tmp[1];
        amgr->xyz_fac[2] *= amgr->xyz_tmp[2];
    }
    else
    {
        vrlib_nav_translate (-x_cen, -y_cen, -z_cen);
        vrlib_nav_rotate    (-amgr->xyz_rot[0],
                             -amgr->xyz_rot[1],
                             -amgr->xyz_rot[2]);
        vrlib_nav_translate ( x_cen,  y_cen,  z_cen);

        vrlib_nav_translate (-amgr->xyz_off[0],
                             -amgr->xyz_off[1],
                             -amgr->xyz_off[2]);

        amgr->xyz_pos[0] -= amgr->xyz_off[0];
        amgr->xyz_pos[1] -= amgr->xyz_off[1];
        amgr->xyz_pos[2] -= amgr->xyz_off[2];
    }

    vrlib_nav_unlock ();


    amgr->xyz_rot[0] = amgr->xyz_rot[1] = amgr->xyz_rot[2] = 0.0;
    amgr->xyz_off[0] = amgr->xyz_off[1] = amgr->xyz_off[2] = 0.0;


    return;
}
/* end PM */



/*
 * Subroutine: initialize cave view
 */

/* 11Jul07  Phil McDonald */
static void cave5d_nav_init (APP_MGR *amgr)
{

    int         scale_mode;



    cave5d_render_sync (amgr, CAVE5D_STATUS_PAUSE);

    vrlib_nav_reset ();

    amgr->xyz_pos[0] = 0.0;
    amgr->xyz_pos[1] = 0.0;
    amgr->xyz_pos[2] = 0.0;
    amgr->xyz_off[0] = amgr->xyz_pos0[0];
    amgr->xyz_off[1] = amgr->xyz_pos0[1];
    amgr->xyz_off[2] = amgr->xyz_pos0[2];
    amgr->xyz_rot[0] = amgr->xyz_rot0[0];
    amgr->xyz_rot[1] = amgr->xyz_rot0[1];
    amgr->xyz_rot[2] = amgr->xyz_rot0[2];
    amgr->xyz_fac[0] = 1.0;
    amgr->xyz_fac[1] = 1.0;
    amgr->xyz_fac[2] = 1.0;

    scale_mode      = amgr->scaleMode;
    amgr->scaleMode = 0;

    cave5d_nav_set (amgr->xyz_pos[0], amgr->xyz_pos[1], amgr->xyz_pos[2]);

    if ((amgr->xyz_fac0[0] != 1.0) ||
        (amgr->xyz_fac0[1] != 1.0) ||
        (amgr->xyz_fac0[2] != 1.0))
    {
/* 08Aug07  Phil McDonald	TODO: this isn't quite right for FreeVR */
        amgr->scaleMode  = 1;
        amgr->xyz_tmp[0] = amgr->xyz_fac0[0];
        amgr->xyz_tmp[1] = amgr->xyz_fac0[1];
        amgr->xyz_tmp[2] = amgr->xyz_fac0[2];
        cave5d_nav_set (amgr->xyz_pos[0], amgr->xyz_pos[1], amgr->xyz_pos[2]);
    }

    amgr->scaleMode = scale_mode;

    cave5d_render_sync (amgr, CAVE5D_STATUS_RESUME);


    return;
}
/* end PM */



/* 05Aug07  Phil McDonald	Initialize Vis5D.  This is a minimal       */
/*				initialization without data.  Data         */
/*				contexts will be allocated and initialized */
/*				when their data files are loaded as the    */
/*				Tcl/Tk configuration file is processed.    */

static void cave5d_init_vis5d (APP_MGR *amgr)
{

    /* Set up shared memory management functions and mutex data locks */
    vrlib_shmem_set_funcs ();
    cave5d_mutex_init ();

    /* Start the initialization */
    vis5d_initialize (1);

    /* TODO: get the number of workers from the config file */
/*
    vis5d_workers (nworkers);
*/

    /* Allocate the display context.  Data contexts will be allocated */
    /* as the data files are loaded.                                  */
    amgr->dx = vis5d_alloc_display_context ();
    amgr->cc = -1;

    /* Actually initialize some display context values */
    vis5d_init_begin (amgr->cc, amgr->dx);

    /* Initialize a default set of display context options */
    vis5d_alpha_mode (amgr->dx, 1);
    vis5d_set_color (amgr->dx, VIS5D_BOX, 0, 1.0, 0.0, 1.0, 1.0);
    vis5d_graphics_mode (amgr->dx, VIS5D_BOX, VIS5D_ON);
    vis5d_graphics_mode (amgr->dx, VIS5D_DEPTHCUE, VIS5D_OFF);
    vis5d_graphics_mode (amgr->dx, VIS5D_PERSPECTIVE, VIS5D_OFF);
    vis5d_graphics_mode (amgr->dx, VIS5D_CONTOUR_NUMBERS, VIS5D_ON);


    return;
}
/* end PM */



/* 24Jan08  Phil McDonald */
static int cave5d_time_step (APP_MGR *amgr)
{
    int         new_step;



    new_step = amgr->curtime;

    if (amgr->animFlag)
    {
        int         now_usec, usec_per_step;

        now_usec = cave5d_time_usec ();

        /* Check for clock "roll-over" */
        if (abs (amgr->anim_step_usec - now_usec) > 500000000)
        {
            if (now_usec < amgr->anim_step_usec)
            {
                now_usec += 1000000000;
            }
            else if (amgr->anim_step_usec != 0)
            {
                amgr->anim_step_usec += 1000000000;
            }
        }
           
        if (now_usec < amgr->anim_step_usec) return -1;

        usec_per_step = (int) (1000000.0 / amgr->anim_rate_fps);
        if (amgr->anim_step_usec == 0)
        {
            amgr->anim_step_usec = now_usec + usec_per_step;
        }
        else
        {
            amgr->anim_step_usec += usec_per_step;
            amgr->anim_step_usec = now_usec + usec_per_step;
            new_step++;
        }
        amgr->anim_step_usec %= 1000000000;
    }
    else
    {
        amgr->anim_step_usec = 0;
        if (amgr->step_fwd)
        {
            amgr->step_fwd = 0;
            new_step++;
        }
    }

    if (new_step == amgr->curtime) return -1;

    if (new_step >= amgr->numtimes)
    {
        new_step = 0;
    }
    else if (new_step < 0) /* this for reverse, whenever that gets added */
    {
        new_step = amgr->numtimes - 1;
    }


    return new_step;
}
/* end PM */



/*
 * Subroutine: Event handling loop
 */

#define POS_FUZZ		0.010
#define ROT_FUZZ		0.100

static void cave5d_event_loop (APP_MGR *amgr)
{

    float       wand_pos[3] = { 0.0, 0.0, 0.0 };
    float       wand_vec[3] = { 0.0, 0.0, 0.0 };
    float       wand_old[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    float       wand_dir[3] = { 0.0, 0.0, 0.0 };
    float       dxpos, dypos, dzpos, dxrot, dyrot, dzrot;
    float       time_cur = 0.0, time_prv = 0.0, time_del = 0.0;
    float       jStick = 0.0;
    int         bState = 0, b2Flag = 0, b3Flag = 0;
    int         new_step = -1;
    int         work_pending;

    while (!vrlib_button_state (-1))
    {
        vrlib_wand_posvec (wand_pos, wand_vec, 0);

        time_cur = vrlib_get_time ();
        time_del = (time_cur - time_prv) * amgr->navSpeed * 10.0;
        time_prv = time_cur;

        /* Interact with panel */
        if (vrlib_button_change (1) == 1)
        {
            bState = pmgr_queryUI (amgr, wand_pos, wand_vec);
            fprintf (stderr, "ui_event -- state = %d   amgr = %p\n",
                     bState, amgr);
            if (bState == -1) return; /* quit */
        }

        /* NAVIGATE OR SCALE BY JOYSTICK */
        jStick = vrlib_joystick_dist (1);
        cave5d_diff_scale (&jStick, 1.0, 0);
        if (fabs (jStick) > amgr->jstickThresh)
        {
            jStick *= time_del;
            if (amgr->nav_style == CAVE5D_OBJECT_NAV) jStick = -jStick;

            if (amgr->scaleMode == 0)
            {
                amgr->xyz_off[0] = -jStick * wand_vec[0] /
                                   sqrt (amgr->xyz_fac[0]);
                amgr->xyz_off[1] = -jStick * wand_vec[1] /
                                   sqrt (amgr->xyz_fac[1]);
                amgr->xyz_off[2] = -jStick * wand_vec[2] /
                                   sqrt (amgr->xyz_fac[2]);
            }
            else
            {
                int         i = amgr->scaleMode - 1;

                amgr->xyz_tmp[0]  = amgr->xyz_tmp[1] = amgr->xyz_tmp[2] = 1.0;
                amgr->xyz_tmp[i] -= (jStick / amgr->xyz_fac[i]);
            }

            cave5d_nav_set (amgr->xyz_pos[0],
                            amgr->xyz_pos[1],
                            amgr->xyz_pos[2]);
        }

        /* CHECK BUTTON 2 FOR ROTATION/TRANSLATION */
        if (!vrlib_button_state (2))
        {
            b2Flag = 0;
        }
        else
        {
            vrlib_wand_orient (wand_dir, 0);
            if (b2Flag == 0)
            {
                /* Initial BUTTON 2 press */

/* 06Jul07  Phil McDonald */
                if (amgr->nav_style == CAVE5D_AIRPLANE_NAV)
                {
                    wand_old[0] = wand_pos[0];
                    wand_old[1] = wand_pos[1];
                    wand_old[2] = wand_pos[2];
                    wand_old[3] = wand_dir[0];
                    wand_old[4] = wand_dir[1];
                    wand_old[5] = wand_dir[2];
                }
/* end PM */
            }
            else if (amgr->scaleMode == 0)
            {
                dxpos = wand_pos[0] - wand_old[0];
                dypos = wand_pos[1] - wand_old[1];
                dzpos = wand_pos[2] - wand_old[2];
                dxrot = wand_dir[0] - wand_old[3];
                dyrot = wand_dir[1] - wand_old[4];
                dzrot = wand_dir[2] - wand_old[5];

                if ((fabs (dxpos) > POS_FUZZ) || (fabs (dxrot) > ROT_FUZZ) ||
                    (fabs (dypos) > POS_FUZZ) || (fabs (dyrot) > ROT_FUZZ) ||
                    (fabs (dzpos) > POS_FUZZ) || (fabs (dzrot) > ROT_FUZZ))
                {

                    if (amgr->nav_style == CAVE5D_AIRPLANE_NAV)
                    {
                        time_del *= 0.5;

                        amgr->xyz_off[0] = -dxpos * time_del;
                        amgr->xyz_off[1] = -dypos * time_del;
                        amgr->xyz_off[2] = -dzpos * time_del;

                        cave5d_diff_scale (&dxrot, 360.0, 0);
                        cave5d_diff_scale (&dyrot, 360.0, 0);
                        cave5d_diff_scale (&dzrot, 360.0, 0);
                        amgr->xyz_rot[0] = -dxrot * time_del;
                        amgr->xyz_rot[1] = -dyrot * time_del;
                        amgr->xyz_rot[2] = -dzrot * time_del;

                        vrlib_head_pos (amgr->xyz_tmp, 0);

                        cave5d_nav_set (-amgr->xyz_tmp[0],
                                        -amgr->xyz_tmp[1],
                                        -amgr->xyz_tmp[2]);
                    }
                    else
                    {
                        amgr->xyz_off[0] = dxpos / sqrt (amgr->xyz_fac[0]);
                        amgr->xyz_off[1] = dypos / sqrt (amgr->xyz_fac[1]);
                        amgr->xyz_off[2] = dzpos / sqrt (amgr->xyz_fac[2]);

                        amgr->xyz_rot[0] = dxrot;
                        amgr->xyz_rot[1] = dyrot;
                        amgr->xyz_rot[2] = dzrot;

                        cave5d_nav_set (amgr->xyz_pos[0],
                                        amgr->xyz_pos[1],
                                        amgr->xyz_pos[2]);
                    }
                }
            }
/* 06Jul07  Phil McDonald */
            if (amgr->nav_style != CAVE5D_AIRPLANE_NAV)
            {
                wand_old[0] = wand_pos[0];
                wand_old[1] = wand_pos[1];
                wand_old[2] = wand_pos[2];
                wand_old[3] = wand_dir[0];
                wand_old[4] = wand_dir[1];
                wand_old[5] = wand_dir[2];
            }
/* end PM */
            b2Flag = 1;
        }

        /* RETURN TO ORIGINAL POS/ROT/SCALE */
        if (vrlib_button_state (1) && vrlib_button_state (3))
        {
            cave5d_nav_init (amgr);
        }

        /* BUTTON3 in SLICE MODE */
/* 05Mar07  Phil McDonald */
        if (!vrlib_button_state (3))
        {
            b3Flag = 0;
        }
        else
        {
            static float old_pos[3];

            vrlib_wand_posvec (wand_pos, wand_vec, 1);
            if (b3Flag > 0)
            {
                dxpos = (wand_pos[0] - old_pos[0]) / amgr->xyz_fac[0];
                dypos = (wand_pos[1] - old_pos[1]) / amgr->xyz_fac[1];
                dzpos = (wand_pos[2] - old_pos[2]) / amgr->xyz_fac[2];
                if ((dxpos != 0.0) || (dypos != 0.0) || (dzpos != 0.0))
                {
                    gobj_move (amgr, dxpos, dypos, dzpos);
                }
            }
            old_pos[0] = wand_pos[0];
            old_pos[1] = wand_pos[1];
            old_pos[2] = wand_pos[2];
            b3Flag = 1;
        }

/* 22Feb08  Phil McDonald */
        if (new_step < 0)
        {
            new_step = cave5d_time_step (amgr);

            if (new_step >= 0)
            {
                /* Since the new time step isn't visible yet, */
                /* we can make the graphics now and pause the */
                /* renderers only while we advance to the new */
                /* time step.                                 */

                vis5d_make_timestep_graphics (amgr->dx, new_step);
            }
            else if (amgr->redraw)
            {
                /* Since the current time step is already visible, */
                /* the renderers must be paused while we make the  */
                /* new graphics.                                   */

/*
                cave5d_render_sync (amgr, CAVE5D_STATUS_PAUSE);
*/

                vis5d_make_timestep_graphics (amgr->dx, amgr->curtime);
/*
                vis5d_finish_work ();
*/

/*
                cave5d_render_sync (amgr, CAVE5D_STATUS_RESUME);
*/

                amgr->redraw = 0;
            }
        }

        vis5d_do_work ();
        vis5d_check_work (&work_pending);

        if (!work_pending)
        {
            if (new_step >= 0)
            {
                cave5d_render_sync (amgr, CAVE5D_STATUS_PAUSE);

                amgr->curtime = new_step;
                vis5d_set_dtx_timestep (amgr->dx, amgr->curtime);

                cave5d_render_sync (amgr, CAVE5D_STATUS_RESUME);

                new_step = -1;
            }
        }
/* end PM */

	vrFrame ();
    }     /*** end of WHILE loop */
}



/* 05Aug07  Phil McDonald */
int main (int argc, char *argv[])
{
/* 10Sep07  Phil McDonald */
    size_t      nbytes;
    int         iarg, megabytes;
    char        *file_name, *p_chr;
/* end PM */
    int         time_now, time_stop;



    if (argc < 2)
    {
        fprintf (stderr, "Usage:\ncave5d [-mbs MB] config_file\n");
        exit (EXIT_FAILURE);
    }

/* 10Sep07  Phil McDonald */
    /* Parse the command line arguments */
    file_name = NULL;
    megabytes = 512;

    for (iarg = 1; iarg < argc; iarg++)
    {
        if (strcmp (argv[iarg], "-mbs") == 0)
        {
            if (++iarg < argc)
            {
                float       xmeg;

                if (sscanf (argv[iarg], "%f", &xmeg) == 1)
                {
                    p_chr = argv[iarg];
                    while (*(++p_chr) != '\0')
                    {
                        if ((*p_chr == 'G') || (*p_chr == 'g'))
                        {
                            xmeg *= 1024.0;
                            break;
                        }
                    }
                    megabytes = xmeg + 0.5;
                }
                else
                {
                    iarg--;
                    fprintf (stderr, "CAVE5D: ERROR: %s %s %s.  %s.\n",
                             "no value for", argv[iarg], "option", "Ignoring");
                }
            }
        }
        else
        {
            file_name = argv[iarg];
        }
    }
    if (file_name == NULL)
    {
        fprintf (stderr, "CAVE5D: ERROR: no configuration file.\n");
        exit (EXIT_FAILURE);
    }


    nbytes = ((size_t) megabytes) * CAVE5D_MEGABYTES;
    fprintf (stderr, "CAVE5D: attempting to allocate %ld bytes %s.\n", nbytes,
            "from shared memory");
    vrlib_shmem_init (nbytes);
/* end PM */

    fprintf (stderr, "CAVE5D: attempting to allocate %d bytes %s.\n",
             sizeof (APP_MGR), "from shared memory for data structure");
    amgr = vrlib_shmem_alloc (sizeof (APP_MGR));

    memset (amgr, 0, sizeof (APP_MGR));


/* 09Nov06  Phil McDonald	create a GL context for the simulation so  */
/*				that it can use GL functions, if necessary */
/*				(e.    g. texture image scaling).          */
    cave5d_render_init_GL (1);
/* end PM */


    /* Initialize Vis5D without data */
    cave5d_init_vis5d (amgr);

    /* Process the Tcl/Tk configuration file */
    process_config (amgr, file_name);

/* 07Aug07  Phil McDonald */
    vis5d_get_sizePRIME (amgr->dx,
                         &amgr->rowCnt, &amgr->colCnt, &amgr->lvlCnt,
                         NULL, NULL, NULL);
    vis5d_get_dtx_numtimes (amgr->dx, &amgr->numtimes);
    if ((amgr->rowCnt <= 0  ) ||
        (amgr->colCnt <= 0  ) ||
        (amgr->lvlCnt <= 0  ) ||
        (amgr->numtimes <= 0))
    {
        fprintf (stderr, "CAVE5D:  data lacks dimensionality (%d %d %d %d)\n",
                 amgr->rowCnt, amgr->colCnt, amgr->lvlCnt, amgr->numtimes);
        exit (EXIT_FAILURE);
    }

#ifdef CPP
/* 11Jul07  Phil McDonald	TODO:  This used to alloc memory for the */
/*				c5d objects, but I don't know if it's    */
/*				necessary since I couldn't find that the */
/*				memory allocated was actually used       */
/*				anywhere.                                */

    if (amgr->tmp->needC5D)
    {
        c5d_share_mem = ????;
    }
/* end PM */
#endif

/* Create the user interface */
    pmgr_initUI (amgr);
    if (amgr->tmp->mode != OFF) init_clock (amgr);

/* Free the temporary paramters structure */
/* TODO: see if amgr->tmp can be done away with */
    vrlib_shmem_free (amgr->tmp);

/* Start the VR library */
    vrlib_init ();

/* Set the initial view.  This needs to be done _after_ the VR lib is inited */
    cave5d_nav_init (amgr);


    amgr->redraw = 0;
    amgr->status = CAVE5D_STATUS_OK;


/* Enter the interactive mode */
    fprintf (stderr, "CAVE5D: event loop: begin\n");
    cave5d_event_loop (amgr);
    fprintf (stderr, "CAVE5D: event loop: done\n");


/* Terminate Cave5D */

    amgr->status = CAVE5D_STATUS_QUIT;
    usleep (100000); /* wait a little while renderers finish */

    /* Terminate Vis5D */
    fprintf (stderr, "Terminating Vis5D\n");
    vis5d_terminate (1);
    fprintf (stderr, "!!!! Vis5D terminated\n");

    /* Terminate the VR lib */
    fprintf (stderr, "Terminating VR lib\n");
    vrlib_exit ();
    fprintf (stderr, "!!!! VR lib terminated\n");

    /* All done!! */
    fprintf (stderr, "\n!!!! Cave5D terminated gracefully !!!!\n");
}
/* end PM */
