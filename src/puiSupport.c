/*******************************************************************************
 * Name: puiSupport.c    Config_No: 1.3    Date: 08/01/01
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
 * Compilation Unit:  puiSupport.c     Supporting routines for panelUI
 *
 * pmgr_intersect
 * pmgr_plot
 * pmgr_box
 * pmgr_line
 * pmgr_text
 * pmgr_frame
 * pmgr_drawButton
 * pmgr_makeButton
 * pmgr_pickButton
 * pmgr_config
 *
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "panelUI.h"
#include "puiSupport.h"
#include "font.h"
#include "cave5d.h"

/*
 * Find intersection of wand pointer with control panel and return
 * (x,y) pixel coordinate within panel image.
 */

int pmgr_intersect (PMGR * panel, float pos[3], float dir[3], int *x, int *y)
{
    float       a, b, c, d;
    float       xpos, ypos, zpos;
    float       u[3], v[3], w[3];
    float       ulen, vlen;
    float       ut, vt;

    u[0] = panel->vert[1][0] - panel->vert[0][0];
    u[1] = panel->vert[1][1] - panel->vert[0][1];
    u[2] = panel->vert[1][2] - panel->vert[0][2];
    ulen = sqrt (u[0] * u[0] + u[1] * u[1] + u[2] * u[2]);

    v[0] = panel->vert[3][0] - panel->vert[0][0];
    v[1] = panel->vert[3][1] - panel->vert[0][1];
    v[2] = panel->vert[3][2] - panel->vert[0][2];
    vlen = sqrt (v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

    /* compute plane of the control panel (a,b,c,d) */
    a = u[1] * v[2] - u[2] * v[1];
    b = v[0] * u[2] - v[2] * u[0];
    c = u[0] * v[1] - u[1] * v[0];
    d = panel->vert[0][0] * a + panel->vert[0][1] * b + panel->vert[0][2] * c;
    d = -d;

    /* compute intersection of plane with line (xpos,ypos,zpos) */
    {
        float       numerator = -d - (pos[0] * a + pos[1] * b + pos[2] * c);
        float       denominator = dir[0] * a + dir[1] * b + dir[2] * c;
        float       t = numerator / denominator;

        xpos = pos[0] + t * dir[0];
        ypos = pos[1] + t * dir[1];
        zpos = pos[2] + t * dir[2];
    }

    /* compute coordinate of intersection within plane */
    w[0] = xpos - panel->vert[0][0];
    w[1] = ypos - panel->vert[0][1];
    w[2] = zpos - panel->vert[0][2];

    /* ut = component of w along u in [0,1] */
    ut = (w[0] * u[0] + w[1] * u[1] + w[2] * u[2]) / (ulen * ulen);
    vt = (w[0] * v[0] + w[1] * v[1] + w[2] * v[2]) / (vlen * vlen);

    if (ut >= 0.0 && ut <= 1.0 && vt >= 0.0 && vt <= 1.0)
    {
        *x = (int) (panel->width * ut);
        *y = (int) (panel->height * vt);
        return 1;
    }
    else
    {
        *x = *y = -99;
        return 0;
    }
}



/*
 * Plot one pixel.
 */

void pmgr_plot (PMGR * panel, int x, int y, unsigned int color)
{
    *(panel->image + (panel->width * y + x)) = color;
}



/*
 * Draw a filled box.
 */

void pmgr_box (PMGR * panel, int x, int y, int width, int height,
               unsigned int color)
{
    int         i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            *(panel->image + (panel->width * (y + i) + (x + j))) = color;
        }
    }
}



/*
 * Draw a line.
 */

void pmgr_line (PMGR * panel, int x1, int y1, int x2, int y2,
                unsigned int color)
{
    register int dx, dy, xf, yf, a, b, c, i;

    if (x2 > x1)
    {
        dx = x2 - x1;
        xf = 1;
    }
    else
    {
        dx = x1 - x2;
        xf = -1;
    }

    if (y2 > y1)
    {
        dy = y2 - y1;
        yf = 1;
    }
    else
    {
        dy = y1 - y2;
        yf = -1;
    }

    if (dx > dy)
    {
        a = dy + dy;
        c = a - dx;
        b = c - dx;
        for (i = 0; i <= dx; i++)
        {
            pmgr_plot (panel, x1, y1, color);
            x1 += xf;
            if (c < 0)
            {
                c += a;
            }
            else
            {
                c += b;
                y1 += yf;
            }
        }
    }
    else
    {
        a = dx + dx;
        c = a - dy;
        b = c - dy;
        for (i = 0; i <= dy; i++)
        {
            pmgr_plot (panel, x1, y1, color);
            y1 += yf;
            if (c < 0)
            {
                c += a;
            }

            else
            {
                c += b;
                x1 += xf;
            }
        }
    }
}



