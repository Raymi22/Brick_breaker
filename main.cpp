#include <stdio.h>
#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"

using namespace std;
////////////////////////////////// Window parameters //////////////////////////////////
int wx=500, wy=600;
///////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// Object parameters ///////////////////////////////////////
s_ball ball ={0, 0, 20, 2, -2};
s_platform platform ={wx/2-40, wy-5-25, wx/2+40, wy-5};
s_map map={0, 50, wx, wy};
int ps=2;
////////////////////////////////////////////////////////////////////////////////////////




int main()
{
    initwindow(wx,wy);

    ball.x=getmaxx()/2;
    ball.y=200;
    platform ={wx/2-40, wy-5-25, wx/2+40, wy-5};
    platform.left=wx/2-40;
    platform.top=wy-5-25;
    platform.right=wx/2+40;
    platform.bottom=wy-5;
    char c=getch();
    int page=0;

    while (c!='x')
    {
        // page management //
        setactivepage(page);
        cleardevice();
        setvisualpage(1-page);
        /////////////////////

        rectangle(0, 0, wx, map.top);

        //draw the filled circle
        drawBall(ball);

        bar (platform.left, platform.top, platform.right, platform.bottom);


        //check for events and change direction
        setSpeed(ball, map, platform);

        // move the ball
        moveBall(ball);

        if (GetAsyncKeyState(VK_RIGHT)) {platform.left+=ps; platform.right+=ps;}
        if (GetAsyncKeyState(VK_LEFT)) {platform.left-=ps; platform.right-=ps;}



        // page management //
        page=1-page;
        /////////////////////

        delay(3);
    }
    return 0;
}


