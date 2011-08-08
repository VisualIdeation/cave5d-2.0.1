/******************************************************************
 * Name: panelUI.c    Config_No: 1.14    Date: 08/01/01
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
 * Compilation Unit - panelUI.c    Graphical User Interface 
 *
 * pmgr_create_main
 * pmgr_create_objselect
 * pmgr_create_objchange
 * pmgr_renderUI
 * pmgr_initUI
 * pmgr_queryUI
 *
 */

#include <stdlib.h>
#include <unistd.h>
#include "panelUI.h"
#include "puiSupport.h"
#include "api.h"
#include "cave5d.h"



/* 07Nov07  Phil McDonald */
typedef struct {
    int         id;
    char        label[80];
    int         x;
    int         y;
    int         width;
    int         height;
    int		nstates;
} BTN_DATA;
/* end PM */



/* 07Nov07  Phil McDonald */
enum main_btn_id {
    MAIN_TITLE,
    MAIN_GOBJ,
    MAIN_STEPS,
    MAIN_SCALEX,
    MAIN_SCALEY,
    MAIN_SCALEZ,
    MAIN_SLOWER,
    MAIN_FASTER,
    MAIN_TIME0,
    MAIN_STEPFWD,
    MAIN_ANIMFWD,
    MAIN_CLOSE,
    MAIN_HELP,
    MAIN_EXIT
};

/* 12Nov07  Phil McDonald */
enum entry_btn_id {
    NUMPAD_0,
    NUMPAD_1,
    NUMPAD_2,
    NUMPAD_3,
    NUMPAD_4,
    NUMPAD_5,
    NUMPAD_6,
    NUMPAD_7,
    NUMPAD_8,
    NUMPAD_9,
    NUMPAD_DOT,
    NUMPAD_CLEAR,
    NUMPAD_ENTER,
    NUMPAD_CLOSE,
    NUMPAD_NBUTTONS,
    ENTRY_TITLE,
    ENTRY_PARM,
    ENTRY_CUR_VAL,
    ENTRY_NEW_VAL,
    ENTRY_NBUTTONS
};

#define ENTRY_NREADONLY        (ENTRY_NBUTTONS-NUMPAD_NBUTTONS-1)
/* end PM */



/* 26Nov07  Phil McDonald */
enum parm_id {
    PARM_ID_DENSITY,
    PARM_ID_SCALE,
    PARM_ID_VALUE,
    PARM_ID_CINT,
    PARM_ID_CMIN,
    PARM_ID_CMAX,
    PARM_ID_LEVEL,
    PARM_ID_ROW0,
    PARM_ID_COL0,
    PARM_ID_ROW1,
    PARM_ID_COL1,
    PARM_ID_COUNT
};

typedef struct {
    int         id;
    int         val;
    char        *str;
} PARM_DATA;
/* end PM */



/* 09Nov07  Phil McDonald */
#define PANEL_TITLE                  -1
#define PANEL_CLOSE                  -2

/* 12Nov07  Phil McDonald */
#define OBJECT_CHANGE                -3
#define OBJECT_RED                   -4
#define OBJECT_GREEN                 -5
#define OBJECT_BLUE                  -6
#define OBJECT_ALPHA                 -7
/* end PM */



/* 12Nov07  Phil McDonald */
static int pmgr_find_button (PMGR *panel, int btn_id)
{
    int         ibtn;



    if (panel == NULL) return -1;

    for (ibtn = 0; ibtn < panel->buttonCnt; ibtn++)
    {
        if (panel->button[ibtn].id == btn_id) return ibtn;
    }


    return -1;
}



static int pmgr_relabel_button (PMGR *panel, int btn_id, char str[])
{
    int         ibtn;



    if ((ibtn = pmgr_find_button (panel, btn_id)) < 0) return 0;

    strcpy (panel->button[ibtn].label, str);

    pmgr_drawButton (panel, ibtn, panel->button[ibtn].state);


    return 1;
}
/* end PM */



/* 13Nov07  Phil McDonald */
static int pmgr_parm_str (APP_MGR *amgr, int iobj, int iparm, int set_parm)
{
    float       val;
    GOVIS5D     *gobj;



    if (iobj < 0) return 0;

    gobj = &(amgr->gobj[iobj]);

    if (set_parm)
    {
        if (sscanf (amgr->curValue, "%g", &val) != 1) return 0;

        if (iparm < 0)
        {
            if ((val < 0.0) || (val > 1.0)) return 0;

            switch (iparm)
            {
                case OBJECT_RED:
                    gobj->red   = val;
                    break;

                case OBJECT_GREEN:
                    gobj->green = val;
                    break;

                case OBJECT_BLUE:
                    gobj->blue  = val;
                    break;

                case OBJECT_ALPHA:
                    gobj->alpha = val;
                    break;
            }
        }
        else
        {
            gobj->param[iparm] = val;
        }
    }
    else
    {
        if (iparm < 0)
        {
            switch (iparm)
            {
                case OBJECT_RED:
                    val = gobj->red;
                    break;

                case OBJECT_GREEN:
                    val = gobj->green;
                    break;

                case OBJECT_BLUE:
                    val = gobj->blue;
                    break;

                case OBJECT_ALPHA:
                    val = gobj->alpha;
                    break;
            }
        }
        else
        {
            val = gobj->param[iparm];
        }
    }

    sprintf (amgr->curValue, "%g", val);
    pmgr_relabel_button (amgr->panel_entry, ENTRY_CUR_VAL, amgr->curValue);
    pmgr_relabel_button (amgr->panel_entry, ENTRY_NEW_VAL, " ");

    strcpy (amgr->curValue, "");


    return 1;
}
/* end PM */



