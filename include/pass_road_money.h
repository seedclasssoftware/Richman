/**
 * author： 史少博
 */
#ifndef PASS_ROAD_MONEY_H
#define PASS_ROAD_MONEY_H

#include "map.h"
#include "players.h"
#include <stdio.h>

void pay_money(pPlayers player, Cell *cells, pPlayers now_user_for_pay_money);
//传入参数：当前所有玩家的数组、当前所在地图格的地址(eg: &cells[63] )、当前角色指针
//功能：判断是否需要支付过路费以及是否会破产

void test_pay_money(void);
//功能：简单测试过路费功能
#endif