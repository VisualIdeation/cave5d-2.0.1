/*******************************************************************************
 * Name: cave5d.h    Config_No: 1.22    Date: 08/01/01
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
 * Header File: cave5d.h
 *
 */

#ifndef CAVE5D_H
#  define CAVE5D_H



#  include "GL/gl.h"
#  include <malloc.h>
#  include <string.h>
#  include <stdio.h>
/* 19Jul07  Phil McDonald */
#  include "vrlib.h"


#  define MAX_GOBJCNT   24      /* Maximum number of graphics objects */
#  define MAX_PARAMCNT  15      /* Maximum number of gobj parameters */
#  define MAX_CLONECNT  4       /* Maximum number of cloned variables */

#  define MAX_VNAMELEN  32      /* Maximum length of variable name */
#  define MAX_LABELLEN  64      /* Maximum length of label */
#  define MAX_FNAMELEN  512     /* Maximum length of file names */

#  define MAX(A,B)           ( (A) > (B) ? (A) : (B) )
#  define CLAMP(X,MIN,MAX)   ( (X)>(MAX) ? (MAX) : (((X)<MIN) ? (MIN) : (X)) )

typedef enum
{ OFF, VIS5D, DECIMAL } clock_mode;

typedef enum
{ CAVE5D_OBJECT_NAV, CAVE5D_AIRPLANE_NAV } nav_type;

/* 20Dec05  Phil McDonald */
#  define CAVE5D_UNKNOWN                -1

#  define CAVE5D_VECTOR                 1000
#  define CAVE5D_BAR_GRAPH              1001
#  define CAVE5D_SURFACE                1002

/* 03Sep06  Phil McDonald */
#  define CAVE5D_STATUS_OK              0
#  define CAVE5D_STATUS_QUIT            1
/* 01Feb08  Phil McDonald */
#  define CAVE5D_STATUS_FRAME           2
#  define CAVE5D_STATUS_PAUSE           3
#  define CAVE5D_STATUS_RESUME          4

/* 10Sep07  Phil McDonald */
#  define CAVE5D_MEGABYTES              1024 * 1024
/* end PM */



/* 01Feb08  Phil McDonald */
#  define CAVE5D_RENDER_MAX             24 /* max number of renderers */

typedef struct
{
    int         pid;
    int         status;
} RENDER_INFO;
/* end PM */



/**************
 * Structure for Graphic Object 
 **************/
struct vis5d_gobj
{
    int         grType;         /* one of Vis5d supported object types */
    int         varNo;          /* Vis5d variable number */
    int         mode;           /* display mode ON/OFF */
    int         moveSlice;      /* flag to make slices move-able */
    char        vName[MAX_VNAMELEN];    /* Vis5d variable name */
    char        label[MAX_LABELLEN];    /* Descriptive label */
    char        chParam[MAX_VNAMELEN];  /* character parameter - generic gobj support */
    float       param[MAX_PARAMCNT];    /* float parameters - generic gobj support */
    float       red, green, blue, alpha;        /* color,transparency for object */
/* 19Dec05  Phil McDonald */
    int         idatactx;       /* DATA context index */
/* end PM */
    void       *hook;           // support for unknown stuff
};
typedef struct vis5d_gobj GOVIS5D;


/**************
 * Structure for Temporary Parameters
 **************/
struct temp_params
{
    /* file names */
    // Added by SAM -Some panels were added for the user to change the config file
    char        datafile[MAX_FNAMELEN], topofile[MAX_FNAMELEN];
    char        datafile2[MAX_FNAMELEN];
    char        mapfile[MAX_FNAMELEN], savefile[MAX_FNAMELEN];

    /* Name of Velocity/Traj variables */
    char        uvel1[MAX_VNAMELEN], vvel1[MAX_VNAMELEN], wvel1[MAX_VNAMELEN];
    char        uvel2[MAX_VNAMELEN], vvel2[MAX_VNAMELEN], wvel2[MAX_VNAMELEN];
    char        utraj[MAX_VNAMELEN], vtraj[MAX_VNAMELEN], wtraj[MAX_VNAMELEN];
    char        cloneFrom[MAX_CLONECNT][MAX_VNAMELEN];
    char        cloneTo[MAX_CLONECNT][MAX_VNAMELEN];
    int         cloneCnt;
    float       top_left[3];    /*location of the clock */
    float       bottom_right[3];
    float       clockScale;     /*decimal clock scaleing factor */
    clock_mode  mode;
    GLfloat     ambient[3];     //scene ambient light
    GLfloat     position_0[3];  //position of light_0
    GLfloat     ambient_0[3];   //ambient light form light source 0
    GLfloat     diffuse_0[3];
    GLfloat     specular_0[3];
    float       box[3];
    int         box_flag;
    int         hiresflag;      //Added by SAM 2-13-01 to allow for high resolution topo
    int         workers;        //Added by SAM 2-28-01 to allow the user to set the amount of pros to work on
    int         c5d_mem_size, vis5d_mem_size;   //memory allocation for c5d and vis5d objects 
    int         needC5D;        //flag indicating c5d objects are available
/* 12Oct06  Phil McDonald	texture map file name */
    char       *texture;
/* 08Aug07  Phil McDonald */
    float       clip_near;
    float       clip_far;
/* 30Nov07  Phil McDonald */
    char        config_main[MAX_FNAMELEN];
    char        config_help[MAX_FNAMELEN];
    char        config_gobj[MAX_FNAMELEN];
    char        config_parms[MAX_FNAMELEN];
    char        config_entry[MAX_FNAMELEN];
/* end PM */
};
typedef struct temp_params TPARAMS;

