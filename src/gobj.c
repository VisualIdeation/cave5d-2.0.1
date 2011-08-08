/*******************************************************************************
 * Name: gobj.c    Config_No: 1.7    Date: 08/01/01
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

/***************************************************************************** 
 * Compilation Unit - gobj.c   Graphic Object Functionality
 * 
 * gobj_move
 * gobj_modify
 * gobj_make
 * gobj_init
 *
 */

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "cave5d.h"
#include "panelUI.h"
#include "api.h"
/* 30Oct06  Phil McDonald */
#ifdef CPP
#  include "c5d_vector.h"
#  include "c5d_bar_graph.h"
#  include "c5d_surface.h"
#endif
/* end PM */



/* 23Aug07  Phil McDonald */
#define MOVE_FACTOR              20.0
#define MOVE_EPS                 0.0001
/* end PM */



/* 23Aug07  Phil McDonald */
void gobj_msg (char *mod, char *str1, char *str2, GOVIS5D *gobj)
{
    int         new_line;
    char        *str, *p_tmp;


    new_line = 0;

    fprintf (stderr, "%s: ", mod);
    if (str1 != NULL)
    {
        str = strdup (str1);
        if ((p_tmp = strchr (str, '\n')) != NULL)
        {
            new_line = 1;
            *p_tmp   = '\0';
        }
        fprintf (stderr, "%s: ", str);
        free (str);
    }
    if (gobj != NULL)
    {
        fprintf (stderr, ">%s< >%s< %d %d %d",
                 gobj->label, gobj->vName, gobj->varNo, gobj->grType,
                 gobj->idatactx);
    }
    if (str2 != NULL)
    {
        str = strdup (str2);
        if ((p_tmp = strchr (str, '\n')) != NULL)
        {
            new_line = 1;
            *p_tmp   = '\0';
        }
        fprintf (stderr, " %s", str);
        free (str);
    }
    if (new_line) fprintf (stderr, "\n");


    return;
}
/* end PM */



/* 06Nov07  Phil McDonald */
void gobj_get_color (APP_MGR *amgr, int gIdx)
{
    GOVIS5D    *gobj;



    gobj = &(amgr->gobj[gIdx]);

    vis5d_get_color (amgr->dx, gobj->grType, gobj->varNo,
                     &(gobj->red), &(gobj->green), &(gobj->blue),
                     &(gobj->alpha));


    return;
}



void gobj_set_color (APP_MGR *amgr, int gIdx)
{
    GOVIS5D    *gobj;



    gobj = &(amgr->gobj[gIdx]);

    vis5d_set_color (amgr->dx, gobj->grType, gobj->varNo,
                     gobj->red, gobj->green, gobj->blue, gobj->alpha);


    return;
}



