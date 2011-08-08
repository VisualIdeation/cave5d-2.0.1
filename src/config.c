/*******************************************************************************
 * Name: config.c    Config_No: 1.18    Date: 0801/01 
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
 * Compilation Unit: config.c
 *
 * process_config
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "api.h"
#include "cave5d.h"
/* 07Aug07  Phil McDonald */
#include <string.h>
/* 30Oct06  Phil McDonald */
#ifdef CPP
#  include "c5d_vector.h"
#  include "c5d_bar_graph.h"
#  include "c5d_surface.h"
#endif
/* end PM */



/* 05Aug07  Phil McDonald	Tcl/Tk interpreter capability */

#include <tcl.h>



/* 17Aug07  Phil McDonald */
static int interp_check_argc (int argc, char *argv[], int min_arg, int max_arg)
{
    argc--;

    if (argc < min_arg)
    {
        fprintf (stderr, "CAVE5D: config: ERROR: %s %s.\n",
                 "too few arguments for", argv[0]);
        return 0;
    }

    if ((max_arg >= 0) && (argc > max_arg))
    {
        fprintf (stderr, "CAVE5D: config: ERROR: %s %s.\n",
                 "too many arguments for", argv[0]);
        return 0;
    }


    return 1;
}



static int interp_bad_command (int argc, char *argv[])
{
    int         i;



    fprintf (stderr, "CAVE5D: config: ERROR: bad command:");
    for (i =0; i < argc; i++) fprintf (stderr, " %s", argv[i]);
    fprintf (stderr, ".\n");


    return TCL_ERROR;
}
/* end PM */