/**************
 * Structure for Clock Manager
 **************/
struct clock
{
    float     **verts;          /*the ordered triplets that determine where the hand points */
/* 17Jul07  Phil McDonald */
    void       *lock;
/* end PM*/
    clock_mode  mode;           /* vis5d mode or generic decimal clock mode */
    float       xcenter;
    float       ycenter;
    float       zcenter;
    int        *datestamp;
    int        *timestamp;
    float       clockScale;
    float       base[3];
    float       up[3];
    float       stamp[2];
    float       step[2];
    float       date[2];
};
typedef struct clock CLOCK;



/**************
 * Structure for Application Manager
 **************/
struct app_manager
{
    int         startTime;      /*Added by SAM the changed time step start point */
    int         endTime;        /*Added by SAM the changed time step end point */

    int         numtimesChanged;        /*true if numtimes was changed */
/* 16Jul07  Phil McDonald	made navSpeed a float */
    float       navSpeed;       /* navigation speed */
/* end PM */
    int         gobjCnt;        /* number of graphic objects */
    int         numtimes;       /* number of timesteps */
    int         curtime;        /* current timestep */
    int         animFlag;       /* 1=anim forward, 0=stop */
    int         step_fwd;       /* 1=step ahead one, 0=no step */
    int         cc;             /* current Vis5d context */
    int         dx;             /* current Vis5d display context added by SAM for 5.2 update */
    int         gui;            /* current Vis5d Gui context added by SAM for 5.2 update */
    int         rowCnt, colCnt, lvlCnt; /* Size of Vis5d grid */
    int         scaleMode;      /* 0-none,1-X,2-Y,3-Z */
    // initial box size selection
    float       scaleFactor, jstickThresh;      /* Factor for changing Scales; Jstick Threshhold */
    GOVIS5D     gobj[MAX_GOBJCNT];      /* Graphic Object Structures */
    int         gObject;        /* Temp grType Holder to change gObject values ....Added by SAM */
    int         gIndex;         /* Temp holder for the gIdx ....Added by SAM */
    //Added by SAM - Some panels were added to allow users to change the config file
    TPARAMS    *tmp;            /* Temporary parameters structure */
    CLOCK      *clock;
    nav_type    nav_style;      /* Rotate object,Rotate Self,scale */
    char        numStr1[5];     //holds the value to change to flagged variable Added by SAM
    float       numStr2;        //hold the value to change to flagged variable after it is changed for a char * to a float Added by SAM
    int         changeFlag;     //flagged variable Added by SAM
    char        variableChangeLabel[15];        //holds the label of the variable that is being changed ADDED by SAM
/* 08Dec05  Phil McDonald	a little space here would be nice */
/*
	char *curValue;					//holds the current value being changed ADDED by SAM	
*/
    char        curValue[20];
/* end PM */
    char        TimeStep[20];
    char       *startTimeString;
    char       *endTimeString;
    float       varChange;      /* holds the value to be changed  ADDED by SAM */

/* 03Sep06  Phil McDonald	to signal termination, timestep sync, etc. */
    int         status;
/* 01Feb08  Phil McDonald	to keep track of rendering status */
    int         nrender;
    RENDER_INFO render_info[CAVE5D_RENDER_MAX];
/* 09Nov06  Phil McDonald	user data, topo and map flags */
    int         user_data;
    int         user_topo;
    int         user_map;
/* 05Mar07  Phil McDonald	animation parameters */
    float       anim_rate_fps;  /* animation rate (frames per second) */
    int         anim_step_usec; /* terminating time of current timestep */
/* 21Mar07  Phil McDonald */
    float       topo_base_lev;  /* position of topo base */
/* 09Jul07  Phil McDonald	standardized navigation parms */
    float       xyz_pos0[3];    /* initial position */
    float       xyz_rot0[3];    /* initial rotation */
    float       xyz_fac0[3];    /* initial scale factor */
    float       xyz_pos[3];     /* current position */
    float       xyz_rot[3];     /* current rotation */
    float       xyz_fac[3];     /* current scale factor */
    float       xyz_off[3];     /* current translation */
    float       xyz_tmp[3];     /* temporary data */
/* 30Nov07  Phil McDonald */
    struct panel_manager *panel;         /* current gui panel */
    struct panel_manager *panel_main;
    struct panel_manager *panel_help;
    struct panel_manager *panel_objselect;
    struct panel_manager *panel_objchange;
    struct panel_manager *panel_objparms;
    struct panel_manager *panel_entry;
    struct panel_manager *panel_hwind;
    struct panel_manager *panel_vwind;
    struct panel_manager *panel_hstream;
    struct panel_manager *panel_vstream;
    struct panel_manager *panel_hslice;
    struct panel_manager *panel_vslice;
    struct panel_manager *panel_chslice;
    struct panel_manager *panel_cvslice;
    struct panel_manager *panel_isosurf;
    struct panel_manager *panel_traj;
    struct panel_manager *panel_volume;
    int                  cur_iobj;  /* object being changed */
    int                  cur_iparm; /* object parm being changed */

/* 22Jan08  Phil McDonald	light position needed by render_display */
    GLfloat     light0_pos[4];
/* 01Feb08  Phil McDonald */
    int         redraw;
/* end PM */

};
typedef struct app_manager APP_MGR;

