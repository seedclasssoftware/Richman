/**
 * @file god_appar.c
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

#include "god_appear.h"
#include "map.h"
#include "players.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//财神爷出现倒计时
int god_countdown = 0;
int god_position = -1;

void god_appear(Map *map)
{
    srand((unsigned)time(NULL));
    int god_pos = rand() % 70;
    while ((map->cells[god_pos].kind == 4) || (map->cells[god_pos].has_tool != 0) || (map->cells[god_pos].show_char == 'Q') 
    || (map->cells[god_pos].show_char == 'A') || (map->cells[god_pos].show_char == 'S')|| (map->cells[god_pos].show_char == 'J'))
    {
        srand((unsigned)time(NULL));
        god_pos = rand() % 70;
    }
    map->cells[god_pos].show_char = 'F';
    printf("财神爷出现在位置 %d\n",god_position);
}

void god_time(Map *map)
{
    if (god_countdown > 0) {
        god_countdown--;
        printf("距离财神爷出现还有 %d 轮\n", god_countdown);
        if (god_countdown == 0) {
            god_appear(map);
        }
    } else if (god_position != -1) {
        for (int i = 0; i < 4; i++) {
            if (players[i] .isPlaying && players[i]. position == god_position) {
                players[i] .god = 1;
                map->cells[god_position].show_char = ' ';
                god_position = -1;
                printf("%s 捡到了财神爷\n", players[i] . name);
                break;
            }
        }
        static int god_timer = 5;
        if (god_position != -1) {
            god_timer--;
            if (god_timer == 0) {
                map->cells[god_position].show_char = map->cells[god_position].init_char;
                printf("财神爷消失了\n");
                god_position = -1;
                god_timer = 5;
            }
        }
    }
}