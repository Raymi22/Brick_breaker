/**************************************/
/* bball.h - contains functions related to the scoreboard and score calculation. */
/* Author: Nemeth Raymond */
/**************************************/

#ifndef BSCORE_H_INCLUDED
#define BSCORE_H_INCLUDED

#include "bbrick2.h"

int getScore(s_brick wall[4][5]);
void drawScoreboard(s_brick wall[4][5], int s);

#endif // BSCORE_H_INCLUDED
