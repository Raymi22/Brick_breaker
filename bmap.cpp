#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"
#include "bbrick.h"


void drawMap(s_map map)
{
    //(0, 0, map.right, map.top);
    line(map.left, map.top, map.left, map.bottom);
    line(map.right, map.top, map.right, map.bottom);
}


