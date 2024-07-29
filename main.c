/**
 * @file main.c
 * @author 王一赫 (wyihe5220@gmail.com)
 * @brief KMP算法的实现实验
 * @version 0.1
 * @date 2024-05-31
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
// #include "buy_earth.h"
// #include "help.h"
#include "init_play.h"
#include "interaction.h"
#include "map.h"
// #include "pass_road_money.h"
#include "players.h"
// #include "tool_house.h"
// #include "useprops.h"
// #include "roll.h"
#include "god_appear.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

Map map;

Players players[4];

pPlayers now_user;

extern char temp[70][5];



int main(int argc, char const *argv[], char const *envp[]) {

  SetConsoleOutputCP(
      CP_UTF8); ///< 设置控制台输出编码为UTF-8,很重要,否则中文输出乱码
  /// 无参数,默认为游戏模式
  if (argc == 1) {
    printf("游戏模式\n");
    uint32_t initMoney;

    map_init(&map);
    initialize_Players();
    init_money(&initMoney); // 初始化金钱部分
    selectPlayers(&initMoney);
    map_init(&map);
    int all_players = 0;
    for (int i = 0; i < 4; i++) {
      if (players[i].isPlaying || players[i].isBankrupt) {
        all_players++;
      }
    }
    god_init(all_players);

  } else { /// 有参数,将第一个参数作为json文件地址(绝对路径或者相对路径)
    map_init(&map);
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("文件打开失败\n");
    }
    // 获取文件大小
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // 读取文件内容
    char *json_data = (char *)malloc(size + 1);
    fread(json_data, 1, size, fp);
    json_data[size] = '\0';
    // 关闭文件
    fclose(fp);
    initializePlayers(json_data, players, 4, &map);
    // printf("初始化成功\n");
    free(json_data);
    int all_players = 0;
    for (int i = 0; i < 4; i++) {
      if (players[i].isPlaying || players[i].isBankrupt) {
        all_players++;
      }
    }
    god_init(all_players);
  }
  while (1) {
  for (int i = 0; i < 70; i++) {
    // 如果当前位置没有玩家且没有道具, 则显示地图上的字符
    if (players[0].position != i && players[1].position != i &&
        players[2].position != i && players[3].position != i &&
        map.cells[i].has_tool == 0 && map.cells[i].owner == 0) {
      map.cells[i].show_char = map.cells[i].init_char;
    }
  }
    map_print(&map);
    god_time(&map, players, 4);
    wait_for_input();
  for (int i = 0; i < 70; i++) {
    // 如果当前位置没有玩家且没有道具, 则显示地图上的字符
    if (players[0].position != i && players[1].position != i &&
        players[2].position != i && players[3].position != i &&
        map.cells[i].has_tool == 0 && map.cells[i].owner == 0) {
      map.cells[i].show_char = map.cells[i].init_char;
    }
  }}
  return 0;
}

