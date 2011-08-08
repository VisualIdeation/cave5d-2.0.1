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
 *******************************************************************************
 *
 *  VR library-specific functions
 *
 *******************************************************************************
 *******************************************************************************
 */

#include "vrlib.h"



/* 19Jul07  Phil McDonald */
#ifdef FREEVR
#  include "freevr.h"

#  define HEAD_SENSOR            0
#  define WAND_SENSOR            1



/*******************************************************************************
 *
 *  PRIVATE functions
 *
 *******************************************************************************
 */

void vrlib_init_GL (void)
{
    cave5d_render_init_GL (0);
    return;
}



void vrlib_frame (vrRenderInfo *vrlib_data)
{
    cave5d_render_frame ((void *) vrlib_data);
    return;
}



void vrlib_display (vrRenderInfo *vrlib_data)
{
    cave5d_render_display ((void *) vrlib_data);
    return;
}



/*******************************************************************************
 *
 *  PUBLIC functions
 *
 *******************************************************************************
 */

void vrlib_init (void)
{
    vrStart ();
    vrFunctionSetCallback (VRFUNC_DISPLAY_INIT,
                           vrCallbackCreate (vrlib_init_GL, 0));
    vrFunctionSetCallback (VRFUNC_DISPLAY_FRAME,
                           vrCallbackCreate (vrlib_frame, 0));
    vrFunctionSetCallback (VRFUNC_DISPLAY,
                           vrCallbackCreate (vrlib_display, 0));
    return;
}



void vrlib_exit (void)
{
    vrExit ();
    return;
}



void vrlib_shmem_free (void *mem)
{
    if (mem != NULL) vrShmemFree (mem);
    return;
}



void *vrlib_shmem_alloc (size_t size)
{
    return vrShmemAlloc (size);
}



void vrlib_shmem_init (size_t size)
{
    vrShmemInit (size);
    vrConfigure (NULL, NULL, NULL);
    return;
}



void vrlib_shmem_set_funcs (void)
{
    vis5d_mem_set_funcs (NULL, vrShmemAlloc, vrShmemFree);
    return;
}



void *vrlib_lock_create (void)
{
    return (void *) vrLockCreate ();
}



void vrlib_lock_on (void *lock)
{
    vrLockReadSet ((vrLock) lock);
    return;
}



void vrlib_lock_off (void *lock)
{
    vrLockReadRelease ((vrLock) lock);
    return;
}



void vrlib_clip_planes (float near, float far)
{
    /* TODO: set the Near and Far clipping planes */
    return;
}
/* end PM */



float vrlib_get_time (void)
{
    return vrCurrentSimTime ();
}



int vrlib_button_state (int ibutton)
{
    if (ibutton == -1) ibutton = 0; /* check for quit */
    return vrGet2switchValue (ibutton);
}



int vrlib_button_change (int ibutton)
{
    return vrGet2switchDelta (ibutton);
}



float vrlib_joystick_dist (int iaxis)
{
    return vrGetValuatorValue (iaxis);
}



/* 24Aug07  Phil McDonald	TODO: include vw functions in CaveLib */
void vrlib_head_pos (float head_pos[], int virt_world)
{
    vrPoint    pos;

    if (virt_world)
    {
        vrPointGetVWFromUser6sensor (&pos, 0, HEAD_SENSOR);
        head_pos[VR_X] = pos.v[VR_X];
        head_pos[VR_Y] = pos.v[VR_Y];
        head_pos[VR_Z] = pos.v[VR_Z];
    }
    else
    {
        vrPointGetRWFrom6sensor (&pos, HEAD_SENSOR);
        head_pos[VR_X] = pos.v[VR_X];
        head_pos[VR_Y] = pos.v[VR_Y];
        head_pos[VR_Z] = pos.v[VR_Z];
    }
    return;
}