/* 07Nov07  Phil McDonald */
static PMGR *pmgr_create_panel (int width, int height, int nbuttons,
                                unsigned int panel_bg, unsigned int panel_tx,
                                unsigned int btn_bg[], unsigned int btn_tx[],
                                BTN_DATA buttons[], char config_file[])
{
    PMGR       *panel;



    panel = (PMGR *) vrlib_shmem_alloc (sizeof (PMGR));
    if (panel == NULL) return NULL;

    panel->lock  = vrlib_lock_create ();
    panel->image = (unsigned int *) vrlib_shmem_alloc (width * height *
                                                       sizeof (unsigned int));
    if ((panel->lock == NULL) || (panel->image == NULL))
    {
        vrlib_shmem_free (panel->lock);
        vrlib_shmem_free (panel->image);
        vrlib_shmem_free (panel);
        return NULL;
    }

    panel->width     = width;
    panel->height    = height;
    panel->buttonCnt = nbuttons;
    panel->bgColor   = panel_bg;
    panel->textColor = panel_tx;
    panel->tex_id    = -1;


    pmgr_config (panel, config_file, btn_bg, btn_tx);
    pmgr_box    (panel, 0, 0, panel->width, panel->height, panel->bgColor);
    pmgr_frame  (panel, 0, 0, panel->width, panel->height, 1);


    if (buttons != NULL)
    {
        int         ibtn;

        for (ibtn = 0; ibtn < nbuttons; ibtn++)
        {
            pmgr_makeButton (panel, ibtn,
                             buttons[ibtn].x, buttons[ibtn].y,
                             buttons[ibtn].width, buttons[ibtn].height,
                             buttons[ibtn].label, buttons[ibtn].id,
                             panel->bbg, panel->btx, buttons[ibtn].nstates);
        }
    }


    return panel;
}
/* end PM */



/* 09Nov07  Phil McDonald */
static void pmgr_make_simple (PMGR *panel, int nbtns, char *(btn_label[]),
                              int btn_id[], int btn_nstates[])
{
    unsigned int  white = PMGR_WHITE;
    unsigned int  black = PMGR_BLACK;

    int           ibtn, x, y, xsize, ysize, yspc, nstates;



    if (panel->buttonCnt <= 0) return;

    xsize  = panel->width - 36;
    x      = (panel->width - xsize) / 2;
    ysize  = panel->height / (panel->buttonCnt + 1);
    yspc   = (ysize < 20) ? 2 : 5;
    ysize -= yspc;
    y      = 255 - (ysize + (ysize / 2) + (yspc / 2));

    ibtn = 0;
    pmgr_makeButton (panel, ibtn, x, y, xsize, ysize,
                     btn_label[ibtn], btn_id[ibtn],
                     &white, &black, 1);
    pmgr_drawButton (panel, ibtn, 0);
    y -= ysize + yspc;

    for (ibtn = 1; ibtn < panel->buttonCnt; ibtn++)
    {
        nstates = (btn_nstates == NULL) ? 2 : btn_nstates[ibtn];

        pmgr_makeButton (panel, ibtn, x, y, xsize, ysize,
                         btn_label[ibtn], btn_id[ibtn],
                         panel->bbg, panel->btx, nstates);
        pmgr_drawButton (panel, ibtn, 0);

        y -= ysize + yspc;
    }


    return;
}



/* 07Nov07  Phil McDonald */
static PMGR *pmgr_create_main (APP_MGR *amgr)
{
    int           width    = 256;
    int           height   = 128;
    int           panel_bg = PMGR_PURPLE;
    int           panel_tx = PMGR_BLACK;
    unsigned int  btn_bg[] = { PMGR_YELLOW, PMGR_BLUE1,  PMGR_BLUE1  };
    unsigned int  btn_tx[] = { PMGR_BLUE1,  PMGR_YELLOW, PMGR_YELLOW };
    BTN_DATA btn[] =
    {
        MAIN_TITLE,   "Cave5D Release 2.0",  37, 105, 180,  20, 2,
        MAIN_GOBJ,    "Graphical Object ",    2,  80, 150,  20, 2,
        MAIN_STEPS,   "Time Steps ",        155,  80,  98,  20, 2,
        MAIN_SCALEX,  "ScaleX ",             13,  55,  60,  20, 2,
        MAIN_SCALEY,  "ScaleY ",             98,  55,  60,  20, 2,
        MAIN_SCALEZ,  "ScaleZ ",            183,  55,  60,  20, 2,
        MAIN_SLOWER,  "slow ",                7,  30,  45,  20, 2,
        MAIN_FASTER,  "fast ",               57,  30,  45,  20, 2,
        MAIN_TIME0,   "t=0 ",               112,  30,  35,  20, 2,
        MAIN_STEPFWD, " 1>  ",              152,  30,  45,  20, 2,
        MAIN_ANIMFWD, " >>  ",              202,  30,  45,  20, 2,
        MAIN_CLOSE,   "Close ",              40,   5,  55,  20, 2,
        MAIN_HELP,    "Help ",              110,   5,  55,  20, 2,
        MAIN_EXIT,    "Exit ",              180,   5,  55,  20, 2,
    };

    PMGR        *panel;
    int         nbtns;



    nbtns = sizeof (btn) / sizeof (BTN_DATA);

    panel = pmgr_create_panel (width, height, nbtns,
                               panel_bg, panel_tx, btn_bg, btn_tx,
                               btn, amgr->tmp->config_main);


    return panel;
}
/* end PM */



