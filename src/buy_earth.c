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

// 传参Player结构体变量地址，需要以&Players的格式，不能直接穿指针；传参需要用&Map的格式，不能直接传入指针。
// 传参例子，已声明Players player1和Map
// map，调用函数应为buy_earth(&player1,&map)；
void buy_earth(pPlayers players, Map *map) {
  int err = 0;
  char choice = 'n'; // y or n
  while (1) {
  back:
    err = 0;
    if ((players->position >= 1 && players->position <= 13) ||
        (players->position >= 15 && players->position <= 27)) { // 地段1对应位置
      if (players->money >= 200) {
        printf("是否购买该地[y/n]?\n");
        choice = getchar();
        if (choice == 'y' && getchar() == '\n') {
          players->money -= 200;
          // 修改地的主人
          map->cells[players->position].owner = players->number;
          break;
        } else if (choice == 'n' && getchar() == '\n') {
          break;
        } else {
          err = 1;
        }
      }
    } else if (players->position >= 29 &&
               players->position <= 34) { // 地段2对应位置
      if (players->money >= 500) {
        printf("是否购买该地[y/n]?\n");
        scanf("%c", choice);
        if (choice == 'y' && getchar() == '\n') {
          players->money -= 500;
          // 修改地的主人
          map->cells[players->position].owner = players->number;
          break;
        } else if (choice == 'n' && getchar() == '\n') {
          break;
        } else {
          err = 1;
        }
      }
    } else if ((players->position >= 36 && players->position <= 48) ||
               (players->position >= 50 &&
                players->position <= 62)) { // 地段3对应位置
      if (players->money >= 300) {
        printf("是否购买该地[y/n]?\n");
        scanf("%c", choice);
        if (choice == 'y' && getchar() == '\n') {
          players->money -= 300;
          // 修改地的主人
          map->cells[players->position].owner = players->number;
          break;
        } else if (choice == 'n' && getchar() == '\n') {
          break;
        } else {
          err = 1;
        }
      }
    }
    if (err == 1) {
      printf("错误输入\n");
      while ((choice = getchar()) != EOF && choice != '\n'); // 清理错误输入的缓冲区
      goto back;
    }
  }
  return;
}

