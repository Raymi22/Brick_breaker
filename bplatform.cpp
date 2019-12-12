#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"



void movePlatform( s_platform *platform, s_map map )    //platform mozgatasa fuggveny
{
    char key;
     if (kbhit())   //ha le volt utve egy billentyu
        {
        key = toupper(getch());     //leutott billentyut nagybetusra alakit

        if (key==KEY_LEFT){          //balra mozgataskor
            if (platform->left>map.left){
                platform->left=platform->left-20;                  //mozog 5 pixelt balra
                platform->right=platform->right-20;
            }
            else{
                platform->left=platform->left;                  //mozog 5 pixelt balra
                platform->right=platform->right;
            }
        }

        if (key==KEY_RIGHT){             //jobbra mozgataskor
            if (platform->right<map.right){
                platform->left=platform->left+20;
                platform->right=platform->right+20;
            }
            else{
                platform->left=platform->left;                  //mozog 5 pixelt balra
                platform->right=platform->right;
            }
        }
    }
}

void drawPlatform( s_platform platform ) //platform rajzolasa fuggveny
{
    setfillstyle(SOLID_FILL,3); //all will be colored by green hopsz
    bar( platform.left, platform.top, platform.right, platform.bottom );
}

///viola
int touchPlatform(s_ball ball, s_platform platform)
{
    if( (touchCorner(ball, platform.left, platform.top)==1) || (touchCorner(ball, platform.right, platform.top)==1) ) return 1; //corner
    if( touchVerticalLine(ball, platform.left, platform.top ,platform.left ,platform.bottom)==1 ||
       touchVerticalLine(ball, platform.right, platform.top ,platform.right ,platform.bottom)==1) return 2; //vertical
    if( touchHorizontalLine(ball, platform.left, platform.top ,platform.right ,platform.top)==1) return 3; //horizontal
    return 0;
}
//int touchPlatform
//sarok,ugyanugy vissza return 1;
//egy eset a ket olalanak megy neki return 2
//egy eset pedig ha felulrol utkozik return 3;
