/**
 * @file query.c
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
#include "query.h"
#include "players.h"
#include <stdio.h>
void query(pPlayers now_user) {
  printf("玩家%d的信息如下：\n", now_user->number);
  printf("玩家%d的金钱：%d\n", now_user->number, now_user->money);
  printf("玩家%d的道具点数：%d\n", now_user->number, now_user->point);
  printf("玩家%d的位置：%d\n", now_user->number, now_user->position);
  printf("玩家%d的道具：\n", now_user->number);
  printf("障碍：%d\n", now_user->block);
  printf("机器娃娃：%d\n", now_user->robot);
  printf("炸弹：%d\n", now_user->bomb);
  printf("玩家%d的增益：\n", now_user->number);
  printf("财神：%d\n", now_user->god);
  printf("监狱：%d\n", now_user->prison);
  printf("医院：%d\n", now_user->hospital);
  printf("魔法：%d\n", now_user->magic);
  //
}