/**
 * author： 史少博
 */
#include "pass_road_money.h"

void pay_money(pPlayers player, Cell *cells, pPlayers now_user_for_pay_money)
{
    //判断不为特殊建筑且这个地的所有者不为当前角色
    if((*cells).owner!=0 && (*cells).owner!=(*now_user_for_pay_money).number && (*cells).kind!=4)
    {
        if((*now_user_for_pay_money).god>0)
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
            //现有钱数大于需支付钱数
            if((*now_user_for_pay_money).money>=pay_money)
            {
                (*now_user_for_pay_money).money-=pay_money;
                player[(*cells).owner-1].money+=pay_money;
            }
            //现有钱数少于支付钱数
            else
            {
                int is_anyone_there=0;
                (*now_user_for_pay_money).isBankrupt=1;
                for(int i=0;i<=3;i++)
                {
                    //如果当前位置有人并且这个人不是当前角色
                    if(player[i].position==(*now_user_for_pay_money).position && player[i].number!=(*now_user_for_pay_money).number)
                    {
                        //根据当前位置的人重置地图符号
                        switch(player[i].number)
                        {
                            case 1:
                                (*cells).show_char='Q';
                                is_anyone_there=1;
                                break;
                            case 2:
                                (*cells).show_char='A';
                                is_anyone_there=1;
                                break;
                            case 3:
                                (*cells).show_char='S';
                                is_anyone_there=1;
                                break;
                            case 4:
                                (*cells).show_char='J';
                                is_anyone_there=1;
                                break;
                            default:
                                printf("player_number_in_no_money_wrong!\n");
                                break;
                        }
                    }
                    if(is_anyone_there=0)
                    {
                        (*cells).show_char=(*cells).kind+48;
                    }
                }

                //等待破产模块
            }
        }
    }
}