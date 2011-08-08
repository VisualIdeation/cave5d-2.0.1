/*******************************************************************************
 * Name: puiSupport.h    Config_No: 1.2     Date: 08/01/01
 *******************************************************************************
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
 * Header File	: puiSupport.h
 *
 */

#ifndef PANELSUPPORT_H
#  define PANELSUPPORT_H

/**************
 * EXTERNs
 **************/
extern int  pmgr_intersect (PMGR * panel, float pos[3],
                            float dir[3], int *x, int *y);
/* 08Nov07  Phil McDonald	reworked */
extern int  pmgr_pickButton (PMGR *panel, float wand_pos[], float wand_dir[]);
/* end PM */

extern void pmgr_plot (PMGR * panel, int x, int y, unsigned int color);
extern void pmgr_box (PMGR * panel, int x, int y, int width, int height,
                      unsigned int color);
extern void pmgr_line (PMGR * panel, int x1, int y1, int x2, int y2,
                       unsigned int color);
extern void pmgr_text (PMGR * panel, int x, int y, int width, int height,
                       char *str, unsigned int color);
extern void pmgr_frame (PMGR * panel, int x, int y, int width, int height,
                        int raised);
extern void pmgr_drawButton (PMGR * panel, int ibtn, int status);
extern void pmgr_makeButton (PMGR * panel, int ibtn, int x, int y, int width,
                             int height, char *label, int id,
                             unsigned int bbgColor[3], unsigned int btxColor[3],
                             int maxState);

extern void pmgr_config (PMGR * panel, char *fname,
                         unsigned color_bg[], unsigned int color_tx[]);

/* 08Nov07  Phil McDonald */
extern void pmgr_updateButton (PMGR *panel, int ibtn, int flash);
/* end PM */

#endif
