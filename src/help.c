/**
 * @file help.h
 * @author 王航天 (no email)
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

#include "help.h"
#include <stdio.h>

void help() {
  printf("----------------------------------------\n");
  printf("| Roll  | 掷骰子命令                    |\n");
  printf("----------------------------------------\n");
  printf("| Sell  | 出售房产命令                  |\n");
  printf("----------------------------------------\n");
  printf("| Block | 路障设置命令                  |\n");
  printf("----------------------------------------\n");
  printf("| Bomb  | 炸弹设置命令                  |\n");
  printf("----------------------------------------\n");
  printf("| Robot | 机器人使用命令                |\n");
  printf("----------------------------------------\n");
  printf("| Query | 显示自家资产命令              |\n");
  printf("----------------------------------------\n");
  printf("| Help  | 查看命令帮助                  |\n");
  printf("----------------------------------------\n");
  printf("| Quit  | 强制退出游戏命令              |\n");
  printf("----------------------------------------\n");
}