/* 07Aug07  Phil McDonald */
static int interp_parm_set (APP_MGR *amgr, Tcl_Interp *interp,
                            int argc, char *argv[])
{
    char        *keyword;
    TPARAMS     *tmp_data;



    if (!interp_check_argc (argc, argv, 2, -1)) return TCL_ERROR;

    tmp_data = amgr->tmp;
    keyword  = argv[1];
    if (strcmp (keyword, "MASTER_PANEL_CONFIG") == 0)
    {
        strcpy (tmp_data->config_main, argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "GOBJ_PANEL_CONFIG") == 0)
    {
        strcpy (tmp_data->config_gobj, argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "PARMS_PANEL_CONFIG") == 0)
    {
        strcpy (tmp_data->config_parms, argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "CHANGE_PANEL_CONFIG") == 0)
    {
        strcpy (tmp_data->config_entry, argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "MAIN_HELP_CONFIG") == 0)
    {
        strcpy (tmp_data->config_help, argv[2]);
        return TCL_OK;
    }

/* 30Nov07  Phil McDonald */
    else if (strcmp (keyword, "MAIN_PANEL_CONFIG") == 0)
    {
        strcpy (tmp_data->config_main, argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "HELP_PANEL_CONFIG") == 0)
    {
        strcpy (tmp_data->config_help, argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "ENTRY_PANEL_CONFIG") == 0)
    {
        strcpy (tmp_data->config_entry, argv[2]);
        return TCL_OK;
    }

/* end PM */

    else if (strcmp (keyword, "ALL_PANELS_CONFIG") == 0)
    {
        strcpy (tmp_data->config_main, argv[2]);
        strcpy (tmp_data->config_gobj, argv[2]);
        strcpy (tmp_data->config_parms, argv[2]);
        strcpy (tmp_data->config_entry, argv[2]);
        strcpy (tmp_data->config_help, argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "C5D_MEMSIZE") == 0)
    {
        tmp_data->c5d_mem_size = atoi (argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "LIGHT0_POSITION") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        tmp_data->position_0[0] = atof(argv[2]);
        tmp_data->position_0[1] = atof(argv[3]);
        tmp_data->position_0[2] = atof(argv[4]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "LIGHT0_AMBIENT") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        tmp_data->ambient_0[0] = atof (argv[2]);
        tmp_data->ambient_0[1] = atof (argv[3]);
        tmp_data->ambient_0[2] = atof (argv[4]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "LIGHT0_DIFFUSE") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        tmp_data->diffuse_0[0] = atof (argv[2]);
        tmp_data->diffuse_0[1] = atof (argv[3]);
        tmp_data->diffuse_0[2] = atof (argv[4]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "LIGHT0_SPECULAR") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        tmp_data->specular_0[0] = atof (argv[2]);
        tmp_data->specular_0[1] = atof (argv[3]);
        tmp_data->specular_0[2] = atof (argv[4]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "LIGHT_AMBIENT") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        tmp_data->ambient_0[0] = atof (argv[2]);
        tmp_data->ambient_0[1] = atof (argv[3]);
        tmp_data->ambient_0[2] = atof (argv[4]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "BOX_DISPLAY") == 0)
    {
        tmp_data->box_flag = 1;
        if (strcmp (argv[2], "OFF") == 0) tmp_data->box_flag = 0;
        return TCL_OK;
    }

    else if (strcmp (keyword, "NAV_SPEED") == 0)
    {
        amgr->navSpeed = atof (argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "ROTATION_STYLE") == 0)
    {
        amgr->nav_style = CAVE5D_OBJECT_NAV;
        if (strcmp (argv[2], "AIRPLANE") == 0)
            amgr->nav_style = CAVE5D_AIRPLANE_NAV;
        return TCL_OK;
    }

    else if (strcmp (keyword, "INIT_POSITION") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        amgr->xyz_pos0[0] = atof (argv[2]);
        amgr->xyz_pos0[1] = atof (argv[3]);
        amgr->xyz_pos0[2] = atof (argv[4]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "INIT_ROTATION") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        amgr->xyz_rot0[0] = atof (argv[2]);
        amgr->xyz_rot0[1] = atof (argv[3]);
        amgr->xyz_rot0[2] = atof (argv[4]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "INIT_SCALE") == 0)
    {
        if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;
        amgr->xyz_fac0[0]  = atof (argv[2]);
        amgr->xyz_fac0[1]  = atof (argv[3]);
        amgr->xyz_fac0[2]  = atof (argv[4]);
        tmp_data->box_flag = 1;
        return TCL_OK;
    }

    else if (strcmp (keyword, "CHANGE_SCALE_FACTOR") == 0)
    {
        amgr->scaleFactor = atof (argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "JSTICK_THRESH") == 0)
    {
        amgr->jstickThresh = atof (argv[2]);
        return TCL_OK;
    }

/* 30Oct06  Phil McDonald	TODO: deal with these C5D objects */
#ifdef CPP
    else if (strcmp (keyword, "C5D_VECTOR") == 0)
    {
        char        *fname;
        float       c[4];
        float       scale;

        if (!interp_check_argc (argc, argv, 8, 8)) return TCL_ERROR;

        tmp_data->needC5D = 1;
        c5d_vector *this_vector_ptr;

        this_vector_ptr = new c5d_vector;
        strcpy (curGO->label, argv[2]);
        fname = argv[3];
        scale = atof (argv[4]);
        c[0]  = atof (argv[5]);
        c[1]  = atof (argv[6]);
        c[2]  = atof (argv[7]);
        c[3]  = atof (argv[8]);
        ifstream    in (fname);

        in >> *this_vector_ptr;
        if (in.fail ())
        {
            fprintf (stderr, "ERROR: CAVE5D_VECTOR: %s failed to load.\n",
                     curGO->label);
            exit (EXIT_FAILURE);
        }
        curGO->red = c[0];
        curGO->green = c[1];
        curGO->blue = c[2];
        curGO->alpha = c[3];
        this_vector_ptr->set_color (c);
        this_vector_ptr->set_scale (scale);
        curGO->hook = this_vector_ptr;
        curGO->grType = CAVE5D_VECTOR;
        amgr->gobjCnt++;
        return TCL_OK;
    }

    else if (strcmp (keyword, "C5D_BAR_GRAPH") == 0)
    {
        c5d_bar_graph *this_bar_ptr;

        if (!interp_check_argc (argc, argv, 12, 12)) return TCL_ERROR;

        this_bar_ptr = new c5d_bar_graph;
        tmp_data->needC5D = 1;
        char        *fname;
        float       clamp[2];
        float       foot[2];
        char        dim = '\0';
        float       c[4];

        strcpy (curGO->label, argv[2]);
        fname   = argv[3];
        foot[0]  = atof (argv[4]);
        foot[1]  = atof (argv[5]);
        clamp[0] = atof (argv[6]);
        clamp[1] = atof (argv[7]);
        dim      = argv[8][0];
        c[0]     = argv[9]);
        c[1]     = argv[10]);
        c[2]     = argv[11]);
        c[3]     = argv[12]);
        ifstream    in (fname);

        in >> *this_bar_ptr;
        else if (in.fail ())
        {
            fprintf (stderr, "ERROR: CAVE5D_BAR_GRAPH: %s failed to load\n",
                     curGO->label);
            exit (EXIT_FAILURE);
        }
        curGO->red   = c[0];
        curGO->green = c[1];
        curGO->blue  = c[2];
        curGO->alpha = c[3];
        this_bar_ptr->set_color (c);
        if ((dim == 'X') || (dim == 'x'))
            this_bar_ptr->init (clamp, foot, c5d_bar_graph::X);
        else if ((dim == 'Y') || (dim == 'y'))
            this_bar_ptr->init (clamp, foot, c5d_bar_graph::Y);
        else if ((dim == 'Z') || (dim == 'z'))
            this_bar_ptr->init (clamp, foot, c5d_bar_graph::Z);
        else
        {
            delete      this_bar_ptr;

            fprintf (stderr, "ERROR: CAVE5D_BAR_GRAPH: %s %s.\n",
                    curGO->label, "failed to set dimension");
            return TCL_OK;
        }
        curGO->hook    = this_bar_ptr;
        curGO->grType  = CAVE5D_BAR_GRAPH;
        amgr->gobjCnt++;
        return TCL_OK;
    }

    else if (strcmp (keyword, "C5D_SURFACE") == 0)
    {
        c5d_surface *this_surface_ptr;

        if (!interp_check_argc (argc, argv, 8, 8)) return TCL_ERROR;

        this_surface_ptr = new c5d_surface;
        tmp_data->needC5D = 1;
        char        *fname;
        float       scale;
        float       c[4];

        strcpy (curGO->label, argv[2]);
        fname = argv[3];
        scale = atof (argv[4]);
        c[0]  = atof (argv[5]);
        c[1]  = atof (argv[6]);
        c[2]  = atof (argv[7]);
        c[3]  = atof (argv[8]);
        ifstream    in (fname);

        if (!in)
        {
            fprintf (stderr, "ERROR: Couldn't open %s\n", fname);
            return;
        }
        in >> *this_surface_ptr;
        if (in.fail ())
        {
            fprintf (stderr, "ERROR: CAVE5D_SURFACE: %s failed to load.\n",
                     curGO->label);
            exit (EXIT_FAILURE);
        }
        curGO->red   = c[0];
        curGO->green = c[1];
        curGO->blue  = c[2];
        curGO->alpha = c[3];
        this_surface_ptr->set_color (c);
        this_surface_ptr->set_scale (scale);
        curGO->hook   = this_surface_ptr;
        curGO->grType = CAVE5D_SURFACE;
        amgr->gobjCnt++;
        return TCL_OK;
    }
