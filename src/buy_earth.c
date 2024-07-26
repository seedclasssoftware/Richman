/*write@doyourbesthust  gjy*/
#include "buy_earth.h"
#include <stdio.h>
#include <stdlib.h>

struct Players buy_earth(Players players)
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
                //调用会修改地图0的颜色的函数，
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
                //调用会修改地图0的颜色的函数
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
                //调用会修改地图0的颜色的函数
            }
        }
    }
    return players;

}

/*void test1_buy_earth()
{
    Players players;
    players.money = 200;
    players.name = "QIAN_Madam";
    players.number = 1;
    players.position = 1;
    players = buy_earth(players);
    //int should_money = players.money-500;
    //if(players.money == should_money)
    //{
    //    printf("Success.");
    //}
    //else {
    //    printf("Failed.");
    //}
}*/

