#include "tool_house.h"
#include "players.h"

void test1_tool_house_when_points_is_29()
{
    Players players;
    players.point = 29;
    players = buy_tool(players);
    
}