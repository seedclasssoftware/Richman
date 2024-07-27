/**
 * @file buy_earth.c
 * @author 古静怡 (2856514560@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-07-27
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
#include "buy_earth.h"
#include <stdio.h>

int ask_to_buy(int price) {
  char input[10]; // 假设输入不会超过10个字符
  printf("是否购买该地 (价格: %d) [y/n]?\n", price);
  if (fgets(input, sizeof(input), stdin) != NULL) {
    if (input[0] == 'y' || input[0] == 'Y') {
      return 1; // 返回1表示选择了'yes'
    }
  }
  return 0; // 返回0表示选择了'no'或其他
}

/**
 * @brief 购买地皮
 *
 * @param player  玩家
 * @param map 地图
 */
void buy_earth(pPlayers player, Map *map) {
  int price = 0;
  int position = player->position;

  if ((position >= 1 && position <= 13) || (position >= 15 && position <= 27)) {
    price = 200;
  } else if (position >= 29 && position <= 34) {
    price = 500;
  } else if ((position >= 36 && position <= 48) ||
             (position >= 50 && position <= 62)) {
    price = 300;
  }

  if (price > 0 && player->money >= price) {
    if (ask_to_buy(price)) {
      player->money -= price;
      map->cells[position].owner = player->number;
      printf("购买成功！\n");
    } else {
      printf("取消购买。\n");
    }
  }
}