void gobj_get_parms (APP_MGR *amgr, int gIdx)
{
    GOVIS5D    *gobj;



    gobj = &(amgr->gobj[gIdx]);

    switch (gobj->grType)
    {
        case VIS5D_HWIND:
            vis5d_get_hwindslice (amgr->dx, gobj->varNo,
                                  &(gobj->param[GOBJ_DENSITY]),
                                  &(gobj->param[GOBJ_SCALE]),
                                  &(gobj->param[GOBJ_VLVL]));
            break;

        case VIS5D_VWIND:
            vis5d_get_vwindslice (amgr->dx, gobj->varNo,
                                  &(gobj->param[GOBJ_DENSITY]),
                                  &(gobj->param[GOBJ_SCALE]),
                                  &(gobj->param[GOBJ_R0]),
                                  &(gobj->param[GOBJ_C0]),
                                  &(gobj->param[GOBJ_R1]),
                                  &(gobj->param[GOBJ_C1]));
            break;

        case VIS5D_HSTREAM:
            vis5d_get_hstreamslice (amgr->dx, gobj->varNo,
                                    &(gobj->param[GOBJ_DENSITY]),
                                    &(gobj->param[GOBJ_VLVL]));
            break;

        case VIS5D_VSTREAM:
            vis5d_get_vstreamslice (amgr->dx, gobj->varNo,
                                    &(gobj->param[GOBJ_DENSITY]),
                                    &(gobj->param[GOBJ_R0]),
                                    &(gobj->param[GOBJ_C0]),
                                    &(gobj->param[GOBJ_R1]),
                                    &(gobj->param[GOBJ_C1]));
            break;

        case VIS5D_HSLICE:
            vis5d_get_hslice (gobj->idatactx, gobj->varNo,
                              &(gobj->param[GOBJ_CINT]),
                              &(gobj->param[GOBJ_CMIN]),
                              &(gobj->param[GOBJ_CMAX]),
                              &(gobj->param[GOBJ_VLVL]));
            break;

        case VIS5D_VSLICE:
            vis5d_get_vslice (gobj->idatactx, gobj->varNo,
                              &(gobj->param[GOBJ_CINT]),
                              &(gobj->param[GOBJ_CMIN]),
                              &(gobj->param[GOBJ_CMAX]),
                              &(gobj->param[GOBJ_R0]),
                              &(gobj->param[GOBJ_C0]),
                              &(gobj->param[GOBJ_R1]),
                              &(gobj->param[GOBJ_C1]));
            break;

        case VIS5D_CHSLICE:
            vis5d_get_chslice (gobj->idatactx, gobj->varNo,
                               &(gobj->param[GOBJ_VLVL]));
            break;

        case VIS5D_CVSLICE:
            vis5d_get_cvslice (gobj->idatactx, gobj->varNo,
                               &(gobj->param[GOBJ_R0]),
                               &(gobj->param[GOBJ_C0]),
                               &(gobj->param[GOBJ_R1]),
                               &(gobj->param[GOBJ_C1]));
            break;

/* 06Nov07  Phil McDonald	TODO: */
        case VIS5D_TRAJ:
            break;
/* end PM */

        case VIS5D_ISOSURF:
            vis5d_get_isosurface (gobj->idatactx, gobj->varNo,
                                  &(gobj->param[GOBJ_ISOVAL]));
            break;

        case VIS5D_VOLUME:
            /* Nothing to do */
            break;
    }
    gobj_get_color (amgr, gIdx);


    return;
}



void gobj_set_parms (APP_MGR *amgr, int gIdx)
{
    GOVIS5D    *gobj;



    gobj = &(amgr->gobj[gIdx]);
    gobj_msg ("gobj_set_parms", "\n", NULL, gobj);

    switch (gobj->grType)
    {
        case VIS5D_HWIND:
            vis5d_set_hwindslice (amgr->dx, gobj->varNo,
                                  gobj->param[GOBJ_DENSITY],
                                  gobj->param[GOBJ_SCALE],
                                  gobj->param[GOBJ_VLVL]);
            break;

        case VIS5D_VWIND:
            vis5d_set_vwindslice (amgr->dx, gobj->varNo,
                                  gobj->param[GOBJ_DENSITY],
                                  gobj->param[GOBJ_SCALE],
                                  gobj->param[GOBJ_R0],
                                  gobj->param[GOBJ_C0],
                                  gobj->param[GOBJ_R1],
                                  gobj->param[GOBJ_C1]);
            break;

        case VIS5D_HSTREAM:
            vis5d_set_hstreamslice (amgr->dx, gobj->varNo,
                                    gobj->param[GOBJ_DENSITY],
                                    gobj->param[GOBJ_VLVL]);
            break;

        case VIS5D_VSTREAM:
            vis5d_set_vstreamslice (amgr->dx, gobj->varNo,
                                    gobj->param[GOBJ_DENSITY],
                                    gobj->param[GOBJ_R0],
                                    gobj->param[GOBJ_C0],
                                    gobj->param[GOBJ_R1],
                                    gobj->param[GOBJ_C1]);
            break;

        case VIS5D_HSLICE:
            vis5d_set_hslice (gobj->idatactx, gobj->varNo,
                              gobj->param[GOBJ_CINT],
                              gobj->param[GOBJ_CMIN],
                              gobj->param[GOBJ_CMAX],
                              gobj->param[GOBJ_VLVL]);
            break;

        case VIS5D_VSLICE:
            vis5d_set_vslice (gobj->idatactx, gobj->varNo,
                              gobj->param[GOBJ_CINT],
                              gobj->param[GOBJ_CMIN],
                              gobj->param[GOBJ_CMAX],
                              gobj->param[GOBJ_R0],
                              gobj->param[GOBJ_C0],
                              gobj->param[GOBJ_R1],
                              gobj->param[GOBJ_C1]);
            break;

        case VIS5D_CHSLICE:
            vis5d_set_chslice (gobj->idatactx, gobj->varNo,
                               gobj->param[GOBJ_VLVL]);
            break;

        case VIS5D_CVSLICE:
            vis5d_set_cvslice (gobj->idatactx, gobj->varNo,
                               gobj->param[GOBJ_R0],
                               gobj->param[GOBJ_C0],
                               gobj->param[GOBJ_R1],
                               gobj->param[GOBJ_C1]);
            break;

/* 06Nov07  Phil McDonald	TODO: */
        case VIS5D_TRAJ:
            break;
/* end PM */

        case VIS5D_ISOSURF:
            vis5d_set_isosurface (gobj->idatactx, gobj->varNo,
                                  gobj->param[GOBJ_ISOVAL]);
            break;

        case VIS5D_VOLUME:
            /* Nothing to do */
            break;
    }
    gobj_set_color (amgr, gIdx);

    amgr->redraw = 1;


    return;
}
/* end PM */



