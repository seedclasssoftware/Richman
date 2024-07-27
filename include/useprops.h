/**
 * @file useprops.h
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

#ifndef USEPROPS_H
#define USEPROPS_H

#include "players.h"
#include "map.h"

void useprops(Players *player, Map *map);//使用道具函数

void useblock(Players *player, Map *map);//使用路障函数
void userobot(Players *player, Map *map);//使用机器人函数
void usebomb(Players *player, Map *map);//使用炸弹函数
#endif 
