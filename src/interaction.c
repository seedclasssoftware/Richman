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
#include "help.h"
#include "players.h"
#include "query.h"
#include "roll.h"
#include "sell_house.h"
#include "useprops.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

extern pPlayers now_user;
extern Map map;
// 退出游戏的实现
void exit_game() {
  printf("正在退出游戏...\n");

  // 显示退出信息
  printf("游戏已退出。感谢您的参与！\n");

  // 退出程序
  exit(0);
}

void print_working_directory() {
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working directory: %s\n", cwd);
  } else {
    perror("getcwd() error");
  }
}

// 切换玩家
void change_player() {
// 切换到下一个玩家
flag:
  // printf("切换到玩家%d\n", now_user->number);
  // printPlayers(players, 4);
  if (((players[(now_user->number) % 4].hospital == 0) &&
       (players[(now_user->number) % 4].prison == 0) &&
       (players[(now_user->number) % 4].isPlaying == 1) &&
       (players[(now_user->number) % 4].isBankrupt == 0)) == 1) {
    now_user = &(players[(now_user->number) % 4]);
    // printf("成功切换到玩家%d\n", now_user->number);
  } else {
    if ((players[(now_user->number) % 4].hospital != 0 &&
         players[(now_user->number) % 4].prison != 0) == 1 &&
        players[(now_user->number) % 4].isPlaying == 1) {
      printf("玩家%d处于监狱或医院，跳过该玩家\n", now_user->number);
      if (players[(now_user->number) % 4].hospital != 0) {
        players[(now_user->number) % 4].hospital--;
      }
      if (players[(now_user->number) % 4].prison != 0)
        players[(now_user->number) % 4].prison--;
    }
    now_user = &(players[(now_user->number) % 4]);
    goto flag;
  }
}
// 处理 Step 命令
void handle_step_command(const char *command) {
  // 检查 command 是否为 NULL 或长度不足
  if (command == NULL || strlen(command) < 6) {
    printf("Invalid command\n");
    return;
  }

  // 确保 "Step" 或 "step" 后跟一个空格
  if ((strncmp(command, "Step ", 5) == 0 ||
       strncmp(command, "step ", 5) == 0)) {
    // 检查空格后是否跟随数字
    char *num_str = command + 5;
    char *endptr;
    int n = strtol(num_str, &endptr, 10); // 转换字符串为整数

    // 确保转换成功并且没有非法字符
    if (*endptr == '\0') {
      change_position(now_user, n);
      eventJudge(now_user);
      change_player();
    } else {
      printf("Invalid number in command\n");
    }
  } else {
    printf("Invalid command format\n");
  }
}

extern Map map;

// 检查文件是否存在
int file_exists(const char *path) {
  FILE *file = fopen(path, "r");
  if (file) {
    fclose(file);
    return 1;
  }
  return 0;
}
/**
 * @brief 处理用户输入的命令
 *
 * @param command 用户输入的命令
 */
void handle_command(const char *command) {
  if (strcmp(command, "Roll") == 0 || strcmp(command, "roll") == 0) {
    int roll = roll_num();
    change_position(now_user, roll);
    eventJudge(now_user);
    // 切换当前玩家
    change_player();
  } else if (strncmp(command, "Sell", 4) == 0 ||
             strncmp(command, "sell", 4) == 0) {
    int n = atoi(command + 5);
    sell_house(now_user, &map);
  } else if (strncmp(command, "Block", 5) == 0 ||
             strncmp(command, "block", 5) == 0) {
    int n = atoi(command + 6);
    useblock(now_user, &map, n);
  } else if (strncmp(command, "Bomb", 4) == 0 ||
             strncmp(command, "bomb", 4) == 0) {
    int n = atoi(command + 5);
    usebomb(now_user, &map, n);
  } else if (strcmp(command, "Robot") == 0 || strcmp(command, "robot") == 0) {
    userobot(now_user, &map);
  } else if (strcmp(command, "Query") == 0 || strcmp(command, "query") == 0) {
    query(now_user);
  } else if (strcmp(command, "Help") == 0 || strcmp(command, "help") == 0) {
    help();
  } else if (strncmp(command, "Step", 4) == 0 ||
             strncmp(command, "step", 4) == 0) {
    handle_step_command(command);
  } else if (strcmp(command, "Quit") == 0 || strcmp(command, "quit") == 0) {
    exit_game();
  } else if (strcmp(command, "Dump") == 0 || strcmp(command, "dump") == 0) {
    printPlayers(players, 4);
    printf("Dumping game data...\n");
    char *json = convertToJson(players, 4, &map, now_user);
    // 创建output.json
    FILE *fp = fopen("output.json", "w");
    if (fp == NULL) {
      perror("文件打开失败");
      return;
    }
    // 写入json
    fprintf(fp, "%s", json);
    printf("游戏数据已保存到output.json\n");
    // 关闭文件
    fclose(fp);
    printf("已将游戏数据保存到output.json\n");
    free(json);
  } else if (strncmp(command, "load ", 5) == 0 ||
             strncmp(command, "Load ", 5) == 0) {
    const char *path = command + 5;
    print_working_directory();

    // 处理路径
    char cleaned_path[256];
    int j = 0;
    for (int i = 0; i < strlen(path) && j < sizeof(cleaned_path) - 1; i++) {
      if (path[i] != '"' && path[i] != '\n') {
        cleaned_path[j++] = (path[i] == '\\') ? '/' : path[i];
      }
    }
    cleaned_path[j] = '\0';

    printf("Trying to open file: %s\n", cleaned_path);

    // 检查文件是否存在, 接受绝对路径和相对路径
    if (file_exists(cleaned_path)) {
      // 读取文件内容
      FILE *fp = fopen(cleaned_path, "r");
      if (fp == NULL) {
        perror("文件打开失败");
        return;
      }
      // 获取文件大小
      fseek(fp, 0, SEEK_END);
      long size = ftell(fp);
      fseek(fp, 0, SEEK_SET);
      // 读取文件内容
      char *json_d = (char *)malloc(size + 1);
      fread(json_d, 1, size, fp);
      json_d[size] = '\0';
      // 关闭文件
      fclose(fp);
      // 调用initializePlayers函数
      initializePlayers(json_d, players, 4, &map);
      free(json_d);
    } else {
      printf("文件不存在\n");
    }
    printf("游戏数据已加载\n");
    printf("当前玩家: %s\n", now_user->name);
  } else {
    printf("未知命令\n");
  }
}

void wait_for_input() {
  // printPlayers(players, 4);
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