/*
 * Display text on panel
 */

void pmgr_text (PMGR * panel, int x, int y, int width, int height,
                char *str, unsigned int color)
{
    char       *ch;
    int         i, row, col, byte, xmax, ymax;

    xmax = x + width;
    ymax = y + height;
    for (ch = str; *ch; ch++)
    {
        /* find the char */
        for (i = 0; i < 255; i++)
        {
            if (bitmapFont[i][0] == *ch)
            {
                /* found the char */
                if (((x+8) > xmax) || ((y+12) > ymax)) return;
                for (row = 0; row < 13; row++)
                {
                    byte = bitmapFont[i][row + 1];
                    for (col = 0; col < 8; col++)
                    {
                        if (byte & (128 >> col))
                        {
                            pmgr_plot (panel, x + col, y + row, color);
                        }
                    }
                }
                break;
            }
            else if (bitmapFont[i][0] == 255)
            {
                break;
            }
        }
        x += 9;
    }
}



/*
 * Draw a shadowed box.
 */

void pmgr_frame (PMGR * panel, int x, int y, int width, int height, int raised)
{
    unsigned int color1, color2;

    if (raised)
    {
        color1 = PMGR_WHITE;
        color2 = PMGR_GREY1;
    }
    else
    {
        color1 = PMGR_GREY1;
        color2 = PMGR_WHITE;
    }

    width--;
    height--;

    pmgr_line (panel, x, y, x + width, y, color2);
    pmgr_line (panel, x + width, y, x + width, y + height, color2);
    pmgr_line (panel, x, y + height, x + width, y + height, color1);
    pmgr_line (panel, x, y, x, y + height, color1);
}



/* 08Nov07  Phil McDonald	reworked */
/*
 * Draw a button.
 */

void pmgr_drawButton (PMGR * panel, int ibtn, int state)
{
    int         newState;

    if ((ibtn < 0) || (ibtn >= panel->buttonCnt)) return;

    /* increments button.state by 1 if state < 0 */
    if (state < 0)
    {
        newState = panel->button[ibtn].state + 1;
        if (newState >= panel->button[ibtn].maxState) newState = 0;
    }
    /* sets button.state to state if state >=0 */
    else
    {
        newState = CLAMP (state, 0, (panel->button[ibtn].maxState - 1));
    }

    panel->button[ibtn].state = newState;

    pmgr_box (panel, panel->button[ibtn].x, panel->button[ibtn].y,
              panel->button[ibtn].width, panel->button[ibtn].height,
              panel->button[ibtn].bgColor[newState]);

    if (panel->button[ibtn].maxState > 1)
    {
        pmgr_frame (panel, panel->button[ibtn].x, panel->button[ibtn].y,
                    panel->button[ibtn].width, panel->button[ibtn].height, 0);
    }

    pmgr_text (panel, panel->button[ibtn].x + 5, panel->button[ibtn].y + 1,
               panel->button[ibtn].width - 5, panel->button[ibtn].height - 1,
               panel->button[ibtn].label,
               panel->button[ibtn].textColor[newState]);


    return;
}
/* end PM */



/*
 * Make a control panel button.
 */

void pmgr_makeButton (PMGR * panel, int bIdx, int x, int y, int width,
                      int height, char *label, int id, unsigned int bgColor[3],
                      unsigned int textColor[3], int maxState)
{
    int         cIdx;

    if (maxState > BUTTON_MAXSTATE)
    {
/* 05Nov07  Phil McDonald */
        fprintf (stderr, "CAVE5D: panel: ERROR: only %d %s.  %d %s.\n",
                BUTTON_MAXSTATE, "states supported",  maxState, "is invalid");
/* end PM */
        exit (EXIT_FAILURE);
    }
/* 21Aug07  Phil McDonald */
    panel->button[bIdx].state    = 0;
/* end PM */
    panel->button[bIdx].maxState = maxState;
    panel->button[bIdx].x        = x;
    panel->button[bIdx].y        = y;
    panel->button[bIdx].width    = width;
    panel->button[bIdx].height   = height;
    panel->button[bIdx].id       = id;
    for (cIdx = 0; cIdx < BUTTON_MAXSTATE; cIdx++)
    {
        panel->button[bIdx].bgColor[cIdx]   = bgColor[cIdx];
        panel->button[bIdx].textColor[cIdx] = textColor[cIdx];
    }
    strcpy (panel->button[bIdx].label, label);
    pmgr_drawButton (panel, bIdx, 0);
}