/* 05Jan06  Phil McDonald */
int gobj_check (GOVIS5D * gobj)
{
    if (gobj == NULL) return 0;

    if (gobj->idatactx < 0)
    {
        if ((gobj->grType == VIS5D_TOPO) || (gobj->grType == VIS5D_MAP))
            return 1;

        if ((gobj->grType == VIS5D_HWIND  ) ||
            (gobj->grType == VIS5D_VWIND  ) ||
            (gobj->grType == VIS5D_HSTREAM) ||
            (gobj->grType == VIS5D_VSTREAM) ||
            (gobj->grType == VIS5D_TRAJ   ))
        {
            if (gobj->varNo >= 0) return 1;
        }
    }
    else
    {
        if ((gobj->grType == VIS5D_ISOSURF) ||
            (gobj->grType == VIS5D_HSLICE ) ||
            (gobj->grType == VIS5D_VSLICE ) ||
            (gobj->grType == VIS5D_CHSLICE) ||
            (gobj->grType == VIS5D_CVSLICE) ||
            (gobj->grType == VIS5D_VOLUME ))
        {
            if ((gobj->varNo >= 0) && (gobj->vName[0] != '\0')) return 1;
        }
    }
    fprintf (stderr, "CAVE5D: gobj_check: ERROR: >%s< >%s< %s=%d %s=%d %s=%d\n",
             "bad object", gobj->label, gobj->vName, "var", gobj->varNo,
             "type", gobj->grType, "idatactx", gobj->idatactx);


    return 0;
}
/* end PM */



/* 
 * Subroutine: Move slices based on button3/wand interactions
 */
