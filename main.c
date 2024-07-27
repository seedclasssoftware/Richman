/**
 * @file main.c
 * @author 王一赫 (wyihe5220@gmail.com)
 * @brief KMP算法的实现实验
 * @version 0.1
 * @date 2024-05-31
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
#include <windows.h>
#include <stdio.h>
#include "gifthouse.h"
#include "players.h"
#include "useprops.h"
#include "map.h"

int main(int argc, char const *argv[], char const *envp[])
{
    SetConsoleOutputCP(CP_UTF8);///< 设置控制台输出编码为UTF-8,很重要,否则中文输出乱码
    // 打开文件
    
    //write you test file here
    //-----------------------------------------------------
    /*
    Players players;

    printf("money: %d\n", players.money);
    printf("point: %d\n", players.point);
    printf("god: %d\n", players.god);


    gifthouse_event_process(&players);

    printf("money: %d\n", players.money);
    printf("point: %d\n", players.point);
    */

    
    Players player;
    Map map;
    map_init(&map);
    player.position = 15;
    map_print(&map);
    useprops(&player, &map);
    


    //-----------------------------------------------------
    
    return 0;
}