void vrlib_wand_posvec (float wand_pos[], float wand_vec[], int virt_world)
{
    vrPoint    pos;
    vrVector   vec;

    if (virt_world)
    {
        vrPointGetVWFromUser6sensor (&pos, 0, WAND_SENSOR);
        wand_pos[VR_X] = pos.v[VR_X];
        wand_pos[VR_Y] = pos.v[VR_Y];
        wand_pos[VR_Z] = pos.v[VR_Z];
        vrVectorGetVWFromUser6sensorDir (&vec, 0, WAND_SENSOR, VRDIR_FORE);
        wand_vec[VR_X] = vec.v[VR_X];
        wand_vec[VR_Y] = vec.v[VR_Y];
        wand_vec[VR_Z] = vec.v[VR_Z];
    }
    else
    {
        vrPointGetRWFrom6sensor (&pos, WAND_SENSOR);
        wand_pos[VR_X] = pos.v[VR_X];
        wand_pos[VR_Y] = pos.v[VR_Y];
        wand_pos[VR_Z] = pos.v[VR_Z];
        vrVectorGetRWFrom6sensorDir (&vec, WAND_SENSOR, VRDIR_FORE);
        wand_vec[VR_X] = vec.v[VR_X];
        wand_vec[VR_Y] = vec.v[VR_Y];
        wand_vec[VR_Z] = vec.v[VR_Z];
    }
    return;
}



void vrlib_wand_orient (float wand_orient[], int virt_world)
{
/* TODO: The user of Eulers is seriously depricated.                          */
/*       This section should be rewritten.                                    */
    vrEuler     euler;

    if (virt_world)
    {
        vrEulerGetVWFromUser6sensor (&euler, 0, WAND_SENSOR);
        wand_orient[VR_AZIM] = euler.r[VR_AZIM];
        wand_orient[VR_ELEV] = euler.r[VR_ELEV];
        wand_orient[VR_ROLL] = euler.r[VR_ROLL];
    }
    else
    {
        vrEulerGetRWFrom6sensor (&euler, WAND_SENSOR);
        wand_orient[VR_AZIM] = euler.r[VR_AZIM];
        wand_orient[VR_ELEV] = euler.r[VR_ELEV];
        wand_orient[VR_ROLL] = euler.r[VR_ROLL];
    }
    return;
}



void vrlib_nav_lock (void)
{
    vrUserTravelLockSet (VR_ALLUSERS);
    return;
}



void vrlib_nav_unlock (void)
{
    vrUserTravelLockRelease (VR_ALLUSERS);
    return;
}



void vrlib_nav_reset (void)
{
    vrUserTravelReset (VR_ALLUSERS);
    return;
}



void vrlib_nav_transform (void *vrlib_data)
{
    vrRenderTransformUserTravel ((vrRenderInfo *) vrlib_data);
    return;
}



void vrlib_nav_translate (float xoff, float yoff, float zoff)
{
    vrUserTravelTranslate3d (VR_ALLUSERS, xoff, yoff, zoff);
    return;
}



void vrlib_nav_rotate (float xrot, float yrot, float zrot)
{
    vrUserTravelRotateId (VR_ALLUSERS, VR_X, xrot);
    vrUserTravelRotateId (VR_ALLUSERS, VR_Y, yrot);
    vrUserTravelRotateId (VR_ALLUSERS, VR_Z, zrot);
    return;
}



void vrlib_nav_scale (float *p_xfac, float *p_yfac, float *p_zfac, int iaxis)
{

    float    fac;

    switch (iaxis)
    {
        case 0:
            fac = *p_xfac;
            break;
        case 1:
            fac = *p_yfac;
            break;
        case 2:
            fac = *p_zfac;
            break;
    }
    vrUserTravelScale (VR_ALLUSERS, fac);
    *p_xfac = fac;
    *p_yfac = fac;
    *p_zfac = fac;
    return;
}
#endif
/* end PM */



/* 19Jul07  Phil McDonald */
#ifdef CAVE
#  include "cave_ogl.h"



/*******************************************************************************
 *
 *  PRIVATE functions
 *
 *******************************************************************************
 */

void vrlib_init_GL (void)
{
    cave5d_render_init_GL (0);
    return;
}



void vrlib_frame (void)
{
    cave5d_render_frame (NULL);
    return;
}



void vrlib_display (void)
{
    cave5d_render_display (NULL);
    return;
}



