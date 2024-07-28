/**
 * @file gifthouse.c
 * @author 王航天 (no)
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
#include "gifthouse.h"
#include <stdio.h>

void gifthouse_event_process(Players *player) {
  printf("欢迎光临礼品屋！\n");

  printf("您有如下三个选项:\n");
  printf("1. 2000 money\n");
  printf("2. 200 points\n");
  printf("3. 1 godBuff\n");
  printf("请输入您的选项(1-3): ");

  int choice;
  // 读入用户的选择，并清除缓冲区
  scanf("%d", &choice);
  while (getchar() != '\n')
    ;

  switch (choice) {
  case 1:
    player->money += 2000;
    break;

  case 2:
    player->point += 200;
    break;

  case 3:
    player->god = 5;
    break;
  }

  printf("You have got your gift!\n");
}