/* 29Nov07  Phil McDonald */
static PMGR *pmgr_create_help (APP_MGR * amgr)
{
    int           width    = 512;
    int           height   = 256;
    int           panel_bg = PMGR_PURPLE;
    int           panel_tx = PMGR_BLACK;
    unsigned int  btn_bg[] = { PMGR_PURPLE, PMGR_YELLOW, PMGR_PURPLE };
    unsigned int  btn_tx[] = { PMGR_YELLOW, PMGR_PURPLE, PMGR_GREY2  };
    BTN_DATA btn[] =
    {
        PANEL_CLOSE, "Close",                           210,  10,  55,  30, 2,
        0, "                   Master Panel",             1, 230,  -1,  20, 1,
        0, "!CAVE5D",                                     1, 205,  60,  20, 1,
        0, "toggle rotation between airplane & object",  61, 205,  -1,  20, 1,
        0, "!Graphical Objects",                          1, 185, 170,  20, 1,
        0, "turn objects on & off, also allows",        171, 185,  -1,  20, 1,
        0, " you to access -Change Configuration Values- option",
             10, 165,  -1,  20, 1,
        0, "!Scale",                                      1, 145,  50,  20, 1,
        0, "change size of box along each axis",         51, 145,  -1,  20, 1,
        0, "Animation Controls:",                         1, 125, 254,  20, 1,
        0, "!>>",                                         1, 105,  30,  20, 1,
        0, "animation",                                  35, 105,  90,  20, 1,
        0, "!t=0",                                      130, 105,  45,  20, 1,
        0, "first step",                                161, 105, 100,  20, 1,
        0, "!1>",                                       270, 105,  30,  20, 1,
        0, "advance one time step",                     291, 105, 200,  20, 1,
        0, "!slow",                                       1,  85,  50,  20, 1,
        0, "slow animation down",                        51,  85, 200,  20, 1,
        0, "!fast",                                     260,  85,  50,  20, 1,
        0, "speed animation up",                        310,  85, 200,  20, 1,
        0, "To rotate, hold down the middle button & move wand",
              1,  45,  -1,  20, 1,
    };

    PMGR          *panel;
    int           i, ibtn, nbtns;
    char          *label;
    unsigned int  *tx_color;



    nbtns = sizeof (btn) / sizeof (BTN_DATA);

    panel = pmgr_create_panel (width, height, nbtns,
                               panel_bg, panel_tx, btn_bg, btn_tx,
                               NULL, amgr->tmp->config_help);
    if (panel == NULL) return NULL;


    for (i = 0; i < BUTTON_MAXSTATE; i++)
    {
        panel->bbg[i] = panel->bgColor;
    }

    pmgr_makeButton (panel, 0,
                     btn[0].x, btn[0].y,
                     btn[0].width, btn[0].height,
                     btn[0].label, btn[0].id,
                     panel->bbg, panel->btx, btn[0].nstates);

    for (ibtn = 1; ibtn < nbtns; ibtn++)
    {
        btn[ibtn].id = ibtn;
        if (btn[ibtn].width < 0) btn[ibtn].width = width - btn[ibtn].x - 1;
        label    = btn[ibtn].label;
        tx_color = panel->btx;
        if (label[0] == '!')
        {
            label++;
            tx_color = panel->btx + 2;
        }
        pmgr_makeButton (panel, ibtn,
                         btn[ibtn].x, btn[ibtn].y,
                         btn[ibtn].width, btn[ibtn].height,
                         label, btn[ibtn].id,
                         panel->bbg, tx_color, btn[ibtn].nstates);
    }


    return panel;
}
/* end PM */



