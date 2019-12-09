#ifndef BPLATFORM_H_INCLUDED
#define BPLATFORM_H_INCLUDED

#include "bball.h"
#include "bcollisions.h"
#include "bmap.h"

typedef struct
{
    int left, top, right, bottom;
} s_platform;

//int touchPlatform(s_ball ball, s_platform platform);

void drawPlatform(s_platform platform);
void movePlatform(s_platform &platform, s_map map);
///viola
int touchPlatform(s_ball ball, s_platform platform);

#endif // BPLATFORM_H_INCLUDED
