/**************************************/
/* bplatform.h - contains functions related to the platform */
/* Author: Feleki Viola */
/**************************************/

#ifndef BPLATFORM_H_INCLUDED
#define BPLATFORM_H_INCLUDED

#include "bball.h"
#include "bcollisions.h"
#include "bmap.h"

typedef struct
{
    int left, top, right, bottom;
} s_platform;

void initPlatform(s_platform *platform, int wx, int wy);
void drawPlatform(s_platform platform);
void movePlatform(s_platform *platform, s_map map);
int touchPlatform(s_ball ball, s_platform platform);

#endif // BPLATFORM_H_INCLUDED
