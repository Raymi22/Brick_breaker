#include <stdio.h>
#include <graphics.h>
#include "bball.h"

using namespace std;

//////////////////////////////// Ball parameters ///////////////////////////////////////
s_ball ball ={0, 0, 20, 2, -2};
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////// Window parameters //////////////////////////////////
int wx=600, wy=500;
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    initwindow(wx,wy);

    ball.x=getmaxx()/2;
    ball.y=200;

    char c=getch();
    int page=0;

    while (c!='x')
    {
        // page management //
        setactivepage(page);
        cleardevice();
        setvisualpage(1-page);
        /////////////////////

        //draw the filled circle
        drawBall(ball);

        //check for events and change direction
        setSpeed(ball, wx, wy);

        // move the ball
        moveBall(ball);


        // page management //
        page=1-page;
        /////////////////////

        delay(3);
    }
    return 0;
}


