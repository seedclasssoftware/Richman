/**
 * @file sell_house.c
 * @author 王一赫 (wyihe5220@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-28
 *
 * @copyright copyright (c) 2024
 *   Licensed to the Apache Software Foundation (ASF) under one
 *   or more contributor license agreements.  See the NOTICE file
 *   distributed with this work for additional information
 *   regarding copyright ownership.  The ASF licenses this file
 *   to you under the Apache License, Version 2.0 (the
 *   "License"); you may not use this file except in compliance
 *   with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing,
 *   software distributed under the License is distributed on an
 *   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *   KIND, either express or implied.  See the License for the
 *   specific language governing permissions and limitations
 *   under the License.
 *
 */

#include "sell_house.h"
#include "map.h"
#include "players.h"
#include <stdio.h>


void sell_house(Players *player, Map *map, int house) // 卖房子函数
{

  int own = 0;
  for (int i = 0; i < 70; i++) {
    if (map->cells[i].owner == player->number) {
      own++;
    }
  }
  if (own) {
    if (map->cells[house].owner == player->number) {
      if (map->cells[house].rank == 1) {
        player->money += 2 * 200 * (map->cells[house].kind + 1);
        map->cells[house].kind = 0;
        map->cells[house].owner = 0;
        map->cells[house].init_char = '0';
        map->cells[house].show_char = '0';
        printf("卖掉了%d的房子！\n", house);
      } else if (map->cells[house].rank == 2) {
        player->money += 2 * 500 * (map->cells[house].kind + 1);
        map->cells[house].kind = 0;
        map->cells[house].owner = 0;
        map->cells[house].init_char = '0';
        map->cells[house].show_char = '0';
        printf("卖掉了%d的房子！\n", house);
      } else if (map->cells[house].rank == 3) {
        player->money += 2 * 300 * (map->cells[house].kind + 1);
        map->cells[house].kind = 0;
        map->cells[house].owner = 0;
        map->cells[house].init_char = '0';
        map->cells[house].show_char = '0';
        printf("卖掉了%d的房子！\n", house);
      } else {
        printf("you do not have any house\n");
      }

    } else {
      printf("这栋房子不属于您！\n");
    }
  } else {
    printf("你没有房子可卖！\n");
  }

  
}
