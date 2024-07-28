/**
 * @file roll.h
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
#ifndef ROLL_H
#define ROLL_H
#include "players.h"

/**
 * @brief 玩家掷骰子 
 * @return 骰子点数
 */

int roll_num();
/**
 * @brief 根据点数以及玩家当前位置将玩家移到指定地方
 * @param now_user 当前玩家指针
 * @param steps 玩家掷的骰子数
 */
void change_position(pPlayers now_user,int steps);
/**
 * @brief 根据玩家所在格属性判断触发的事件
 * 
 * @param now_user 当前玩家指针
 */
void eventJudge(pPlayers now_user);

void change_show(int position,char cap);

void change_now(int position);
#endif