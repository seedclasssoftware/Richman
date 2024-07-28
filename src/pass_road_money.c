/**
 * author： 史少博
 */

#include "pass_road_money.h"

void pay_money(pPlayers player, Cell *cells, pPlayers now_user_for_pay_money, Map *map) 
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
                printf("您需要支付租金 %d 元\n",pay_money);
                (*now_user_for_pay_money).money-=pay_money;
                player[(*cells).owner-1].money+=pay_money;
            }
            //现有钱数少于支付钱数
            else
            {
                int is_anyone_there=0;
                (*now_user_for_pay_money).isBankrupt=1;
                printf("您已破产，感觉挺惨！\n");
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
                }

                //如果当前位置没有人
                if(is_anyone_there=0)
                {
                    (*cells).show_char=(*cells).kind+48;
                }

                //将破产角色地产清空
                for(int i=0;i<=69;i++)
                {
                    if((*map).cells[i].owner==(*now_user_for_pay_money).number)
                    {
                        (*map).cells[i].owner=0;
                        (*map).cells[i].kind=0;
                        (*map).cells[i].show_char='0';
                    }
                }
                int playing_num=0,dead_num=0,final_role_num=0;
                for(int i=0;i<=3;i++)
                {
                    if(player[i].isPlaying==1) playing_num++;
                    if(player[i].isBankrupt==1) dead_num++;
                    if(player[i].isPlaying==1 && player[i].isBankrupt==0) final_role_num=player[i].number;
                }
                if(1==playing_num-dead_num)
                {
                    switch(final_role_num)
                    {
                        case 1:
                            printf("钱夫人胜利!\n");
                            break;
                        case 2:
                            printf("阿土伯胜利!\n");
                            break;
                        case 3:
                            printf("孙小美胜利!\n");
                            break;
                        case 4:
                            printf("金贝贝胜利!\n");
                            break;
                        default:
                            printf("final_role_num error!\n");
                    }
                    map_print(map);
                    printf("游戏结束！\n");
                    exit(0);
                }
            }
        }
    }
}