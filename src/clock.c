/*******************************************************************************
 * Name: clock.c    Config_No: 1.3    Date: 08/01/01
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
 * Compilation Unit: clock.c
 *
 * l_plot_string
 * init_clock
 * draw_clock
 */

/* utility */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <math.h>
/* end PM */

/* vis5d support */
#include "api.h"
#include "v5d.h"

/* application specific */
#include "cave5d.h"

/*
 * Subroutine: plot string for clock
 */

static void l_plot_string (char *str, float startx, float starty, float startz,
                           float base[], float up[])
{
    static float zero[] = { 0, 0, 0, .8, .4, .8, .4, 0, 0, 0 };
    static float one[] = { 0, 0, 0, .8 };
    static float two[] = { .4, 0, 0, 0, 0, .4, .4, .4, .4, .8, 0, .8 };
    static float three[] =
        { 0, 0, .4, 0, .4, .4, 0, .4, .4, .4, .4, .8, 0, .8 };
    static float four[] = { 0, .8, 0, .4, .4, .4, .4, .8, .4, 0 };
    static float five[] = { 0, 0, .4, 0, .4, .4, 0, .4, 0, .8, .4, .8 };
    static float six[] = { .4, .8, 0, .8, 0, 0, .4, 0, .4, .4, 0, .4 };
    static float seven[] = { 0, .7, 0, .8, .4, .8, .4, 0 };
    static float eight[] = { 0, 0, 0, .8, .4, .8, .4, 0, 0, 0, 0, .4, .4, .4 };
    static float nine[] = { .4, .4, 0, .4, 0, .8, .4, .8, .4, 0 };
    static float dash[] = { 0, .4, .4, .4 };
    static float dot[] = { 0, 0, 0, .1, .1, .1, .1, 0, 0, 0 };
    static float colon[] =
        { 0, .1, 0, .2, .1, .2, .1, .1, 0, .7, 0, .6, .1, .6, .1, .7 };

    static float *index[13] = { zero, one, two, three, four, five, six,
        seven, eight, nine, dash, dot, colon
    };

    static float width[13] = { 0.6, 0.2, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6,
        0.6, 0.6, 0.6, 0.3, 0.3
    };
    static int  num_verts[13] = { 5, 2, 6, 7, 5, 6, 6, 4, 7, 5, 2, 5, 8 };

    float      *temp;
    float       cx, cy, cz;
    int         i, j, k, ler, len;
    float       plot[20][3];
    const float ccx = startx + 0.8, ccy = starty + 0.2, ccz = startz;
    float       boxVert[12] =
        { (ccx - 1.0), (ccy + 0.5), (ccz - 0.01), (ccx - 1.0), (ccy - 0.5),
        (ccz - 0.01), (ccx + 1.5), (ccy - 0.5), (ccz - 0.01),
        (ccx + 1.5), (ccy + 0.5), (ccz - 0.01)
    };



    cx = startx;
    cy = starty;
    cz = startz;
    len = strlen (str);
    /* draw left justified text */
    for (i = 0; i < len; i++)
    {
        if (str[i] == '-')
            k = 10;
        else if (str[i] == '.')
            k = 11;
        else if (str[i] == ':')
            k = 12;
        else if (str[i] >= '0' && str[i] <= '9')
            k = str[i] - '0';
        else
            continue;
        /* make the vertex array for this character */
        temp = index[k];
        for (j = 0; j < num_verts[k]; j++)
        {
            float       x, y;

            x = *temp++;
            y = *temp++;
            plot[j][0] = cx + x * base[0] + y * up[0];
            plot[j][1] = cy + x * base[1] + y * up[1];
            plot[j][2] = cz + x * base[2] + y * up[2];
        }

        /*Added by SAM draw background box to see clock better */
        glBegin (GL_POLYGON);
/* 02Apr07  Phil McDonald */
/*
    	glColor3f(0.0, 0.0, 0.0);
*/
        {
            float       red, grn, blu, alf;

/* 02Apr07  Phil McDonald	TODO: change 0 to amgr->dx */
            vis5d_get_color (0, VIS5D_BACKGROUND, 0, &red, &grn, &blu, &alf);
/* end PM */
            glColor3f (red, grn, blu);
        }
/* end PM */
        glVertex3f (boxVert[0], boxVert[1], boxVert[2]);
        glVertex3f (boxVert[3], boxVert[4], boxVert[5]);
        glVertex3f (boxVert[6], boxVert[7], boxVert[8]);
        glVertex3f (boxVert[9], boxVert[10], boxVert[11]);
        glEnd ();

        glLineWidth (4.0);
        glColor3f (1.0, 1.0, 1.0);

        /*draw the char */
        if (k < 12)
        {
            glBegin (GL_LINE_STRIP);
            for (ler = 0; ler < num_verts[k]; ler++)
                glVertex3fv (plot[ler]);
            glEnd ();
        }
        else
        {                       /* we have a colon which takes two line strips */
            glBegin (GL_LINE_LOOP);
            for (ler = 0; ler < 4; ler++)
                glVertex3fv (plot[ler]);        /*HARD CODED */
            glEnd ();
            glBegin (GL_LINE_LOOP);
            for (ler = 4; ler < 8; ler++)
                glVertex3fv (plot[ler]);        /*HARD CODED */
            glEnd ();
        }
        /* calculate position for next char */
        cx += width[k] * base[0];
        cy += width[k] * base[1];
        cz += width[k] * base[2];
    }


}