#endif
/* end PM */

    else if (strcmp (keyword, "CLOCK_MODE") == 0)
    {
        if (strcmp (argv[2], "DECIMAL") == 0)
            tmp_data->mode = DECIMAL;
        else if (strcmp (argv[2], "VIS5D") == 0)
            tmp_data->mode = VIS5D;
        else
            tmp_data->mode = OFF;
        return TCL_OK;
    }

    else if (strcmp (keyword, "CLOCK_SCALE") == 0)
    {
        tmp_data->clockScale = atof (argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "TARGET_RATE") == 0)
    {
        amgr->anim_rate_fps = atof (argv[2]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "CLOCK_POSITION") == 0)
    {
        if (!interp_check_argc (argc, argv, 7, 7)) return TCL_ERROR;
        tmp_data->top_left[0]     = atof (argv[2]);
        tmp_data->top_left[1]     = atof (argv[3]);
        tmp_data->top_left[2]     = atof (argv[4]);
        tmp_data->bottom_right[0] = atof (argv[5]);
        tmp_data->bottom_right[1] = atof (argv[6]);
        tmp_data->bottom_right[2] = atof (argv[7]);
        return TCL_OK;
    }

    else if (strcmp (keyword, "CAVENEAR") == 0)
    {
        tmp_data->clip_near = atof (argv[2]);
        return TCL_OK;
    }

    else if ((strcmp (keyword, "CAVEFAR") == 0) ||
        (strcmp (keyword, "CAVEFar") == 0))
    {
        tmp_data->clip_far = atof (argv[2]);
        return TCL_OK;
    }


    return interp_bad_command (argc, argv);
}



