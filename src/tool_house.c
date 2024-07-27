/**
 * @file tool_house.c
 * @author 古静怡 (2856514560@qq.com)
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
#include "tool_house.h"
#include "players.h"

void buy_tool(pPlayers player)
{
    if(player->point >= 30)
    {
        char choice_tool = 'F';
        printf("欢迎光临道具屋，请选择您所需要的道具：1.路障 2.机器娃娃 3.炸弹 F.退出\n");
        scanf("%c",&choice_tool);
        while(choice_tool != 'F')
        {
            int tool_number = player->block + player->bomb + player->robot;
            if(tool_number == 10)
            {
                printf("您的道具数已达最大值，不能购买.\n");
                break;
            }
            else 
            {
                if(choice_tool == '2')
                {
                    player->robot++;
                    player->point -= 30;
                }
                else if(choice_tool == '1')
                {
                    if(player->point >= 50)
                    {
                        player->point -= 50;
                        player->block++;
                    }
                    else {
                        printf("您当前剩余的点数为%u，不足以购买路障道具。\n",player->point);
                    }
                }
                else if(choice_tool == '3')
                {
                    if(player->point >= 50)
                    {
                        player->point -= 50;
                        player->bomb++;
                    }
                    else {
                        printf("您当前剩余的点数为%u，不足以购买炸弹道具。\n",player->point);
                    }
                }
                else {
                    printf("输入错误\n");
                }
            }
            
            printf("请选择您所需要的道具：1.路障 2.机器娃娃 3.炸弹 F.退出\n");
            scanf("%c",&choice_tool);
        }
    }
    else
    {
        printf("点数不足.\n");
    }
    return;
}

void test_tool_house_when_points_is_29_and_0_tool()
{
    Players players;
    players.point = 29;
    players.bomb = 0;
    players.block = 0;
    players.robot = 0;
    buy_tool(&players);
    int tool_number = players.robot +players.block + players.bomb;
    printf("test_result:point:%u,tool_number:%d\n",players.point,tool_number);

}