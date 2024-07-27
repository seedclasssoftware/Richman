/**
 * @file roll.c
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
#include "players.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "map.h"

extern Map map;

int roll_num() {
    // 使用当前时间作为种子
    srand(time(NULL));
    // 生成1到6之间的随机数
    int steps = rand() % 6 + 1;
    return steps;
}

void change_position(pPlayers now_user,int steps){
    printf("当前骰子点数为：%d\n",steps);
    for(int i=1;i<=steps;i++){
        int tool=map.cells[now_user->position+i].has_tool;
        if(tool==0) continue;
    }
}