static int interp_menu_item (APP_MGR *amgr, Tcl_Interp *interp,
                             int argc, char *argv[])
{
    int         gIdx;
    GOVIS5D     *gobj;



    if (!interp_check_argc (argc, argv, 4, 4)) return TCL_ERROR;

    if (amgr->gobjCnt >= MAX_GOBJCNT)
    {
        fprintf (stderr, "CAVE5D: config: ERROR: %s %d %s.\n",
                 "too many objects -- more than", MAX_GOBJCNT,
                 "will be ignored");
        return TCL_ERROR;
    }

    gIdx = amgr->gobjCnt;
    gobj = &(amgr->gobj[gIdx]);

    strcpy (gobj->label, argv[2]);

    if (strcmp (argv[3], "VIS5D_ISOSURF") == 0)
    {
        gobj->grType = VIS5D_ISOSURF;
    }
    else if (strcmp (argv[3], "VIS5D_HSLICE") == 0)
    {
        gobj->grType = VIS5D_HSLICE;
    }
    else if (strcmp (argv[3], "VIS5D_VSLICE") == 0)
    {
        gobj->grType = VIS5D_VSLICE;
    }
    else if (strcmp (argv[3], "VIS5D_CHSLICE") == 0)
    {
        gobj->grType = VIS5D_CHSLICE;
    }
    else if (strcmp (argv[3], "VIS5D_CVSLICE") == 0)
    {
        gobj->grType = VIS5D_CVSLICE;
    }
    else if (strcmp (argv[3], "VIS5D_HWIND") == 0)
    {
        gobj->grType = VIS5D_HWIND;
    }
    else if (strcmp (argv[3], "VIS5D_VWIND") == 0)
    {
        gobj->grType = VIS5D_VWIND;
    }
    else if (strcmp (argv[3], "VIS5D_HSTREAM") == 0)
    {
        gobj->grType = VIS5D_HSTREAM;
    }
    else if (strcmp (argv[3], "VIS5D_VSTREAM") == 0)
    {
        gobj->grType = VIS5D_VSTREAM;
    }
    else if (strcmp (argv[3], "VIS5D_VOLUME") == 0)
    {
        gobj->grType = VIS5D_VOLUME;
    }
    else if (strcmp (argv[3], "VIS5D_TRAJ") == 0)
    {
        gobj->grType = VIS5D_TRAJ;
    }
    else if (strcmp (argv[3], "VIS5D_TOPO") == 0)
    {
        gobj->grType = VIS5D_TOPO;
    }
    else if (strcmp (argv[3], "VIS5D_MAP") == 0)
    {
        gobj->grType = VIS5D_MAP;
    }
    else
    {
        return interp_bad_command (argc, argv);
    }

    strcpy (gobj->vName, argv[4]);

    amgr->gobjCnt++;


    return TCL_OK;
}



