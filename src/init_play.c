/**
 * @file init_play.c
 * @author 郑伊恬 李文皓 (1491305138@qq.com)
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
#include "init_play.h"
#include "players.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void initialize_Players() {
  players[0] =
      (Players){"钱夫人", 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\0', 0, {0}};
  players[1] =
      (Players){"阿土伯", 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\0', 0, {0}};
  players[2] =
      (Players){"孙小美", 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\0', 0, {0}};
  players[3] =
      (Players){"金贝贝", 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\0', 0, {0}};
}

char player_caps[] = {'Q', 'A', 'S', 'J'};

// 定义默认初始金额
#define DEFAULT_INIT_MONEY 10000
#define MIN_INIT_MONEY 1000
#define MAX_INIT_MONEY 50000

/**
 * @brief Initializes the money for the game
 *
 * @param initMoney Pointer to the variable that will store the initial money
 */
void init_money(uint32_t *initMoney) {
  char input[100]; // 用来存储用户输入
  int money;

  printf("请输入初始金额(%d-%d)，直接按回车默认为%d: ", MIN_INIT_MONEY,
         MAX_INIT_MONEY, DEFAULT_INIT_MONEY);

  // 获取输入
  if (fgets(input, sizeof(input), stdin) != NULL) {
    // 去除输入中的换行符
    input[strcspn(input, "\n")] = 0;

    // 判断用户是否输入了值
    if (input[0] == '\0') {
      *initMoney = DEFAULT_INIT_MONEY; // 默认值
    } else {
      // 尝试将输入转换为整数
      if (sscanf(input, "%d", &money) == 1) {
        // 检查输入是否在有效范围内
        if (money >= MIN_INIT_MONEY && money <= MAX_INIT_MONEY) {
          *initMoney = (uint32_t)money;
        } else {
          fprintf(stderr,
                  "输入无效，请输入初始金额(%d-%d)，直接按回车默认为%d: ",
                  MIN_INIT_MONEY, MAX_INIT_MONEY, DEFAULT_INIT_MONEY);
          init_money(initMoney); // 递归调用直到输入有效
        }
      } else {
        fprintf(stderr, "输入无效，请输入初始金额(%d-%d)，直接按回车默认为%d: ",
                MIN_INIT_MONEY, MAX_INIT_MONEY, DEFAULT_INIT_MONEY);
        init_money(initMoney); // 递归调用直到输入有效
      }
    }
  } else {
    *initMoney = DEFAULT_INIT_MONEY; // 如果fgets失败，设置默认值
    printf("初始金额为：%u\n", *initMoney);
    printf("fgets失败\n");
  }

  printf("初始金额为：%u\n", *initMoney);
}
/**
 * @brief Selects the players for the game
 *
 * @param players Pointer to the players struct
 * @param selected_players Pointer to the array that will store the selected
 * players
 * @param num_players Number of players
 * @param init_money Initial money for the game
 */

const char *getPlayerColor(const char *name) {
  if (strcmp(name, "钱夫人") == 0) {
    return RED;
  } else if (strcmp(name, "阿土伯") == 0) {
    return GREEN;
  } else if (strcmp(name, "孙小美") == 0) {
    return BLUE;
  } else if (strcmp(name, "金贝贝") == 0) {
    return YELLOW;
  }
  return RESET;
}
void printPlayerName(const char *name) {
  printf("%s%s%s", getPlayerColor(name), name, RESET);
}

void selectPlayers(uint32_t *initMoney) {
  char input[5];
  int valid = 0;

  while (!valid) {
    printf("请选择2-4位不重复玩家，输入编号即可(1. 钱夫人; 2. 阿土伯; 3. "
           "孙小美; 4. 金贝贝;), 如输入: 12 23\n");
    scanf("%s", input);
    while (getchar() != '\n')
      ;

    int length = strlen(input);
    valid = 1;

    // 检查输入长度
    if (length < 2 || length > 4) {
      printf("输入无效，请输入2到4位不重复数字。\n");
      valid = 0;
      continue;
    }

    // 检查输入字符范围和重复
    for (int i = 0; i < length; i++) {
      if (input[i] < '1' || input[i] > '4') {
        printf("输入无效，数字必须是1到4。\n");
        valid = 0;
        break;
      }
      for (int j = i + 1; j < length; j++) {
        if (input[i] == input[j]) {
          printf("输入无效，数字不能重复。\n");
          valid = 0;
          break;
        }
      }
      if (!valid)
        break;
    }
  }

  printf("您选择的角色是: ");
  for (int i = 0; i < strlen(input); i++) {
    int index = input[i] - '1';
    players[index].isPlaying = 1;
    players[index].money = *initMoney; // 设置初始金额
    players[index].cap = player_caps[index];
    printf("%s ", players[index].name);
  }
  printf("\n");
  // 根据input初始化next
  initPlayersorder(input);

  // printPlayers(players, 4);

  // system("pause");
}
