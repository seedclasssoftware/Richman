/**
 * @file palyers.h
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

#ifndef PLAYERS_H
#define PLAYERS_H

#include <stdint.h>

/**
 * @brief 枚举玩家名字宏定义
 *
 */
enum Players_Name {
  ATUB = 0,   ///< 阿土伯 = 0
  QIAN_Madam, ///< 钱夫人 = 1
  SUN_Miss,   ///< 孙小姐 = 2
  JIN_Bei,    ///< 金贝 = 3
};

/**
 * @brief 玩家结构体
 *
 * @param name 玩家名{char*}
 * @param money 玩家金钱{uint32_t}
 * @param point 玩家道具点数{uint32_t}
 * @param number 玩家编号{uint8_t}
 * @param block 道具:障碍{uint8_t}
 * @param robot 道具:机器娃娃{uint8_t}
 * @param bomb 道具:炸弹{uint8_t}
 * @param god 增益:财神{uint8_t} 使用1-5代表剩余回合数,0表示未使用
 * @param prison 增益:监狱{uint8_t} 使用1-2代表剩余回合数,0表示未使用
 * @param hospital 增益:医院{uint8_t} 使用1-3代表剩余回合数,0表示未使用
 * @param magic 增益:魔法{uint8_t} 使用1-3代表剩余回合数,0表示未使用
 * @param position 玩家位置{uint8_t}
 * @param properties 玩家资产 ...未实现
 */
typedef struct Players {
  char *name;
  uint32_t money;
  uint32_t point;
  uint8_t number;
  uint8_t block;
  uint8_t robot;
  uint8_t bomb;
  uint8_t god;
  uint8_t prison;
  uint8_t hospital;
  uint8_t magic;
  uint8_t position;
  /// properties
} Players, *pPlayers;

#endif ///< PLAYERS_H