/**
 * @file tool_house.c
 * @author 古静怡 (2856514560@qq.com)
 * @brief
 * @brief
 * @version 0.1
 * @date 2024-07-27
 *
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
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *
 *   Unless required by applicable law or agreed to in writing,
 *   software distributed under the License is distributed on an
 *   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *   KIND, either express or implied.  See the License for the
 *   specific language governing permissions and limitations
 *   under the License.
 *
 *
 */
#include "tool_house.h"
#include "players.h"
#include <stdio.h>

// 传参Players类型变量的地址，以&Players形式传参。例子：已初始化变量Players
// player,调用函数buy_tool(&player)；
void buy_tool(pPlayers player) {
  if (player->point >= 30) {
    char choice_tool = 'F';
    printf("欢迎光临道具屋，请选择您所需要的道具：1.路障 2.机器娃娃 F.退出\n");
    choice_tool = getchar();
    while (choice_tool != 'F') {
      int tool_number = player->block + player->robot;
      if (tool_number == 10) { // 道具数为10
        printf("您的道具数已达最大值，不能购买.\n");
        break;
      } else {
        if (choice_tool == '2' && getchar() == '\n') { // 选择机器娃娃
          player->point -= 30;
          player->robot++;
          printf("你已购买机器娃娃。\n");
        }
        else if (choice_tool == '1' && getchar() == '\n') { // 选择路障
          if (player->point >= 50) {
            player->point -= 50;
            player->block++;
            printf("你已购买路障。\n");
          } else {
            printf("您当前剩余的点数为%u，不足以购买路障道具。\n",
                   player->point);
          }
        }else { // 输入错误
          printf("输入错误\n");
          while ((choice_tool = getchar()) != '\n' && choice_tool != EOF);
        }
      }
      if (player->point < 30)
      {
        printf("您所剩点数不足买任何道具，自动退出。\n");
        break;
      }
      printf("请选择您所需要的道具：1.路障 2.机器娃娃 F.退出\n");
      choice_tool = getchar();
    }
    getchar();//去除回车
  } else { // 点数不足
    printf("点数不足.\n");
  }
  return;
}

// 自测试
void test_tool_house() {
  Players players;
  players.point = 50;
  players.block = 0;
  players.robot = 9;
  buy_tool(&players);
  int tool_number = players.robot + players.block + players.bomb;
  printf("test_result:point:%u,tool_number:%d\n", players.point, tool_number);
}