/* 09Nov07  Phil McDonald */
static PMGR *pmgr_create_objselect (APP_MGR * amgr)
{
    int           width        = 256;
    int           height       = 256;
    unsigned int  panel_bg     = PMGR_PURPLE;
    unsigned int  panel_tx     = PMGR_BLACK;
    unsigned int  btn_bg[3]    = { PMGR_BLUE1,  PMGR_YELLOW, PMGR_YELLOW };
    unsigned int  btn_tx[3]    = { PMGR_YELLOW, PMGR_BLUE1,  PMGR_BLACK  };
    char          title_str[]  = "Turn objects on and off";
    char          change_str[] = "Change Config Values";
    char          close_str[]  = "Close";

    PMGR          *panel;
    char          **btn_label;
    int           nbtns, ibtn, iobj, nstates, state, *btn_id, *btn_nstates;
    GOVIS5D       *gobj;



    nbtns = amgr->gobjCnt + 3;

    panel = pmgr_create_panel (width, height, nbtns,
                               panel_bg, panel_tx, btn_bg, btn_tx,
                               NULL, amgr->tmp->config_gobj);
    if (panel == NULL) return NULL;


    btn_label   = (char **) malloc (nbtns * sizeof (char*));
    btn_id      = (int *) malloc (nbtns * sizeof (int));
    btn_nstates = (int *) malloc (nbtns * sizeof (int));
    if ((btn_label == NULL) || (btn_id == NULL) || (btn_nstates == NULL))
    {
        if (btn_label   != NULL) free (btn_label);
        if (btn_id      != NULL) free (btn_id);
        if (btn_nstates != NULL) free (btn_nstates);

        return panel;
    }

    ibtn              = 0;
    btn_label[ibtn]   = title_str;
    btn_id[ibtn]      = PANEL_TITLE;
    btn_nstates[ibtn] = 1;

    for (iobj = 0; iobj < amgr->gobjCnt; iobj++)
    {
        gobj = &(amgr->gobj[iobj]);

        ibtn++;
        btn_label[ibtn]   = gobj->label;
        btn_id[ibtn]      = iobj;
        btn_nstates[ibtn] = 2;
        if ((gobj->grType == VIS5D_HWIND)   ||
            (gobj->grType == VIS5D_VWIND)   ||
            (gobj->grType == VIS5D_HSTREAM) ||
            (gobj->grType == VIS5D_VSTREAM) ||
            (gobj->grType == VIS5D_HSLICE)  ||
            (gobj->grType == VIS5D_VSLICE)  ||
            (gobj->grType == VIS5D_CHSLICE) ||
            (gobj->grType == VIS5D_CVSLICE))
        {
            btn_nstates[ibtn] = 3;
        }
    }

    ibtn++;
    btn_label[ibtn]   = change_str;
    btn_id[ibtn]      = OBJECT_CHANGE;
    btn_nstates[ibtn] = 2;
    ibtn++;
    btn_label[ibtn]   = close_str;
    btn_id[ibtn]      = PANEL_CLOSE;
    btn_nstates[ibtn] = 2;

    pmgr_make_simple (panel, nbtns, btn_label, btn_id, btn_nstates);

    free (btn_label);
    free (btn_id);
    free (btn_nstates);


    /* Synchronize the button states with the object states */

    for (ibtn = 1; ibtn < nbtns-2; ibtn++)
    {
        iobj  = btn_id[ibtn];
        state = gobj_state (amgr, iobj, VIS5D_GET);
        pmgr_drawButton (panel, ibtn, state);
    }


    return (panel);
}
/* end PM */



/* 09Nov07  Phil McDonald */
static PMGR *pmgr_create_objchange (APP_MGR * amgr)
{
    int           width       = 256;
    int           height      = 256;
    unsigned int  panel_bg    = PMGR_BLUE2;
    unsigned int  panel_tx    = PMGR_BLACK;
    unsigned int  btn_bg[3]   = { PMGR_PURPLE, PMGR_YELLOW, PMGR_YELLOW };
    unsigned int  btn_tx[3]   = { PMGR_YELLOW, PMGR_BLUE1,  PMGR_BLACK  };
    char          title_str[] = "Select object to change";
    char          close_str[] = "Close";

    PMGR          *panel;
    char          **btn_label;
    int           nbtns, ibtn, iobj, *btn_id;
    GOVIS5D       *gobj;



    nbtns = amgr->gobjCnt + 2;

    panel = pmgr_create_panel (width, height, nbtns,
                               panel_bg, panel_tx, btn_bg, btn_tx,
                               NULL, amgr->tmp->config_gobj);
    if (panel == NULL) return NULL;


    btn_label = (char **) malloc (nbtns * sizeof (char*));
    btn_id    = (int *) malloc (nbtns * sizeof (int));
    if ((btn_label == NULL) || (btn_id == NULL))
    {
        if (btn_label != NULL) free (btn_label);
        if (btn_id    != NULL) free (btn_label);

        return panel;
    }

    ibtn            = 0;
    btn_label[ibtn] = title_str;
    btn_id[ibtn]    = PANEL_TITLE;

    for (iobj = 0; iobj < amgr->gobjCnt; iobj++)
    {
        ibtn++;
        btn_label[ibtn] = amgr->gobj[iobj].label;
        btn_id[ibtn]    = iobj;
    }

    ibtn++;
    btn_label[ibtn] = close_str;
    btn_id[ibtn]    = PANEL_CLOSE;

    pmgr_make_simple (panel, nbtns, btn_label, btn_id, NULL);

    free (btn_label);
    free (btn_id);


    return (panel);
}
/* end PM */



