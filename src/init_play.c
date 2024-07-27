/**
 * @file init_play.c
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
#include <stdio.h>
#include <stdlib.h>
#include "init_play.h"
#include "players.h"
#include <string.h>
#include<stdint.h>

char *player_names[] = {
    "钱夫人",
    "阿土伯",
    "孙小美",
    "金贝贝"
};

char *player_colors[] = {
    "\033[31m", // 红色
    "\033[32m", // 绿色
    "\033[34m", // 蓝色
    "\033[33m"  // 黄色
};

char player_caps[] = {'Q','A','S','J'};

void init_money(uint32_t *initMoney) {
    char input[100]; // 用来存储用户输入
    printf("请输入初始金额(1000-50000)，直接按回车默认为10000: ");
    
    // 获取输入
    fgets(input, sizeof(input), stdin);
    
    // 判断用户是否输入了值
    if (input[0] == '\n') {
        *initMoney = 10000; // 默认值
    } else {
        *initMoney = atoi(input); // 将输入的字符串转换为整数
        // 检查输入是否在有效范围内
        while (*initMoney < 1000 || *initMoney > 50000) {
            fprintf(stderr,"输入无效，请输入初始金额(1000-50000)，直接按回车默认为10000: ");
            fgets(input, sizeof(input), stdin);
            if (input[0] == '\n') {
                *initMoney = 10000; // 默认值
                break;
            } else {
                *initMoney = atoi(input); // 转换为整数
            }
        }
    }
    printf("初始金额为：%d\n", *initMoney);
}

void select_players(Players *players, int num_players, uint32_t init_money) {
    char input[10];
    int count = 0;

    // 初始化所有角色
    for (int i = 0; i < 4; i++) {
        players[i].money = init_money;
        players[i].point = 0;
        players[i].number = 0;
        players[i].block = 0;
        players[i].robot = 0;
        players[i].bomb = 0;
        players[i].god = 0;
        players[i].prison = 0;
        players[i].hospital = 0;
        players[i].magic = 0;
        players[i].position = 0;
        players[i].isPlaying = 0;
        players[i].isBankrupt= 0;
    }

    printf("请选择2-4位不重复玩家，输入编号即可");
    for (int i = 0; i < 4; i++) {
        printf("%s%d、%s%s\033[0m; ", player_colors[i], i + 1, player_colors[i], player_names[i]);
    }
    printf("如输入:12: ");
    printf("\n");
    //循环直到用户输入有效的玩家编号
    while (1) {
        fgets(input, sizeof(input), stdin); //获取输入
        count = 0;
        int valid = 1;
        int selected[4] = {0};
        // 遍历输入的每个字符
        for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
            int index = input[i] - '1'; // 将字符转换为索引
            // 检查编号是否有效且未被选择
            if (index < 0 || index > 3 || selected[index] == 1) {
                valid = 0; // 标记为无效输入
                break;
            }
            selected[index]++; // 存储有效编号
            count++;
        }
        // 检查输入是否有效且选择的玩家数量在2-4之间
        if (valid==1&&count>=2&&count<=4) {
            printf("您选择的角色是: ");
            for (int i = 0; i < count; i++) {
                players[i].name=player_names[input[i]-1];
                players[i].cap=player_caps[input[i]-1];
                players[i].isPlaying = 1;
                if(players[i].cap=='Q'){
                    players[i].number=1;
                }
                else if(players[i].cap=='A'){
                    players[i].number=2;
                }
                else if(players[i].cap=='S'){
                    players[i].number=3;
                }
                else players[i].number=4;
                // 打印选择的玩家名字和颜色
                printf("%s%s\033[0m ", player_colors[(int)(input[i]-'1')], player_names[(int)(input[i]-'1')]);
            }
            break;
        }
        else fprintf(stderr,"您的输入格式不正确，请重新输入！"); 
    }
    return ;
}