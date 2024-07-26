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
#include <cstdio>
#include <windows.h>
#include <stdio.h>
#include "players.h"

Players players[4];

pPlayers now_user = &players[0];

int main(int argc, char const *argv[], char const *envp[])
{
    if (argc == 0)
    {
    }
    else {/// 有参数,将第一个参数作为json文件地址(绝对路径或者相对路径)
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("文件打开失败\n");
    }
    // 获取文件大小
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // 读取文件内容
    char *json_data = (char *)malloc(size + 1);
    fread(json_data, 1, size, fp);
    json_data[size] = '\0';
    // 关闭文件
    fclose(fp);
    initializePlayers(json_data, players, 4);
    printPlayers(players, 4);
    }
    SetConsoleOutputCP(CP_UTF8);///< 设置控制台输出编码为UTF-8,很重要,否则中文输出乱码

    return 0;
}