/* 23Aug07  Phil McDonald */
void gobj_move (APP_MGR * amgr, float xMove, float yMove, float zMove)
{
    int        gIdx, iaxis, max_rcl[3];
    float      delta_rcl[3];
    float      x, y, z, xyzmax;
    GOVIS5D    *gobj;



    /* Constrain movement to only one axis */
    delta_rcl[0] = fabs (yMove);
    delta_rcl[1] = fabs (xMove);
    delta_rcl[2] = fabs (zMove);
    xyzmax       = delta_rcl[0];
    if (delta_rcl[1] > xyzmax) xyzmax = delta_rcl[1];
    if (delta_rcl[2] > xyzmax) xyzmax = delta_rcl[2];
    if (xyzmax < MOVE_EPS) return;
    if (delta_rcl[0] < xyzmax) yMove = 0.0;
    if (delta_rcl[1] < xyzmax) xMove = 0.0;
    if (delta_rcl[2] < xyzmax) zMove = 0.0;

    delta_rcl[0] = -yMove; /* rows are the reverse of Y */
    delta_rcl[1] =  xMove; /* cols */
    delta_rcl[2] =  zMove; /* levs */

    max_rcl[0]   = amgr->rowCnt - 1;
    max_rcl[1]   = amgr->colCnt - 1;
    max_rcl[2]   = amgr->lvlCnt - 1;

    for (gIdx = 0; gIdx < amgr->gobjCnt; gIdx++)
    {
        gobj  = &amgr->gobj[gIdx];
        iaxis = gobj->moveSlice - 1;
        if ((iaxis >= 0) && (gobj->mode == 1) && (delta_rcl[iaxis] != 0.0))
        {
            gobj_get_parms (amgr, gIdx);
            switch (gobj->grType)
            {
                case VIS5D_CHSLICE:
                case VIS5D_HSLICE:
                case VIS5D_HWIND:
                case VIS5D_HSTREAM:
                    gobj->param[GOBJ_VLVL] += delta_rcl[2] * MOVE_FACTOR;
                    gobj->param[GOBJ_VLVL]  = CLAMP (gobj->param[GOBJ_VLVL],
                                                     0, max_rcl[2]);
                    break;

                case VIS5D_CVSLICE:
                case VIS5D_VSLICE:
                case VIS5D_VWIND:
                case VIS5D_VSTREAM:
                    if (iaxis == 0)
                    {
                        gobj->param[GOBJ_R0] += delta_rcl[0] * MOVE_FACTOR;
                        gobj->param[GOBJ_R0]  = CLAMP (gobj->param[GOBJ_R0],
                                                       0, max_rcl[0]);
                        gobj->param[GOBJ_R1] += delta_rcl[0] * MOVE_FACTOR;
                        gobj->param[GOBJ_R1]  = CLAMP (gobj->param[GOBJ_R1],
                                                       0, max_rcl[0]);
                    }
                    else
                    {
                        gobj->param[GOBJ_C0] += delta_rcl[1] * MOVE_FACTOR;
                        gobj->param[GOBJ_C0]  = CLAMP (gobj->param[GOBJ_C0],
                                                       0, max_rcl[1]);
                        gobj->param[GOBJ_C1] += delta_rcl[1] * MOVE_FACTOR;
                        gobj->param[GOBJ_C1]  = CLAMP (gobj->param[GOBJ_C1],
                                                       0, max_rcl[1]);
                    }
                    break;

            }
            gobj_set_parms (amgr, gIdx);
        }
    }


    return;
}
/* end PM */



/* 01Feb08  Phil McDonald */
int gobj_state (APP_MGR *amgr, int iobj, int mode)
{
    int         state, flag;
    GOVIS5D     *gobj;



    gobj = &(amgr->gobj[iobj]);

    if (gobj->idatactx < 0)
    {
        if ((gobj->grType == VIS5D_TOPO) || (gobj->grType == VIS5D_MAP))
        {
            state = vis5d_graphics_mode (amgr->dx, gobj->grType, mode);
        }
        else
        {
            state = vis5d_enable_graphics (amgr->dx, gobj->grType,
                                           gobj->varNo, mode);
        }
    }
    else
    {
        state = vis5d_enable_graphics (gobj->idatactx, gobj->grType,
                                       gobj->varNo, mode);
    }

    if (gobj->grType == VIS5D_TOPO)
    {
        vis5d_check_texture (amgr->dx, &flag);
        if (flag) vis5d_graphics_mode (amgr->dx, VIS5D_TEXTURE, mode);
    }
    else if (gobj->grType == VIS5D_MAP)
    {
        vis5d_check_topo (amgr->dx, &flag);
        if (flag) vis5d_enable_sfc_map (amgr->dx, mode);
    }

    if (mode != VIS5D_GET) amgr->redraw = 1;


    return state;
}
/* end PM */



/* 
 * Subroutine: Update Graphical Objects based on UI Event
 */
