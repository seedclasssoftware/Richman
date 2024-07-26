#include "players.h"

uint32_t buy_earth(Players players)
{
    return 0;

}

void test_buy_earth_when_money_is_200()
{
    Players players;
    players.money = 200;
    players.name = "QIAN_Madam";
    players.number = 1;
    players.position = 1;
    players.money = buy_earth(players);
    if(players.money == 0)
    {
        printf("Success.")
    }
}