/* 26Nov07  Phil McDonald */
static PMGR  *pmgr_create_objparms (APP_MGR *amgr, int nparms, int parm_id[])
{
    int           width    = 256;
    int           height   = 256;
    unsigned int  panel_bg = PMGR_BLUE2;
    unsigned int  panel_tx = PMGR_BLACK;
    unsigned int  btn_bg[] = { PMGR_PURPLE, PMGR_YELLOW, PMGR_YELLOW };
    unsigned int  btn_tx[] = { PMGR_YELLOW, PMGR_BLUE1,  PMGR_BLUE1  };

    PARM_DATA     parm[PARM_ID_COUNT] =
    {
      PARM_ID_DENSITY, GOBJ_DENSITY, "Density",
      PARM_ID_SCALE,   GOBJ_SCALE,   "Scale",
      PARM_ID_VALUE,   GOBJ_ISOVAL,  "Value",
      PARM_ID_CINT,    GOBJ_CINT,    "Int",
      PARM_ID_CMIN,    GOBJ_CMIN,    "Min",
      PARM_ID_CMAX,    GOBJ_CMAX,    "Max",
      PARM_ID_LEVEL,   GOBJ_VLVL,    "Level",
      PARM_ID_ROW0,    GOBJ_R0,      "Row0",
      PARM_ID_COL0,    GOBJ_C0,      "Col0",
      PARM_ID_ROW1,    GOBJ_R1,      "Row1",
      PARM_ID_COL1,    GOBJ_C1,      "Col1",
    };

    char          title_str[] = "";
    char          close_str[] = "Close";
    char          red_str[]   = "Red";
    char          green_str[] = "Green";
    char          blue_str[]  = "Blue";
    char          alpha_str[] = "Alpha";

    PMGR          *panel;
    int           iparm, ip, ibtn, nbtns, *btn_id;
    char          **btn_label;



    nbtns = nparms + 6;
    panel = pmgr_create_panel (width, height, nbtns,
                               panel_bg, panel_tx, btn_bg, btn_tx,
                               NULL, amgr->tmp->config_parms);
    if (panel == NULL) return NULL;

    btn_label = (char **) malloc (nbtns * sizeof (char *));
    btn_id    = (int *) malloc (nbtns * sizeof (int));
    if ((btn_label == NULL) || (btn_id == NULL))
    {
        if (btn_label == NULL) free (btn_label);
        if (btn_id    == NULL) free (btn_id);

        return panel;
    }


    ibtn            = 0;
    btn_id[ibtn]    = PANEL_TITLE;
    btn_label[ibtn] = title_str;

    for (iparm = 0; iparm < nparms; iparm++)
    {
        for (ip = 0; ip < PARM_ID_COUNT; ip++)
        {
            if (parm[ip].id == parm_id[iparm])
            {
                ibtn++;
                btn_id[ibtn]    = parm[ip].val;
                btn_label[ibtn] = parm[ip].str;
                break;
            }
        }
    }

    ibtn++;
    btn_id[ibtn]    = OBJECT_RED;
    btn_label[ibtn] = red_str;

    ibtn++;
    btn_id[ibtn]    = OBJECT_GREEN;
    btn_label[ibtn] = green_str;

    ibtn++;
    btn_id[ibtn]    = OBJECT_BLUE;
    btn_label[ibtn] = blue_str;

    ibtn++;
    btn_id[ibtn]    = OBJECT_ALPHA;
    btn_label[ibtn] = alpha_str;

    ibtn++;
    btn_id[ibtn]    = PANEL_CLOSE;
    btn_label[ibtn] = strdup ("Close");


    pmgr_make_simple (panel, nbtns, btn_label, btn_id, NULL);


    free (btn_label);
    free (btn_id);


    return panel;
}
/* end PM */



/* 12Nov07  Phil McDonald */
static PMGR *pmgr_create_entry (APP_MGR *amgr)
{
    int           width    = 256;
    int           height   = 128;
    unsigned int  panel_bg = PMGR_BLUE1;
    unsigned int  panel_tx = PMGR_YELLOW;
    unsigned int  btn_bg[] = { PMGR_YELLOW, PMGR_BLUE1,  PMGR_GREY2 };
    unsigned int  btn_tx[] = { PMGR_BLUE1,  PMGR_YELLOW, PMGR_BLACK };

    BTN_DATA pad[NUMPAD_NBUTTONS] =
    {
        NUMPAD_0,     " 0 ",    37,  40,  35,  20, 2,
        NUMPAD_1,     " 1 ",     2, 100,  35,  20, 2,
        NUMPAD_2,     " 2 ",    37, 100,  35,  20, 2,
        NUMPAD_3,     " 3 ",    72, 100,  35,  20, 2,
        NUMPAD_4,     " 4 ",     2,  80,  35,  20, 2,
        NUMPAD_5,     " 5 ",    37,  80,  35,  20, 2,
        NUMPAD_6,     " 6 ",    72,  80,  35,  20, 2,
        NUMPAD_7,     " 7 ",     2,  60,  35,  20, 2,
        NUMPAD_8,     " 8 ",    37,  60,  35,  20, 2,
        NUMPAD_9,     " 9 ",    72,  60,  35,  20, 2,
        NUMPAD_DOT,   " . ",     2,  40,  35,  20, 2,
        NUMPAD_CLEAR, "CLR",    72,  40,  35,  20, 2,
        NUMPAD_ENTER, "ENTER",  40,   5,  55,  20, 2,
        NUMPAD_CLOSE, "CLOSE", 180,   5,  55,  20, 2,
    };

    BTN_DATA disp[ENTRY_NREADONLY] =
    {
        ENTRY_TITLE,   "",     110,  95, 142,  20, 2,
        ENTRY_PARM,    "",     110,  70,  70,  20, 2,
        ENTRY_CUR_VAL, "",     180,  70,  72,  20, 2,
        ENTRY_NEW_VAL, "",     110,  40, 142,  25, 3,
    };

    PMGR        *panel;
    int         idisp, ibtn;



    panel = pmgr_create_panel (width, height, NUMPAD_NBUTTONS,
                               panel_bg, panel_tx, btn_bg, btn_tx,
                               pad, amgr->tmp->config_entry);

    for (idisp = 0; idisp < ENTRY_NREADONLY; idisp++)
    {
        ibtn = panel->buttonCnt++;
        pmgr_makeButton (panel, ibtn,
                         disp[idisp].x, disp[idisp].y,
                         disp[idisp].width, disp[idisp].height,
                         disp[idisp].label, disp[idisp].id,
                         panel->bbg, panel->btx, disp[idisp].nstates);
        pmgr_drawButton (panel, ibtn, 1);
    }

    if ((ibtn = pmgr_find_button (panel, ENTRY_NEW_VAL)) >= 0)
    {
        pmgr_drawButton (panel, ibtn, 2);
    }


    return panel;
}
/* end PM */