void init_clock (APP_MGR * amgr)
{
    int         i;
    CLOCK      *clock;
    const float SCALE_FACTOR = .26;     /*It works...don't argue with success */

    /*the true scale factor is .26666666~ but whatever works */

    clock       = (CLOCK *) vrlib_shmem_alloc (sizeof (CLOCK));
    clock->lock = vrlib_lock_create ();
    clock->mode = amgr->tmp->mode;
/* 29Jun07  Phil McDonald */
    if (clock->mode == VIS5D  ) printf ("Vis5D clock \n");
    if (clock->mode == DECIMAL) printf ("Decimal clock\n");
    fflush (stdout);
/* end PM */
    for (i = 0; i < 3; i++)
    {
        clock->base[i] = 0;
        clock->up[i]   = 0;
    }
    clock->base[0]    = (amgr->tmp->bottom_right[0] - amgr->tmp->top_left[0]) *
                        SCALE_FACTOR;
    clock->up[1]      = clock->base[0];
    clock->clockScale = amgr->tmp->clockScale;

/*test for clock plane is parrallel to cave wall */

    if (amgr->tmp->top_left[2] != amgr->tmp->bottom_right[2])
    {
/* 29Jun07  Phil McDonald */
        printf ("ERROR: %s.  Clock will be disabled.\n",
                "Clock plane not parallel to CAVE wall");
        fflush (stdout);
/* end PM */
        amgr->clock = NULL;
        return;
    }

/*load up the stamps*/
    clock->datestamp = (int *) vrlib_shmem_alloc (sizeof (int) *
                                                  amgr->numtimes);
    clock->timestamp = (int *) vrlib_shmem_alloc (sizeof (int) *
                                                  amgr->numtimes);
    for (i = 0; i < amgr->numtimes; i++)
    {
        /*Changed by SAM use to be vis5d_get_time_stamp  */
        if (vis5d_get_dtx_time_stamp
            (amgr->dx, i, clock->datestamp + i, clock->timestamp + i) < 0)
        {
/* 29Jun07  Phil McDonald */
            printf ("ERROR: %s.  Clock will be disabled.\n",
                    "Couldn't get date/time stamp from .v5d file");
            fflush (stdout);
/* end PM */
            vrlib_shmem_free (clock->datestamp);
            vrlib_shmem_free (clock->timestamp);
            clock = NULL;
            return;
        }
    }
/*end load of stamps*/


    clock->verts = (float **) vrlib_shmem_alloc (sizeof (float *) *
                                                 amgr->numtimes);
    for (i = 0; i < amgr->numtimes; i++)
        *(clock->verts + i) = (float *) vrlib_shmem_alloc (sizeof (float) * 3);

    clock->xcenter =
        (amgr->tmp->bottom_right[0] - amgr->tmp->top_left[0]) / 2 +
        amgr->tmp->top_left[0];
    clock->ycenter =
        (amgr->tmp->top_left[1] - amgr->tmp->bottom_right[1]) / 2 +
        amgr->tmp->bottom_right[1];
    clock->zcenter = amgr->tmp->top_left[2];

    clock->step[0] = amgr->tmp->top_left[0] - 0.3;
    clock->step[1] = amgr->tmp->bottom_right[1] - clock->up[1];
    clock->stamp[0] = amgr->tmp->bottom_right[0];
    clock->stamp[1] = amgr->tmp->top_left[1] - clock->up[1];
    clock->date[0] = amgr->tmp->bottom_right[0];
    clock->date[1] = amgr->tmp->bottom_right[1] + .3;






/*zcenter must be modified in the config file see config.c for code*/


/*fill up the vertexes */

    for (i = 0; i < amgr->numtimes; i++)
    {
        const float two_pi = 6.2831853;
        float       angle, radius;

        if (amgr->numtimes == 0)
            angle = 0.0;
        else
        {
            float       number;

            number = i;
            angle = number / amgr->numtimes;
            radius = (amgr->tmp->bottom_right[0] - amgr->tmp->top_left[0]) / 2;
            clock->verts[i][0] = clock->xcenter + radius * sin (two_pi * angle);
            clock->verts[i][1] = clock->ycenter + radius * cos (two_pi * angle);
            clock->verts[i][2] = clock->zcenter;
        }
    }
/*end building of the sweep hand*/




    amgr->clock = clock;
}                               /*end clock_init */