static void interp_register (APP_MGR *amgr, Tcl_Interp *interp,
                             char *cmd_name, int (*cmd_func) ())
{
    Tcl_CreateCommand (interp, cmd_name, cmd_func, amgr, NULL);
    return ;
}



static void interp_register_commands (APP_MGR *amgr, Tcl_Interp *interp)
{
    interp_register (amgr, interp, "cave5d_parm_set", interp_parm_set);
    interp_register (amgr, interp, "cave5d_menu_item", interp_menu_item);


    return;
}
/* end PM */



/* 05Aug07  Phil McDonald	read config data from Tcl/Tk file */
static int interp_tcl (APP_MGR *amgr, char *file_name)
{
    char        cmd[1024], *str, *p_chr;
    Tcl_Interp  *interp;
    FILE        *file;



    interp = Tcl_CreateInterp ();
    if (interp == NULL)
    {
        fprintf (stderr, "CAVE5D: config: ERROR: %s.\n",
                 "couldn't create Tcl/Tk interpreter");
        return 0;
    }
    register_api_commands (interp);
    interp_register_commands (amgr, interp);


    if ((file = fopen (file_name, "r")) == NULL)
    {
        fprintf (stderr, "CAVE5D: config: ERROR: %s >%s<.\n",
                 "couldn't open config file", file_name);
        return 0;
    }

    str = cmd;
    while (fgets (str, (sizeof (cmd) - (str - cmd)), file) != NULL)
    {
        if ((p_chr = strchr (str, '\n')) != NULL) *p_chr = '\0';
        fprintf (stderr, "CAVE5D: config: %s\n", str);

        if ((p_chr = strchr (str, '\\')) != NULL)
        {
            /* Handle a backslash continuation */
            *p_chr = ' ';
            while (isspace (*p_chr)) p_chr--;
            *(++p_chr) = '\0';

            str = p_chr;
        }
        else
        {
            str = cmd;
            if (Tcl_Eval (interp, cmd) != TCL_OK)
            {
                if (strstr (interp->result, "close-brace") != NULL)
                {
                   strcat (cmd, " ; ");
                   str += strlen (cmd);
                }
                else
                {
                   fprintf (stderr, "CAVE5D: config: ERROR: %s\n",
                            interp->result);
                }
            }
        }
    }


    return 1;
}
/* end PM */



/*
 * Subroutine - process parameters identified in config file
 */