/* 08Nov07  Phil McDonald	reworked */
/*
 * Return the ID of the button under coordinate (x,y) or 0 if none.
 */

int pmgr_pickButton (PMGR *panel, float wand_pos[], float wand_dir[])
{
    int         ibtn, x, y;

    if (!pmgr_intersect (panel, wand_pos, wand_dir, &x, &y)) return -1;

    for (ibtn = 0; ibtn < panel->buttonCnt; ibtn++)
    {
        if ((x >= panel->button[ibtn].x) &&
            (x < panel->button[ibtn].x + panel->button[ibtn].width) &&
            (y >= panel->button[ibtn].y) &&
            (y < panel->button[ibtn].y + panel->button[ibtn].height))
        {
            return ibtn;
        }
    }


    return -1;
}
/* end PM */



/* 08Nov07  Phil McDonald */
void pmgr_updateButton (PMGR *panel, int ibtn, int flash)
{
    if ((ibtn < 0) || (ibtn >= panel->buttonCnt)) return;

    pmgr_drawButton (panel, ibtn, -1);

    if (flash)
    {
        usleep (40000);
        pmgr_drawButton (panel, ibtn, -1);
    }


    return;
}
/* end PM */



/*
 * Read params from panel config file
 */

void pmgr_config (PMGR * panel, char *fname,
                  unsigned int color_bg[], unsigned int color_tx[])
{
    FILE       *fp;
    char        str[256], keyword[256], dummy[64];
    int         i, red, green, blue;
    float       min, max;

/* 05Nov07  Phil McDonald */
    for (i = 0; i < BUTTON_MAXSTATE; i++)
    {
        panel->bbg[i] = color_bg[i];
        panel->btx[i] = color_tx[i];
    }

    panel->vert[0][0] = -2.0;
    panel->vert[0][1] = 1.5;
    panel->vert[0][2] = -4.0;
    panel->vert[1][0] = 2.0;
    panel->vert[1][1] = 1.5;
    panel->vert[1][2] = -4.0;
    panel->vert[2][0] = 2.0;
    panel->vert[2][1] = 5.5;
    panel->vert[2][2] = -4.0;
    panel->vert[3][0] = -2.0;
    panel->vert[3][1] = 5.5;
    panel->vert[3][2] = -4.0;

    if ((fname == NULL) || (fname[0] == '\0')) return;

    if ((fp = fopen (fname, "r")) == NULL)
    {
        fprintf (stderr, "CAVE5D: panel: ERROR: file %s not found.\n", fname);
        exit (EXIT_FAILURE);
    }
    fprintf (stderr, "CAVE5D: panel: processing configuration file %s\n",
             fname);
/* end PM */

    while (fgets (str, sizeof (str), fp) == str)
    {
        sscanf (str, "%s", keyword);

/* 07Dec05  Phil McDonald */
        if (strcmp (keyword, "BGCOLOR") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->bgColor = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "TXCOLOR") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->textColor = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "BUTTON_BG1") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->bbg[0] = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "BUTTON_BG2") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->bbg[1] = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "BUTTON_BG3") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->bbg[2] = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "BUTTON_TX1") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->btx[0] = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "BUTTON_TX2") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->btx[1] = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "BUTTON_TX3") == 0)
        {
            sscanf (str, "%s %d %d %d", dummy, &red, &green, &blue);
            panel->btx[2] = COLOR (red, green, blue);
            continue;
        }
        if (strcmp (keyword, "XRANGE") == 0)
        {
            sscanf (str, "%s %f %f", dummy, &min, &max);
            panel->vert[0][0] = min;
            panel->vert[1][0] = max;
            panel->vert[2][0] = max;
            panel->vert[3][0] = min;
            continue;
        }
        if (strcmp (keyword, "YRANGE") == 0)
        {
            sscanf (str, "%s %f %f", dummy, &min, &max);
            panel->vert[0][1] = min;
            panel->vert[1][1] = min;
            panel->vert[2][1] = max;
            panel->vert[3][1] = max;
            continue;
        }
        if (strcmp (keyword, "ZRANGE") == 0)
        {
            sscanf (str, "%s %f %f", dummy, &min, &max);
            panel->vert[0][2] = max;
            panel->vert[1][2] = max;
            panel->vert[2][2] = min;
            panel->vert[3][2] = min;
            continue;
        }
/* end PM */
    }
    fclose (fp);
}
