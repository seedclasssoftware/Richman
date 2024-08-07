/**
 * @file clean_body.c
 * @author 王航天
 * @brief 
 * @version 0.1
 * @date 2024-07-29
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
#include "map.h"
#include "players.h"
#include <stdio.h>
#include "roll.h"

extern int temp[70][4];

void clean_body(Map *map, Players *player)
{
    printf("%c被抬走了\n", map->cells[player->position].show_char);
    change_now(player);
      map->cells[player->position].show_char =
      temp[player->position][3] ? temp[now_user->position][3]
                                  : map->cells[player->position].init_char;}