void gobj_modify (APP_MGR * amgr, int gIdx, int state)
{
    GOVIS5D    *cur;
    int         flag;



/* 09Nov07  Phil McDonald */
    if ((gIdx < 0) || (gIdx >= amgr->gobjCnt)) return;

    cur = &(amgr->gobj[gIdx]);

/* 20Dec05  Phil McDonald */
    if (!gobj_check (cur)) return;
/* end PM */

    /* Based on button state set mode/moveSlice FLAGS */
    cur->moveSlice = 0;

    switch (state)
    {
        case 0:
            gobj_msg ("gobj_modify", "turning off\n", NULL, cur);
            cur->mode = 0;
            gobj_state (amgr, gIdx, VIS5D_OFF);
            break;

        case 1:
            gobj_msg ("gobj_modify", "turning on\n", NULL, cur);
            cur->mode = 1;
            gobj_state (amgr, gIdx, VIS5D_ON);
            break;

        case 2:
/* 23Aug07  Phil McDonald */
            if ((cur->grType == VIS5D_CHSLICE) ||
                (cur->grType == VIS5D_HSLICE ) ||
                (cur->grType == VIS5D_HWIND  ) ||
                (cur->grType == VIS5D_HSTREAM))
            {
                cur->moveSlice = 3; /* move through levels */
            }
            else
            {
/* 23Aug07  Phil McDonald	TODO: accommodate non-axis-aligned slices */
/* end PM */
                float       drow, dcol, r0, c0, r1, c1, xtmp;

                if (cur->grType == VIS5D_CVSLICE)
                {
                    vis5d_get_cvslice (cur->idatactx, cur->varNo,
                                       &r0, &c0, &r1, &c1);
                }
                else if (cur->grType == VIS5D_VSLICE)
                {
                    vis5d_get_vslice (cur->idatactx, cur->varNo,
                                      &xtmp, &xtmp, &xtmp, &r0, &c0, &r1, &c1);
                }
                else if (cur->grType == VIS5D_VWIND)
                {
                    vis5d_get_vwindslice (amgr->dx, cur->varNo,
                                          &xtmp, &xtmp, &r0, &c0, &r1, &c1);
                }
                else if (cur->grType == VIS5D_VSTREAM)
                {
                    vis5d_get_vstreamslice (amgr->dx, cur->varNo,
                                            &xtmp, &r0, &c0, &r1, &c1);
                }
                dcol = fabs (c0 - c1);
                drow = fabs (r0 - r1);
                /* 0 = move through rows; 1 = move through cols */
                cur->moveSlice = (dcol >= drow) ? 1 : 2;
            }
            gobj_msg ("gobj_modify", "moveable\n", NULL, cur);
/* end PM */
            break;
    }


    return;
}



/* 30Jan08  Phil McDonald	This may be totally obsolete now.  It is  */
/*				definitely oboslete for "normal"objects   */
/*				(slices, isosurfs, volumes, etc.) so the  */
/*				the section that dealt with these objects */
/*				has been removed.                         */
/* 
 * Subroutine: Make a graphical object
 */

