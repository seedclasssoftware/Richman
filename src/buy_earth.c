/*write@doyourbesthust  gjy*/
#include "buy_earth.h"
#include <stdio.h>



struct Players buy_earth(Players players,Map *map)
{
    int buy_or_not = 0;//1 buy、2 not buy
    char choice = 'n';//y or n
    if((players.position >= 1 && players.position <=13)||(players.position >= 15 && players.position <= 27))
    {//地段1对应位置
        if(players.money >= 200)
        {
            printf("是否购买该地[y/n]?\n");
            scanf("%c",choice);
            if(choice == 'y' || choice == 'Y')
            {
                buy_or_not = 1;
                players.money -= 200;
                //修改地的主人
                map->cells[players.position].owner = players.number;
            }
        }
    }
    else if(players.position >= 29 && players.position <= 34)
    {//地段2对应位置
        if(players.money >= 500)
        {
            printf("是否购买该地[y/n]?\n");
            scanf("%c",choice);
            if(choice == 'y' || choice == 'Y')
            {
                buy_or_not = 1;
                players.money -= 500;
                //修改地的主人
                map->cells[players.position].owner = players.number;
            }
        }
    }
    else if((players.position >= 36 && players.position <= 48)||(players.position >= 50 && players.position <= 62))
    {//地段3对应位置
        if(players.money >= 300)
        {
            printf("是否购买该地[y/n]?\n");
            scanf("%c",choice);
            if(choice == 'y' || choice == 'Y')
            {
                buy_or_not = 1;
                players.money -= 300;
                //修改地的主人
                map->cells[players.position].owner = players.number;
            }
        }
    }
    return players;

}

void test1_buy_earth1_when_money_is_199()
{
  Players player;
  player.money = 199;
  player.position = 1;
  player.number = 1;
  Map *map;
  map_init(map);
  player = buy_earth(player,map);
  printf("test1 result: money:%u,position:%d,map_owener:%d\n",player.money,player.position,map->cells[player.position].owner);
}