void draw_clock (float R, float G, float B, APP_MGR * amgr)
{

    char       *str;
    const int   STAMP_SIZE = 12;
    int         i;

    glColor3f (R, G, B);

/* Time step*/

    vrlib_lock_on (amgr->clock->lock);
    str = (char *) vrlib_shmem_alloc (sizeof (char) * STAMP_SIZE);
    sprintf (str, "%d-%d  ", amgr->curtime, (amgr->numtimes - 1));
    l_plot_string (str, amgr->clock->step[0], amgr->clock->step[1],
                   amgr->clock->zcenter, amgr->clock->base, amgr->clock->up);
/* I stole this code from Vis5d render.c */

    if (amgr->clock->mode == VIS5D)
    {                           /*Vis5D Mode */
        {                       /*start date block */
            int         iy, im, id, days, mon;
            int         dds[24] =
                { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365,
                31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
            };

            days = amgr->clock->datestamp[amgr->curtime];
            iy = (4 * days) / 1461;
            id = days - (365 * iy + (iy - 1) / 4);
            im = (iy % 4) == 0 ? 12 : 0;
            for (i = im; i < im + 12; i++)
            {
                if (id <= dds[i])
                {
                    mon = i - im;
                    if (mon > 0)
                        id = id - dds[i - 1];
                    mon = ++mon;        /*Added by SAM to get correct month to display */
                    break;
                }
            }
            sprintf (str, "%02d-%02d-%02d", mon, id, iy);
            l_plot_string (str, amgr->clock->date[0], amgr->clock->date[1],
                           amgr->clock->zcenter, amgr->clock->base,
                           amgr->clock->up);
        }                       /*end date block */
        {                       /*time block */
            i = amgr->clock->timestamp[amgr->curtime];
            sprintf (str, "%02d%s%02d%s%02d", i / 3600, ":", (i / 60) % 60, ".",
                     i % 60);
            l_plot_string (str, amgr->clock->stamp[0], amgr->clock->stamp[1],
                           amgr->clock->zcenter, amgr->clock->base,
                           amgr->clock->up);
        }                       /*end time block */

    }                           /*end Vis5D clock mode */





/*sweep hand has precalculated vertices*/
    glBegin (GL_LINES);
    glColor3f (0.0, 1.0, 0.0);  /*Changed by SAM changed the color of the clock */
    glVertex3f (amgr->clock->xcenter, amgr->clock->ycenter,
                amgr->clock->zcenter);
    glVertex3fv (amgr->clock->verts[amgr->curtime]);
    glEnd ();
    vrlib_lock_off (amgr->clock->lock);
}
