/**
 * author： 史少博
 */
#include "mine_earth.h"
void mining_for_point(pPlayers player, Cell *cells, int which_earth)
{
    switch (which_earth)
    {
    case 69:
        printf("你通过辛勤的挖矿劳动获得了20点数！\n");
        (*player).point+=20;
        break;
    case 68:
        printf("你通过辛勤的挖矿劳动获得了80点数！\n");
        (*player).point+=80;
        break;
    case 67:
        printf("你通过辛勤的挖矿劳动获得了100点数！\n");
        (*player).point+=100;
        break;
    case 66:
        printf("你通过辛勤的挖矿劳动获得了40点数！\n");
        (*player).point+=40;
        break;
    case 65:
        printf("你通过辛勤的挖矿劳动获得了80点数！\n");
        (*player).point+=80;
        break;
    case 64:
        printf("你通过辛勤的挖矿劳动获得了60点数！\n");
        (*player).point+=60;
        break;

    default:
        break;
    }
}