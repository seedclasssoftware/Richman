#include "pass_road_money.h"

void pay_money(pPlayers player, Cell *cells, int now_user)
{
    if((*cells).owner!=0 && (*cells).owner!=player[now_user-1].number && (*cells).kind!=4)
    {
        if(player[now_user-1].god>0)
        {
            printf("财神显灵，租金全免!\n");
            return;
        }
        else if(player[(*cells).owner-1].hospital>0)
        {
            printf("地主正在医院，你幸运的免去了租金！\n");
            return;
        }
        else if(player[(*cells).owner-1].prison>0)
        {
            printf("地主正在监狱，你幸运的免去了租金！\n");
            return;
        }
        else
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
            else
            {
                //等待破产模块
            }
        }
    }
}