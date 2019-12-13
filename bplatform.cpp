#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"

void movePlatform( s_platform *platform, s_map map )    //function of moving the platform
{
    char key;
     if (kbhit())   //verify the key buffer (if was typed any key)
        {
        key = toupper(getch());     //upper the typed key

        if (key==KEY_LEFT){          //moving to left
            if (platform->left>map.left){
                platform->left=platform->left-20;                  //move 20 pixel in left direction
                platform->right=platform->right-20;
            }
            else{
                platform->left=platform->left;                  //touch the map on left side ,no moving
                platform->right=platform->right;
            }
        }

        if (key==KEY_RIGHT){             //moving to right
            if (platform->right<map.right){
                platform->left=platform->left+20;                 //move 20 pixel in right direction
                platform->right=platform->right+20;
            }
            else{
                platform->left=platform->left;                  //touch the map on right side ,no moving
                platform->right=platform->right;
            }
        }
    }
}

void drawPlatform( s_platform platform ) //function of drawing the platform
{
    setfillstyle(SOLID_FILL,3);       //will be colored by green
    bar( platform.left, platform.top, platform.right, platform.bottom );
}

int touchPlatform(s_ball ball, s_platform platform)
{
    if( (touchCorner(ball, platform.left, platform.top)==1) || (touchCorner(ball, platform.right, platform.top)==1) ) return 1; //corner
    if( touchVerticalLine(ball, platform.left, platform.top ,platform.left ,platform.bottom)==1 ||
       touchVerticalLine(ball, platform.right, platform.top ,platform.right ,platform.bottom)==1) return 2; //vertical
    if( touchHorizontalLine(ball, platform.left, platform.top ,platform.right ,platform.top)==1) return 3; //horizontal
    return 0;
}

void initPlatform(s_platform *platform, int wx, int wy) //give the initial values of the platform: length=80,width=25,margin=5
{
    platform->left=wx/2-40;
    platform->top=wy-5-25;
    platform->right=wx/2+40;
    platform->bottom=wy-5;
}
