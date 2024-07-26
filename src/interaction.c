/**
 * @file interaction.c
 * @author 王一赫 (wyihe5220@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-26
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
#include "interaction.h"

extern pPlayers now_user;

void wait_for_input() 
{
    switch (now_user->number) {
        case 1:
            printf("\033[31m钱夫人>\033[31m");
            break;
        case 2:
        printf("\033[32m阿土伯>\033[32m");
        break;
        case 3:
        printf("\033[33m孙小美>\033[33m");
        break;
        case 4:
        printf("\033[34m金贝贝>\033[34m");
        break;
        default:
        printf("error\n");
        break;
    }
    // 
}