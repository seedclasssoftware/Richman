/**
 * @file interaction.c
 * @author 王一赫 (wyihe5220@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-26
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
#include "interaction.h"
#include "players.h"
#include "roll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern pPlayers now_user;

// 退出游戏的实现
void exit_game() {
  printf("正在退出游戏...\n");

  // 显示退出信息
  printf("游戏已退出。感谢您的参与！\n");

  // 退出程序
  exit(0);
}
/**
 * @brief 处理用户输入的命令
 *
 * @param command 用户输入的命令
 */
void handle_command(const char *command) {
  if (strcmp(command, "Roll") == 0 || strcmp(command, "roll") == 0) {
    int roll = roll_num();
    printf("骰子点数为：%d\n", roll);
    change_position(now_user, roll);
    eventJudge(now_user);
  // 切换当前玩家
  flag:
    if (players[(now_user->number) % 4].hospital == 0 ||
        players[(now_user->number) % 4].prison == 0 ||
        players[(now_user->number) % 4].isPlaying == 1 ||
        players[(now_user->number) % 4].isBankrupt == 1) {
      now_user = &players[(now_user->number) % 4];
    } else {
      now_user = &players[(now_user->number) % 4];
      goto flag;
    }
  } else if (strncmp(command, "Sell", 4) == 0 ||
             strncmp(command, "sell", 4) == 0) {
    int n = atoi(command + 5);
    // sell_property(n);
  } else if (strncmp(command, "Block", 5) == 0 ||
             strncmp(command, "block", 5) == 0) {
    int n = atoi(command + 6);
    // place_block(n);
  } else if (strncmp(command, "Bomb", 4) == 0 ||
             strncmp(command, "bomb", 4) == 0) {
    int n = atoi(command + 5);
    // place_bomb(n);
  } else if (strcmp(command, "Robot") == 0 || strcmp(command, "robot") == 0) {
    // clean_up();
  } else if (strcmp(command, "Query") == 0 || strcmp(command, "query") == 0) {
    // show_assets();
  } else if (strcmp(command, "Help") == 0 || strcmp(command, "help") == 0) {
    // show_help();
  } else if (strncmp(command, "Step", 4) == 0 ||
             strncmp(command, "step", 4) == 0) {
    int n = atoi(command + 5);
    // step_dice(n);
  } else if (strcmp(command, "Quit") == 0 || strcmp(command, "quit") == 0) {
    exit_game();
  } else {
    printf("未知命令\n");
  }
}

void wait_for_input() {
  switch (now_user->number) {
  case 1:
    printf("\033[31m钱夫人>\033[31m\033[0m");

    break;
  case 2:
    printf("\033[32m阿土伯>\033[32m\033[0m");
    break;
  case 3:
    printf("\033[34m孙小美>\033[34m\033[0m");
    break;
  case 4:
    printf("\033[33m金贝贝>\033[33m\033[0m");
    break;
  default:
    printf("error\n");
    break;
  }

  // 创建接受缓冲区
  char buf[100];
  // 接受用户输入
  // 接受用户输入
  fgets(buf, sizeof(buf), stdin);
  // 移除换行符
  buf[strcspn(buf, "\n")] = '\0';
  handle_command(buf);
}