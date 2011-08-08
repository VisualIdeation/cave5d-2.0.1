/*******************************************************************************
 * Name: vrlib.h    Config_No: 1.00    Date: 07/19/07
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
 * Header File: vrlib.h
 *
 */

#ifndef VRLIB_H
#  define VRLIB_H

#  include <unistd.h>



/* 19Jul07  Phil McDonald */
    extern void vrlib_init (void);
    extern void vrlib_exit (void);
    extern void vrlib_shmem_free (void *mem);
    extern void *vrlib_shmem_alloc (size_t size);
    extern void vrlib_shmem_init (size_t size);
    extern void vrlib_shmem_set_funcs (void);
    extern void *vrlib_lock_create (void);
    extern void vrlib_lock_on (void *lock);
    extern void vrlib_lock_off (void *lock);
    extern void vrlib_clip_planes (float near, float far);
    extern float vrlib_get_time (void);
    extern int vrlib_button_state (int ibutton);
    extern int vrlib_button_change (int ibutton);
    extern float vrlib_joystick_dist (int iaxis);
    extern void vrlib_head_pos (float head_pos[], int virt_world);
    extern void vrlib_wand_posvec (float wand_pos[], float wand_vec[],
                                   int virt_world);
    extern void vrlib_wand_orient (float wand_orient[], int virt_world);
    extern void vrlib_nav_lock (void);
    extern void vrlib_nav_unlock (void);
    extern void vrlib_nav_reset (void);
    extern void vrlib_nav_transform (void *vrlib_data);
    extern void vrlib_nav_translate (float xoff, float yoff, float zoff);
    extern void vrlib_nav_rotate (float xrot, float yrot, float zrot);
    extern void vrlib_nav_scale (float *p_xfac, float *p_yfac,
                                 float *p_zfac, int iaxis);
/* end PM */

#endif
