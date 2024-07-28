/**
 * @file map.h
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

#ifndef MAP_H
#define MAP_H
typedef struct Cell {
  char show_char;
  // 字符 S 起点、 T 道具屋、 $ 矿地、 H 医院
  // M 魔法屋、G 礼品屋、P 监狱、0 普通地段
  char init_char;
  int kind; // 地的种类  0 空地 1 茅屋 2 洋房 3 摩天楼 特殊建筑为4
  int rank;     // 地段      1 地段一 2 地段二 3 地段三
  int has_tool; // 道具  1 路障、3 炸弹、0 没有道具
  int owner;    // 地主     1,2,3,4 0表示无主
} Cell;

typedef struct Map {
  Cell cells[70];
} Map;

void map_init(Map *map);
void map_print(Map *map);

#endif