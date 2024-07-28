/**
 * @file sell_house.c
 * @author 王一赫 (wyihe5220@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-28
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

#include "map.h"
#include "players.h"
#include "sell_house.h"
#include <stdio.h>

void sell_house(Players *player, Map *map)//卖房子函数
{
    printf("do you want to sell house?\n");
    printf("0.do not sell\n");
    printf("1.sell\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 0:
            break;
        case 1:
            int own = 0;
            for (int i = 0; i < 70; i++)
            {
                if (map->cells[i].owner == player->number)
                {
                    own++;
                }
            }
            if(own)
            {
                printf("which house do you want to sell?\n");
                int house;
                scanf("%d", &house);
                if (map->cells[house].owner == player->number)
                {
                    if (map->cells[house].rank == 1)
                    {
                        player->money += 2*200*map->cells[house].kind;
                        map->cells[house].kind = 0;
                        map->cells[house].owner = 0;
                    }
                    else if (map->cells[house].rank == 2)
                    {
                        player->money += 2*500*map->cells[house].kind;
                        map->cells[house].kind = 0;
                        map->cells[house].owner = 0;
                    }
                    else if (map->cells[house].rank == 3)
                    {
                        player->money += 2*300*map->cells[house].kind;
                        map->cells[house].kind = 0;
                        map->cells[house].owner = 0;
                    }
                    else {
                        printf("you do not have any house\n");
                    }
                    
                }
                else
                {
                    printf("you do not own this house\n");
                }
            }
            else
            {
                printf("you do not own any house\n");
            }
            
            break;
        default:
            break;
    }
}