/**************
 * DEFINES for params in GOVIS5D
 **************/
#  define GOBJ_CINT 0           /* contour interval */
#  define GOBJ_CMIN 1           /* contour min value */
#  define GOBJ_CMAX 2           /* contour max value */

#  define GOBJ_ISOVAL 0         /* isosurface value */
/* 04Jan06  Phil McDonald	provide for mulitple data contexts */
#  define GOBJ_ISOALTCTX 1      /* color variable data context for surface color */
#  define GOBJ_ISOALTVAR 2      /* color variable for surface color */
/* end PM */

#  define GOBJ_DENSITY 0        /* density of vectors */
#  define GOBJ_SCALE   1        /* scale factor */

#  define GOBJ_VLVL 5           /* vertical position */
#  define GOBJ_R0 3             /* starting row */
#  define GOBJ_C0 4             /* starting col */
#  define GOBJ_R1 5             /* ending row */
#  define GOBJ_C1 6             /* ending col */

static const int GOBJ_minROW = 0;       /*start row of traj block */
static const int GOBJ_maxROW = 1;       /* end row */
static const int GOBJ_Rint = 2; /* space between trajectory points */
static const int GOBJ_minCOLUMN = 3;
static const int GOBJ_maxCOLUMN = 4;
static const int GOBJ_Cint = 5;
static const int GOBJ_minLEVEL = 6;
static const int GOBJ_maxLEVEL = 7;
static const int GOBJ_Lint = 8;
static const int GOBJ_minTIME = 9;      /*start of time steps to be passed to vis5d API */
static const int GOBJ_maxTIME = 10;     /* end of time steps */
static const int GOBJ_LENGTH = 11;      /*length of trajectory */
static const int GOBJ_STEP = 12;        /*step size */
static const int GOBJ_FLAG = 13;        /*ribbon or non-ribbon */

// our objects


/**************
 * EXTERNs 
 **************/

#  ifndef MAIN_CAVE
extern void *c5d_share_mem;
#  endif

#  ifdef __cplusplus
extern      "C"
{
#  endif

/* gobj.c */
/* 23Aug07  Phil McDonald	added zMove */
    extern void gobj_move (APP_MGR * amgr, float xMove, float yMove,
                           float zMove);
/* 06Nov07  Phil McDonald */
    extern void gobj_get_parms (APP_MGR *amgr, int gIdx);
    extern void gobj_set_parms (APP_MGR *amgr, int gIdx);
/* 09Nov07  Phil McDonald */
    extern void gobj_modify (APP_MGR * amgr, int gIdx, int state);
    extern void gobj_make (APP_MGR * amgr, int gIdx);
    extern void gobj_init (APP_MGR * amgr);
/* 01Feb08  Phil McDonald */
    extern int gobj_state (APP_MGR *amgr, int gIdx, int mode);
/* end PM */

/* config.c */
    extern void process_config (APP_MGR * amgr, char *fname);

/* from script.c of vis5dSupport */
    extern int  execute_script (int cc, char *savefile);

/* from clock.c */
    extern void init_clock (APP_MGR * amgr);
    extern void draw_clock (float R, float G, float B, APP_MGR * amgr);

/* 01Mar07  Phil McDonald */
/* cave5d.c */
    extern int  cave5d_find_var (int idispctx, char *var_name,
                                 int *p_idatactx, int *p_ivar);
/* end PM */

#  ifdef __cplusplus
}
#  endif

#endif