/*******************************************************************************
 *
 *  PUBLIC functions
 *
 *******************************************************************************
 */

void vrlib_init (void)
{
    CAVEInit ();
    CAVEInitApplication (vrlib_init_GL, 0);
    CAVEFrameFunction (vrlib_frame, 0);
    CAVEDisplay (vrlib_display, 0);
    return;
}



void vrlib_exit (void)
{
    CAVEExit ();
    return;
}



void vrlib_shmem_free (void *mem)
{
    if (mem != NULL) CAVEFree (mem);
    return;
}



void *vrlib_shmem_alloc (size_t size)
{
    return CAVEMalloc (size);
}



void vrlib_shmem_init (size_t size)
{
    CAVESetOption (CAVE_SHMEM_SIZE, size);
    CAVEConfigure (NULL, NULL, NULL);
    usconfig (CONF_INITSIZE, 1 << 33);
    usconfig (CONF_ARENATYPE, US_SHAREDONLY);
    usconfig (CONF_INITUSERS, 10);
    return;
}



void vrlib_shmem_set_funcs (void)
{
    vis5d_mem_set_funcs ((void *) (CAVEAlloc),
                         (void *) (CAVEAlloc), (void) (CAVEFree));
    return;
}



void *vrlib_lock_create (void)
{
    return (void *) CAVENewLock ();
}



void vrlib_lock_on (void *lock)
{
    CAVESetReadLock ((CAVELOCK) lock);
    return;
}



void vrlib_lock_off (void *lock)
{
    CAVEUnsetReadLock ((CAVELOCK) lock);
    return;
}



void vrlib_clip_planes (float near, float far)
{
    CAVENear = near;
    CAVEFar  = near;
    return;
}
/* end PM */




float vrlib_get_time (void)
{
    return CAVEGetTime ();
}



int vrlib_button_state (int ibutton)
{
    switch (ibutton)
    {
        case -1: /* check for quit */
            return (CAVEgetbutton (CAVE_ESCKEY) || CAVEgetbutton (CAVE_DELKEY));
        case 1:
            return CAVEBUTTON1;
        case 2:
            return CAVEBUTTON2;
        case 3:
            return CAVEBUTTON3;
        case 4:
            return CAVEBUTTON4;
    }
    return 0;
}



int vrlib_button_change (int ibutton)
{
    return CAVEButtonChange (ibutton);
}



float vrlib_joystick_dist (int iaxis)
{
    if (iaxis == 0) return CAVE_JOYSTICK_X;

    return CAVE_JOYSTICK_Y;
}



void vrlib_head_pos (float head_pos[])
{
    CAVEGetPosition (CAVE_HEAD_NAV, pos);
    return;
}



void vrlib_wand_posvec (float wand_pos[], float wand_vec[])
{
    CAVEGetPosition (CAVE_WAND, wand_pos);
    CAVEGetVector (CAVE_WAND_FRONT, wand_vec);
    return;
}



void vrlib_wand_orient (float wand_orient[])
{
    CAVEGetOrientation (CAVE_WAND, wand_orient);
    return;
}



void vrlib_nav_lock (void)
{
    CAVENavLock ();
    return;
}



void vrlib_nav_unlock (void)
{
    CAVENavUnlock ();
    return;
}



void vrlib_nav_reset (void)
{
    CAVENavLoadIdentity ();
    return;
}



void vrlib_nav_transform (void *vrlib_data)
{
    CAVENavTransform ();
    return;
}



void vrlib_nav_translate (float xoff, float yoff, float zoff)
{
    CAVENavTranslate (xoff, yoff, zoff);
    return;
}



void vrlib_nav_rotate (float xrot, float yrot, float zrot)
{
    CAVENavRot (xrot, 'x');
    CAVENavRot (yrot, 'y');
    CAVENavRot (zrot, 'z');
    return;
}



void vrlib_nav_scale (float *p_xfac, float *p_yfac, float *p_zfac, int iaxis)
{
    CAVENavScale (*p_xfac, *p_yfac, *p_zfac);
    return;
}
#endif
/* end PM */
