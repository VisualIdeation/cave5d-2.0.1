/*******************************************************************************
 * Name: panelUI.h    Config_No: 1.5    Date: 08/01/01
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
 * 
 * Header - panelUI.h
 *
 */

#ifndef PANEL_H
#  define PANEL_H



#  define MAX_BUTTONS      25
#  define BUTTON_MAXSTATE  3

/*
 * Color Definitions
 */
/* 08May07  Phil McDonald */
#  ifdef WORDS_BIGENDIAN
#    define COLOR(R,G,B)   ( ((R) << 24) | ((G) << 16) | ((B) << 8) | 0xff )
#  else
#    define COLOR(R,G,B)   ( (0xff << 24) | ((B) << 16) | ((G) << 8) | (R) )
#  endif
/* end PM */
#  define PMGR_BLACK     COLOR(0,0,0)
#  define PMGR_WHITE     COLOR(255,255,255)

//Colors added and changed by SAM
#  define PMGR_GREY1     COLOR(50,50,50)
#  define PMGR_GREY2     COLOR(200,200,200)
#  define PMGR_BLUE1     COLOR(0,0,255)
#  define PMGR_BLUE2     COLOR(50, 50, 150)
#  define PMGR_RED1      COLOR(255,0,0)
#  define PMGR_GREEN1    COLOR(0,255,0)
#  define PMGR_ORANGE    COLOR(255,165,0)
#  define PMGR_PURPLE    COLOR(85,26,139)
#  define PMGR_YELLOW    COLOR(255,193,37)
#  define PMGR_MAGENTA   COLOR(238,0,238)


/*
 * Structure definition: Panel Button
 */
struct panel_button
{
    int         x, y, width, height, id, state, maxState;
    unsigned int bgColor[BUTTON_MAXSTATE], textColor[BUTTON_MAXSTATE];
    char        label[80];
};
typedef struct panel_button PBUTTON;

/*
 * Structure definition: Panel Manager
 */
struct panel_manager
{
    int         width, height, buttonCnt, drawBorder;        // drawBorder was addded by SAM switch to draw border or not
    unsigned int bgColor, textColor, *image,
        bbg[BUTTON_MAXSTATE], btx[BUTTON_MAXSTATE];
    float       vert[4][3];
    PBUTTON     button[MAX_BUTTONS];
/* 17Jul07  Phil McDonald */
    void        *lock;
/* 20Oct06  Phil McDonald	GL texture name */
    int         tex_id;
/* end PM */
};
typedef struct panel_manager PMGR;

/*
     3                    2
      +------------------+
      |                  |
      |                  |
      |                  |
      |                  |
      +------------------+
     0                    1
*/

/**************
 * EXTERNs
 **************/
#  ifdef __cplusplus
extern      "C"
{
#  endif

/* 30Oct06  Phil McDonald */
#  ifdef CPP
#    if 1
    typedef struct app_manager APP_MGR;
#    endif
#  else
#    include "cave5d.h"
#  endif
/* end PM */
    extern void pmgr_initUI (APP_MGR * amgr);
    extern int  pmgr_actionUI (APP_MGR * amgr, float wandpos[3],
                               float wanddir[3], int *state1);
    extern void pmgr_renderUI (PMGR * panel);

/* 09Jul07  Phil McDonald	moved from cave5d.c */
    extern int  pmgr_queryUI (APP_MGR * amgr,
                              float wand_pos[3], float wand_vec[3]);
/* end PM */

#  ifdef __cplusplus
}
#  endif

#endif