/* 25Jan08  Phil McDonald	added make_func */
void gobj_make (APP_MGR * amgr, int gIdx)
{
    GOVIS5D    *cur;



    cur = &(amgr->gobj[gIdx]);

/* 20Dec05  Phil McDonald */
    if (!gobj_check (cur)) return;

/* 23Aug07  Phil McDonald	setting of parms/colors moved to UI */

    switch (cur->grType)
    {
            case VIS5D_TRAJ:
            fprintf (stderr, "...make traj\n");
#ifdef TODO
            /*error checking if statement */
            if ((cur->param[GOBJ_minROW] <= cur->param[GOBJ_maxROW])
                && (cur->param[GOBJ_minCOLUMN] <= cur->param[GOBJ_maxCOLUMN])
                && (cur->param[GOBJ_minLEVEL] <= cur->param[GOBJ_maxLEVEL])
                && (cur->param[GOBJ_minTIME] <= cur->param[GOBJ_maxTIME]))
            {
                float       r, c, l, rinterval, cinterval, linterval;
                int         t;

                /*Loop over availible dimentions */
                vis5d_set_traj (amgr->dx, cur->param[GOBJ_STEP],
                                cur->param[GOBJ_LENGTH],
                                (int) cur->param[GOBJ_FLAG]);
                gobj_set_color (amgr, cur, -1, -1);
                rinterval = cur->param[GOBJ_Rint];
                cinterval = cur->param[GOBJ_Cint];
                linterval = cur->param[GOBJ_Lint];
                /*loop over 4-D space */

                for (r = cur->param[GOBJ_minROW]; r <= cur->param[GOBJ_maxROW];
                     r += rinterval)
                {
                    for (c = cur->param[GOBJ_minCOLUMN];
                         c <= cur->param[GOBJ_maxCOLUMN]; c += cinterval)
                    {
                        for (l = cur->param[GOBJ_minLEVEL];
                             l <= cur->param[GOBJ_maxLEVEL]; l += linterval)
                        {
                            for (t = (int) cur->param[GOBJ_minTIME];
                                 t <= (int) cur->param[GOBJ_maxTIME]; t++)
                                vis5d_make_traj (amgr->dx, r, c, l, t,
                                                 (int) cur->varNo);


                        }

                    }

                }

            }                   /*endif */
            else
/* 02Jul07  Phil McDonald */
                fprintf (stderr, "ERROR: %s.  %s.\n",
                        "A trajectory min > max", "Check the config file");
/* end PM */
#endif
            break;

/* 30Oct06  Phil McDonald */
#ifdef CPP
        case CAVE5D_VECTOR:
            {
                c5d_vector *v;

                v = (c5d_vector *) cur->hook;
                v->calculate_render (amgr);
            }
        break;

        case CAVE5D_BAR_GRAPH:
            {
                c5d_bar_graph *bg;

                bg = (c5d_bar_graph *) cur->hook;
                bg->calculate_render (amgr);
            }
        break;

        case CAVE5D_SURFACE:
            {
                c5d_surface *sur;

                sur = (c5d_surface *) cur->hook;
                sur->calculate_render (amgr);
            }
        break;
#endif
/* end PM */

    } /* end switch */


    return;
}
/* end PM */



/*
 * Subroutine: initialize graphic objects
 */
/* 23Aug07  Phil McDonald */
void gobj_init (APP_MGR * amgr)
{
    int         gIdx;



    for (gIdx = 0; gIdx < amgr->gobjCnt; gIdx++)
    {
        if ((amgr->gobj[gIdx].grType == VIS5D_TOPO) ||
            (amgr->gobj[gIdx].grType == VIS5D_MAP))
        {
            amgr->gobj[gIdx].idatactx = -1;
            amgr->gobj[gIdx].varNo    = -1;
            amgr->gobj[gIdx].vName[0] = '\0';
        }
        else if ((amgr->gobj[gIdx].grType == VIS5D_HWIND  ) ||
                 (amgr->gobj[gIdx].grType == VIS5D_VWIND  ) ||
                 (amgr->gobj[gIdx].grType == VIS5D_HSTREAM) ||
                 (amgr->gobj[gIdx].grType == VIS5D_VSTREAM))
        {
            amgr->gobj[gIdx].idatactx = -1;
            amgr->gobj[gIdx].varNo    = atoi (amgr->gobj[gIdx].vName);
            amgr->gobj[gIdx].vName[0] = '\0';
        }
/* 23Aug07  Phil McDonald	TODO: deal with trajectories */
        else if (amgr->gobj[gIdx].grType == VIS5D_TRAJ)
        {
/* end PM */
        }
        else
        {
            cave5d_find_var (amgr->dx, amgr->gobj[gIdx].vName,
                             &(amgr->gobj[gIdx].idatactx),
                             &(amgr->gobj[gIdx].varNo));
            if (amgr->gobj[gIdx].idatactx == CAVE5D_UNKNOWN)
            {
                fprintf (stderr, "CAVE5D: config: graphical object %d %s %s.\n",                         amgr->gobj[gIdx].grType, amgr->gobj[gIdx].vName,
                         "cannot be found");
            }
        }
/* 06Nov07  Phil McDonald	get initial settings from Vis5D */
        gobj_get_parms (amgr, gIdx);
/* end PM */
    }


    return;
}
/* end PM */