void process_config (APP_MGR * amgr, char *file_name)
{

    int        gIdx;
    GOVIS5D    *curGO;



    /* Allocate memory for temporary storage */
    amgr->tmp = (TPARAMS *) vrlib_shmem_alloc (sizeof (TPARAMS));


    /* set some initial values */

    amgr->tmp->hiresflag = 0;

    /*nav initialization */
    amgr->nav_style    = CAVE5D_OBJECT_NAV;
    amgr->navSpeed     = 1.0;
    amgr->scaleMode    = 0;
    amgr->scaleFactor  = 1.0;
    amgr->jstickThresh = 0.01;
/* 09Jul07  Phil McDonald */
    amgr->xyz_pos0[0] = 0.0;
    amgr->xyz_pos0[1] = 5.0;
    amgr->xyz_pos0[2] = -5.0;
    amgr->xyz_rot0[0] = 0.0;
    amgr->xyz_rot0[1] = 0.0;
    amgr->xyz_rot0[2] = 0.0;
    amgr->xyz_fac0[0] = 1.0;
    amgr->xyz_fac0[1] = 1.0;
    amgr->xyz_fac0[2] = 1.0;
/* end PM */


    /*light defaults */
    amgr->tmp->position_0[0] = 0.0;
    amgr->tmp->position_0[2] = 500.0;
    amgr->tmp->position_0[1] = 500.0;
    amgr->tmp->ambient_0[0]  = 0.3;
    amgr->tmp->ambient_0[1]  = 0.3;
    amgr->tmp->ambient_0[2]  = 0.3;
    amgr->tmp->diffuse_0[0]  = 0.4;
    amgr->tmp->diffuse_0[1]  = 0.4;
    amgr->tmp->diffuse_0[2]  = 0.4;
    amgr->tmp->specular_0[0] = 1.0;
    amgr->tmp->specular_0[1] = 1.0;
    amgr->tmp->specular_0[2] = 1.0;
    amgr->tmp->ambient[0]    = 0.2;
    amgr->tmp->ambient[1]    = 0.2;
    amgr->tmp->ambient[2]    = 0.2;


    /*box size (let v5d select) */
    amgr->tmp->box[0]   = 0.0;
    amgr->tmp->box[1]   = 0.0;
    amgr->tmp->box[2]   = 0.0;
    amgr->tmp->box_flag = 1;
    amgr->anim_rate_fps = 0.5;

    /*clock stuff */
    amgr->tmp->mode            = OFF;
    amgr->tmp->clockScale      = 1;
    amgr->tmp->top_left[0]     = -3.0;
    amgr->tmp->top_left[1]     = 3.0;
    amgr->tmp->top_left[2]     = -5.0;
    amgr->tmp->bottom_right[0] = -2.25;
    amgr->tmp->bottom_right[1] = 2.25;
    amgr->tmp->bottom_right[2] = -5.0;

    /* memory stuff */
    amgr->tmp->c5d_mem_size   = 30;
    amgr->tmp->needC5D        = 0;
/* 17Aug07  Phil McDonald	TODO: method to specify number of workers */
    amgr->tmp->workers        = 0;
/* end PM */

/* 21Mar07  Phil McDonald */
    amgr->user_data     = 0;
    amgr->user_topo     = 0;
    amgr->user_map      = 0;
    amgr->topo_base_lev = 0.0;

/* 08Aug07  Phil McDonald */
    amgr->gobjCnt        = 0;
    amgr->tmp->clip_near = 0.2;
    amgr->tmp->clip_far  = 300.0;
/* end PM */



/* 05Aug07  Phil McDonald */
    fprintf (stderr, "\nCAVE5D: config: reading config file %s.\n", file_name);
    if (!interp_tcl (amgr, file_name))
    {
        fprintf (stderr, "CAVE5D: config: %s %s.\n",
                 "error reading config file", file_name);
        exit (EXIT_FAILURE);
    }
    fprintf (stderr, "CAVE5D: config: finished reading config file.\n\n");
/* end PM */


/* 08Aug07  Phil McDonald */
    vrlib_clip_planes (amgr->tmp->clip_near, amgr->tmp->clip_far);
/* end PM */

/* 13Aug07  Phil McDonald	Find the object variable indices and */
/*				data contexts                        */
    gobj_init (amgr);
/* end PM */

/* 29Jun07  Phil McDonald */
    printf ("C5D memory size: %d\n", amgr->tmp->c5d_mem_size);
    printf ("NavSpeed: %f\n", amgr->navSpeed);
    printf ("Initial Position: %f %f %f\n",
            amgr->xyz_pos0[0], amgr->xyz_pos0[1], amgr->xyz_pos0[2]);
    printf ("Initial Rotation: %f %f %f\n",
            amgr->xyz_rot0[0], amgr->xyz_rot0[1], amgr->xyz_rot0[2]);
    printf ("Initial Scale: %f %f %f\n",
            amgr->xyz_fac0[0], amgr->xyz_fac0[1], amgr->xyz_fac0[2]);
    printf ("Graphical Objects: %d\n", amgr->gobjCnt);
    for (gIdx = 0; gIdx < amgr->gobjCnt; gIdx++)
        printf ("\t%s\n", amgr->gobj[gIdx].label);
/* end PM */


    return;
}
