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
#include "gifthouse.h"
#include "buy_earth.h"
#include "earthup.h"
#include "mine_earth.h"
#include "pass_road_money.h"
//#include "winnt.h"
extern Map map;
extern Players players[4];
/**
 * @brief 玩家掷骰子 
 * @return 骰子点数
 */
int roll_num() {
    // 使用当前时间作为种子
    srand(time(NULL));
    // 生成1到6之间的随机数
    int steps = rand() % 6 + 1;
    return steps;
}
/**
 * @brief 根据点数以及玩家当前位置将玩家移到指定地方
 * @param now_user 当前玩家指针
 * @param steps 玩家掷的骰子数
 */
void change_position(pPlayers now_user,int steps){
    int flag=0;
    printf("当前骰子点数为：%d\n",steps);
    for(int i=1;i<=steps;i++){
        int tool=map.cells[now_user->position+i].has_tool;
        if(tool==0) continue;
        else if(tool==1){
            now_user->position+=i;
            map.cells[now_user->position].show_char=now_user->cap;
            flag=1;
            break;
        }
        else if(tool==3){
            now_user->position=14;
            now_user->hospital=3;
            flag=1;
            break;
        }
    }
    if(flag==0) now_user->position+=steps;
}
/**
 * @brief 根据玩家所在格属性判断触发的事件
 * 
 * @param now_user 当前玩家指针
 */
void eventJudge(pPlayers now_user){
    int kind=map.cells[now_user->position].kind;
    int rank=map.cells[now_user->position].rank;
    int owner=map.cells[now_user->position].owner;
    int show_char=map.cells[now_user->position].show_char;
    if(kind==4){
        switch(show_char){
            case 'T':{

                break;
            }
            case 'G':{
                gifthouse_event_process(now_user);
                break;
            }
            case 'M':{

                break;
            }
            case 'H':{
                break;
            }
            case 'P':{
                now_user->prison=2;
                break;
            }
            case '$':{
                mining_for_point(now_user, map.cells, now_user->position);
            }
        }
    }
    else {
        if(owner==0){
           buy_earth(now_user, &map);
        }
        else if(owner==now_user->number){
           earth_up(now_user, map.cells);
        }
        else{
            pay_money(players, map.cells, now_user);
        }
    }
}