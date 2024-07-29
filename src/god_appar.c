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

#include "map.h"
#include "god_appar.h"
#include <stdlib.h>
#include <time.h>

void god_appar(Map *map)
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
    map->cells[god_pos].has_tool = 3;//3代表财神
}