/*
 * Render the control panel as a texture map on a polygon.
 */

void pmgr_renderUI (PMGR * panel)
{
    if (panel == NULL) return;

    vrlib_lock_on (panel->lock);

/* 20Oct06  Phil McDonald */
    glEnable (GL_TEXTURE_2D);

    if (panel->tex_id < 0) glGenTextures (1, (GLuint *) &(panel->tex_id));
    glBindTexture (GL_TEXTURE_2D, (GLuint) panel->tex_id);
/* end PM */

    glTexImage2D (GL_TEXTURE_2D, 0, 4, panel->width, panel->height, 0,
                  GL_RGBA, GL_UNSIGNED_BYTE, panel->image);

    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glColor3f (1.0, 1.0, 1.0);
    glBegin (GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
    glVertex3fv (panel->vert[0]);
    glTexCoord2f (1.0, 0.0);
    glVertex3fv (panel->vert[1]);
    glTexCoord2f (1.0, 1.0);
    glVertex3fv (panel->vert[2]);
    glTexCoord2f (0.0, 1.0);
    glVertex3fv (panel->vert[3]);
    glEnd ();
    glDisable (GL_TEXTURE_2D);
    glLineWidth (1.0);

    vrlib_lock_off (panel->lock);


    return;
}


/* 07Nov07  Phil McDonald */
/*
 * SUBROUTINE: Make the PANEL User Interface
 */
void pmgr_initUI (APP_MGR * amgr)
{
    int         nparms, parm_id[7];



    amgr->panel           = NULL;

    amgr->panel_main      = pmgr_create_main (amgr);
    amgr->panel_help      = pmgr_create_help (amgr);
    amgr->panel_objselect = pmgr_create_objselect (amgr);
    amgr->panel_objchange = pmgr_create_objchange (amgr);
    amgr->panel_entry     = pmgr_create_entry (amgr);

/* 26Nov07  Phil McDonald */
    nparms     = 3;
    parm_id[0] = PARM_ID_DENSITY;
    parm_id[1] = PARM_ID_SCALE;
    parm_id[2] = PARM_ID_LEVEL;
    amgr->panel_hwind = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms     = 6;
    parm_id[0] = PARM_ID_DENSITY;
    parm_id[1] = PARM_ID_SCALE;
    parm_id[2] = PARM_ID_ROW0;
    parm_id[3] = PARM_ID_COL0;
    parm_id[4] = PARM_ID_ROW1;
    parm_id[5] = PARM_ID_COL1;
    amgr->panel_vwind = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms       = 2;
    parm_id[0]   = PARM_ID_DENSITY;
    parm_id[1]   = PARM_ID_LEVEL;
    amgr->panel_hstream = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms       = 5;
    parm_id[0]   = PARM_ID_DENSITY;
    parm_id[1]   = PARM_ID_ROW0;
    parm_id[2]   = PARM_ID_COL0;
    parm_id[3]   = PARM_ID_ROW1;
    parm_id[4]   = PARM_ID_COL1;
    amgr->panel_vstream = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms      = 4;
    parm_id[0]  = PARM_ID_CINT;
    parm_id[1]  = PARM_ID_CMIN;
    parm_id[2]  = PARM_ID_CMAX;
    parm_id[3]  = PARM_ID_LEVEL;
    amgr->panel_hslice = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms      = 7;
    parm_id[0]  = PARM_ID_CINT;
    parm_id[1]  = PARM_ID_CMIN;
    parm_id[2]  = PARM_ID_CMAX;
    parm_id[3]  = PARM_ID_ROW0;
    parm_id[4]  = PARM_ID_COL0;
    parm_id[5]  = PARM_ID_ROW1;
    parm_id[6]  = PARM_ID_COL1;
    amgr->panel_vslice = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms       = 1;
    parm_id[0]   = PARM_ID_LEVEL;
    amgr->panel_chslice = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms       = 4;
    parm_id[0]   = PARM_ID_ROW0;
    parm_id[1]   = PARM_ID_COL0;
    parm_id[2]   = PARM_ID_ROW1;
    parm_id[3]   = PARM_ID_COL1;
    amgr->panel_cvslice = pmgr_create_objparms (amgr, nparms, parm_id);

    nparms       = 1;
    parm_id[0]   = PARM_ID_VALUE;
    amgr->panel_isosurf = pmgr_create_objparms (amgr, nparms, parm_id);
/* end PM */

/* 07Nov07  Phil McDonald	TODO:
    amgr->panel_traj   = NULL;
    amgr->panel_volume = NULL;
/* end PM */

    amgr->cur_iobj  = -1;
    amgr->cur_iparm = -1;


    return;
}
/* end PM */



/* 08Nov07  Phil McDonald */
static int pmgr_exec_main (APP_MGR *amgr, int ibtn)
{
    PMGR        *panel;
    int         state, flash;



    panel = amgr->panel;

    state = panel->button[ibtn].state;
    flash = 0;

    switch (panel->button[ibtn].id)
    {
        case MAIN_TITLE:
            if (amgr->nav_style == CAVE5D_OBJECT_NAV)
            {
                amgr->nav_style = CAVE5D_AIRPLANE_NAV;
            }
            else
            {
                amgr->nav_style = CAVE5D_OBJECT_NAV;
            }
            break;

        case MAIN_GOBJ:
            amgr->panel = amgr->panel_objselect;
            return 1;

        case MAIN_STEPS:
            return 1;

        case MAIN_SCALEX:
            amgr->scaleMode = (state) ? 0 : 1;
            break;

        case MAIN_SCALEY:
            amgr->scaleMode = (state) ? 0 : 2;
            break;

        case MAIN_SCALEZ:
            amgr->scaleMode = (state) ? 0 : 3;
            break;

        case MAIN_SLOWER:
            amgr->anim_rate_fps /= 1.2;
            flash = 1;
            break;

        case MAIN_FASTER:
            amgr->anim_rate_fps *= 1.2;
            flash = 1;
            break;

        case MAIN_TIME0:
            amgr->animFlag = 0;
            amgr->curtime  = amgr->startTime;
            pmgr_drawButton (panel, MAIN_ANIMFWD, 0);
            flash = 1;
            break;

        case MAIN_STEPFWD:
            amgr->animFlag = 0;
            amgr->step_fwd = 1;
            pmgr_drawButton (panel, MAIN_ANIMFWD, 0);
            flash = 1;
            break;

        case MAIN_ANIMFWD:
            amgr->animFlag = (!amgr->animFlag);
            break;

        case MAIN_CLOSE:
            amgr->panel = NULL;
            return 1;

        case MAIN_HELP:
            amgr->panel = amgr->panel_help;
            return 1;

        case MAIN_EXIT:
            return -1;
    }

    pmgr_updateButton (panel, ibtn, flash);


    return 1;
}
/* end PM */



/* 09NOv07  Phil McDonald */
static int pmgr_exec_objselect (APP_MGR *amgr, int ibtn)
{
    PMGR        *panel;



    panel = amgr->panel;

    if (panel->button[ibtn].id < 0)
    {
        switch (panel->button[ibtn].id)
        {
            case PANEL_TITLE:
                break;

            case OBJECT_CHANGE:
                amgr->panel = amgr->panel_objchange;
                break;

            case PANEL_CLOSE:
                amgr->panel = amgr->panel_main;
                break;

            default:
                return 0;
        }
        pmgr_updateButton (panel, ibtn, 1);
    }
    else if (panel->button[ibtn].id >= amgr->gobjCnt)
    {
        return 0;
    }
    else
    {
        /* An object has been selected for toggling on/off */
        int         iobj, jobj, jbtn;
/* 21Aug07  Phil McDonald	make sure only one volume is turned on */

        iobj = panel->button[ibtn].id;
        if (amgr->gobj[iobj].grType == VIS5D_VOLUME)
        {
            for (jbtn = 0; jbtn < panel->buttonCnt; jbtn++)
            {
                if ((jbtn != ibtn) && (panel->button[jbtn].id >= 0))
                {
                    jobj = panel->button[jbtn].id;
                    if (amgr->gobj[jobj].grType == VIS5D_VOLUME)
                    {
                        pmgr_drawButton (panel, jbtn, 0);
                        gobj_modify (amgr, jobj, 0);
                    }
                }
            }
        }
/* end PM */

        pmgr_drawButton (panel, ibtn, -1);
        gobj_modify (amgr, iobj, panel->button[ibtn].state);
    }


    return 1;
}
/* end PM */



/* 09NOv07  Phil McDonald */
static int pmgr_exec_objchange (APP_MGR *amgr, int ibtn)
{
    PMGR        *panel;



    panel = amgr->panel;

    if (panel->button[ibtn].id < 0)
    {
        switch (panel->button[ibtn].id)
        {
            case PANEL_TITLE:
                break;

            case PANEL_CLOSE:
                amgr->panel_objparms = NULL;
                amgr->panel          = amgr->panel_objselect;
                break;

            default:
                return 0;
        }
        pmgr_updateButton (panel, ibtn, 1);
    }
    else if (panel->button[ibtn].id >= amgr->gobjCnt)
    {
        return 0;
    }
    else
    {
        /* Switch to the parms panel for this object */
        int         iobj;

        iobj = panel->button[ibtn].id;

        switch (amgr->gobj[iobj].grType)
        {
            case VIS5D_HWIND:
                amgr->panel_objparms = amgr->panel_hwind;
                break;

            case VIS5D_VWIND:
                amgr->panel_objparms = amgr->panel_vwind;
                break;

            case VIS5D_HSTREAM:
                amgr->panel_objparms = amgr->panel_hstream;
                break;

            case VIS5D_VSTREAM:
                amgr->panel_objparms = amgr->panel_vstream;
                break;

            case VIS5D_HSLICE:
                amgr->panel_objparms = amgr->panel_hslice;
                break;

            case VIS5D_VSLICE:
                amgr->panel_objparms = amgr->panel_vslice;
                break;

            case VIS5D_CHSLICE:
                amgr->panel_objparms = amgr->panel_chslice;
                break;

            case VIS5D_CVSLICE:
                amgr->panel_objparms = amgr->panel_cvslice;
                break;

            case VIS5D_ISOSURF:
                amgr->panel_objparms = amgr->panel_isosurf;
                break;

            case VIS5D_TRAJ:
                amgr->panel_objparms = amgr->panel_traj;
                break;

            case VIS5D_VOLUME:
                amgr->panel_objparms = amgr->panel_volume;
                break;

            default:
                return 0;
        }

        if (amgr->panel_objparms == NULL)
        {
            amgr->panel_objparms = NULL;
            amgr->panel          = amgr->panel_objselect;
            return 1;
        }

        amgr->cur_iobj = iobj;

        pmgr_relabel_button (amgr->panel_objparms, PANEL_TITLE,
                             amgr->gobj[amgr->cur_iobj].label);
        gobj_get_parms (amgr, amgr->cur_iobj);

        amgr->panel = amgr->panel_objparms;
    }


    return 1;
}
/* end PM */



/* 12Nov07  Phil McDonald */
static int pmgr_exec_objparms (APP_MGR *amgr, int ibtn)
{
    PMGR        *panel;



    panel = amgr->panel;

    if (panel->button[ibtn].id < 0)
    {
        if (panel->button[ibtn].id == PANEL_CLOSE)
        {
            amgr->panel_objparms = NULL;
            amgr->panel    = amgr->panel_objchange;
        }
        if (panel->button[ibtn].id > OBJECT_RED  ) return 1;
        if (panel->button[ibtn].id < OBJECT_ALPHA) return 1;
    }

    pmgr_updateButton (panel, ibtn, 1);

    /* Switch to the entry panel for this obj/parm */

    amgr->cur_iparm = panel->button[ibtn].id;

    pmgr_relabel_button (amgr->panel_entry, ENTRY_TITLE,
                         amgr->gobj[amgr->cur_iobj].label);
    strcpy (amgr->curValue, panel->button[ibtn].label);
    strcat (amgr->curValue, " :");
    pmgr_relabel_button (amgr->panel_entry, ENTRY_PARM, amgr->curValue);

    pmgr_parm_str (amgr, amgr->cur_iobj, amgr->cur_iparm, 0);

    amgr->panel = amgr->panel_entry;


    return 1;
}
/* end PM */



/* 12Nov07  Phil McDonald */
static int pmgr_exec_entry (APP_MGR *amgr, int ibtn)
{
    PMGR        *panel;



    panel = amgr->panel;

    if (panel->button[ibtn].id < NUMPAD_NBUTTONS)
    {
        int         chr, nchr;

        chr = '\0';
        switch (panel->button[ibtn].id)
        {
            case NUMPAD_CLOSE:
                amgr->panel = amgr->panel_objparms;
                return 1;

            case NUMPAD_CLEAR:
                strcpy (amgr->curValue, "");
                break;

            case NUMPAD_ENTER:
                pmgr_parm_str (amgr, amgr->cur_iobj, amgr->cur_iparm, 1);
                gobj_set_parms (amgr, amgr->cur_iobj);
                break;

            case NUMPAD_0:
                chr = '0';
                break;

            case NUMPAD_1:
                chr = '1';
                break;

            case NUMPAD_2:
                chr = '2';
                break;

            case NUMPAD_3:
                chr = '3';
                break;

            case NUMPAD_4:
                chr = '4';
                break;

            case NUMPAD_5:
                chr = '5';
                break;

            case NUMPAD_6:
                chr = '6';
                break;

            case NUMPAD_7:
                chr = '7';
                break;

            case NUMPAD_8:
                chr = '8';
                break;

            case NUMPAD_9:
                chr = '9';
                break;

            case NUMPAD_DOT:
                chr = '.';
                break;

            default:
                return 0;
        }
        if (chr != '\0')
        {
            nchr = strlen (amgr->curValue);
            if ((nchr+1) < sizeof (amgr->curValue))
            {
                amgr->curValue[nchr++] = chr;
                amgr->curValue[nchr]   = '\0';
            }
        }
        pmgr_updateButton (panel, ibtn, 1);

        pmgr_relabel_button (panel, ENTRY_NEW_VAL, amgr->curValue);
    }


    return 1;
}
/* end PM */



/* 29Nov07  Phil McDonald */
static int pmgr_exec_help (APP_MGR *amgr, int ibtn)
{
    PMGR        *panel;



    panel = amgr->panel;

    switch (panel->button[ibtn].id)
    {
        case PANEL_CLOSE:
            amgr->panel = amgr->panel_main;
            break;

        default:
            return 0;
    }

    pmgr_updateButton (panel, ibtn, 1);


    return 1;
}
/* end PM */



/* 07Nov07  Phil McDonald	moved from cave5d.c */
/*
 * Subroutine - process panel event
 */

int pmgr_queryUI (APP_MGR * amgr, float wand_pos[3], float wand_vec[3])
{
    int         ibtn;
    PMGR        *panel;



    if (amgr->panel == NULL)
    {
        amgr->panel = amgr->panel_main;
        return 0;
    }

    panel = amgr->panel;

    if ((ibtn = pmgr_pickButton (panel, wand_pos, wand_vec)) < 0) return 0;


    if (panel == amgr->panel_main     ) return pmgr_exec_main (amgr, ibtn);
    if (panel == amgr->panel_objselect) return pmgr_exec_objselect (amgr, ibtn);
    if (panel == amgr->panel_objchange) return pmgr_exec_objchange (amgr, ibtn);
    if (panel == amgr->panel_objparms ) return pmgr_exec_objparms (amgr, ibtn);
    if (panel == amgr->panel_entry    ) return pmgr_exec_entry (amgr, ibtn);
    if (panel == amgr->panel_help     ) return pmgr_exec_help (amgr, ibtn);


    return 0;
}
/* end PM */
