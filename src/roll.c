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

extern Map map;

int roll_num() {
    // 使用当前时间作为种子
    srand(time(NULL));
    // 生成1到6之间的随机数
    int steps = rand() % 6 + 1;
    return steps;
}

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
                if(now_user->position==64)
                    now_user->point+=60;
                else if(now_user->position==65)
                    now_user->point+=80;
                else if(now_user->position==66)
                    now_user->point+=40;
                else if(now_user->position==67)
                    now_user->point+=100;
                else if(now_user->position==68)
                    now_user->point+=80;
                else if(now_user->position==69)
                    now_user->point+=20;
                break;
            }
        }
    }
    else if(kind==0){
        switch(rank){
            case 1:{
                if(now_user->money>=200){
                    printf("您是否要购买这块空地？y/n");
                    buy_earth(now_user,&map);
                }
                break;
            }
            case 2:{
                 if(now_user->money>=500){
                    printf("您是否要购买这块空地？y/n");
                    buy_earth(now_user,&map);
                }
                break;
            }
            case 3:{
                if(now_user->money>=300){
                    printf("您是否要购买这块空地？y/n");
                    buy_earth(now_user,&map);
                }
                break;
            }
        }
    }
}