#ifndef EARTHUP_H
#define EARTHUP_H

#include "map.h"
#include "players.h"
#include <stdio.h>

void earth_up(pPlayers player, Cell *cells);
//传入参数：当前角色指针，当前全体地图指针
//功能：判断角色是否可以升级地产并进行升级

int is_your_earth(Players player, Cell *cells);
//传入参数：当前角色指针，当前全体地图指针
//功能：判断是否为当前角色的土地
//返回值：1 为当前角色土地; 0 不为当前角色土地

void test_earth_up(void);

#endif