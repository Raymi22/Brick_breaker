#ifndef BMAP_H_INCLUDED
#define BMAP_H_INCLUDED

typedef struct
{
    int left, top, right, bottom;
}s_map;

void drawMap(s_map map);

int touchBorder1()
//int getScore(s_brick brick[20]);


#endif // BMAP_H_INCLUDED
