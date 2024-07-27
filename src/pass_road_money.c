#include "pass_road_money.h"

void pay_money(pPlayers player, Cell *cells)
{
    if((*cells).owner!=0 && (*cells).owner!=(*player).number && (*cells).kind!=4)
    {
        int pay_money;
        switch((*cells).rank)
        {
            case 1:
                pay_money=((*cells).kind+1)*100;
                break;
            case 2:
                pay_money=((*cells).kind+1)*250;
                break;
            case 3:
                pay_money=((*cells).kind+1)*150;
                break;
            default:
                printf("rank num error!\n");
                break;
        }
        if((*player).money>=pay_money)
        {
            (*player).money-=pay_money;
            
        }
    }
}