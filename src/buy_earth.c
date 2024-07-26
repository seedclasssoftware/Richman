#include "players.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t buy_earth(Players players)
{
    return 0;

}

void test1_buy_earth1_when_money_is_200()
{
    Players players;
    players.money = 200;
    players.name = "QIAN_Madam";
    players.number = 1;
    players.position = 1;
    players.money = buy_earth(players);
    if(players.money == 0)
    {
        printf("1Success.");
    }
    else {
        printf("1Failed.");
    }
}

void test2_buy_earth2_when_money_is_200()
{
    Players players;
    players.money = 200;
    players.name = "QIAN_Madam";
    players.number = 1;
    players.position = 29;
    
}