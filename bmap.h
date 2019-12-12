/**************************************/
/* bball.h - contains functions related to the scoreboard and score calculation. */
/* Author: Nemeth Raymond */
/**************************************/

#ifndef BMAP_H_INCLUDED
#define BMAP_H_INCLUDED

#include "bball.h"
#include "bcollisions.h"

typedef struct
{
    int left, top, right, bottom;
}s_map;

void drawMap(s_map map);

int touchMap(s_map map, s_ball ball);

void initMap(s_map *map, int wx, int wy);

#endif // BMAP_H_INCLUDED
