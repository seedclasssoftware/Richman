/**
 * @file useprops.c
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
#include "useprops.h"
#include "players.h"
#include "map.h"
#include <stdio.h>

void useprops(Players *player, Map *map)
{
    printf("do you want to use props?\n");
    printf("0.do not use\n");
    printf("1.block\n");
    printf("2.robot\n");
    printf("3.bomb\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (player->block > 0)
            {
                printf("please select a position to place your block:-10~10\n");
                int place_position;
                scanf("%d", &place_position);
                map->cells[player->position+place_position].has_tool = 1;
                printf("you have used block\n");
                player->block--;

                //map->cells[player->position].has_tool = 1;
            }
            else
            {
                printf("you do not have block\n");
            }
            break;

        case 2:
            if (player->robot > 0)
            {
                printf("you have used robot\n");
                player->robot--;
                for (int i = 0; i < 10; i++)
                {
                    if(map->cells[i].has_tool == 3)
                    {
                        map->cells[i].has_tool = 0;
                    }
                }
            }
            else
            {
                printf("you do not have robot\n");
            }
            break;

        case 3:
            if (player->bomb > 0)
            {
                printf("you have used bomb\n");
                player->bomb--;
                map->cells[player->position].has_tool = 3;
            }
            else
            {
                printf("you do not have bomb\n");
            }
            break;

        default:
            break;
    }


}