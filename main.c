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
#include "players.h"
#include <stdio.h>
#include <windows.h>
#include "buy_earth.h"
#include "earthup.h"
#include "map.h"
#include "tool_house.h"



int main(int argc, char const *argv[], char const *envp[]) {
  SetConsoleOutputCP(
      CP_UTF8); ///< 设置控制台输出编码为UTF-8,很重要,否则中文输出乱码
  /// 无参数,默认为游戏模式
  test1_buy_earth1_when_money_is_199();
  test_earth_up();
  printf("hello\n");
  return 0;
}