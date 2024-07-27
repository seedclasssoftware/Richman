/**
 * author： 史少博
 */
#include "mine_earth.h"
void mining_for_point(pPlayers player, Cell *cells, int which_earth)
{
    switch (which_earth)
    {
    case 69:
        (*player).point+=20;
        break;
    case 68:
        (*player).point+=80;
        break;
    case 67:
        (*player).point+=100;
        break;
    case 66:
        (*player).point+=40;
        break;
    case 65:
        (*player).point+=80;
        break;
    case 64:
        (*player).point+=60;
        break;

    default:
        break;
    }
}