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
 *   放置炸弹和路障以及使用机器人清扫前方10步内的所有路障和炸弹
 *
 */
#include "useprops.h"
#include "map.h"
#include "players.h"
#include <stdio.h>


void useprops(Players *player, Map *map) {
  printf("do you want to use props?\n");
  printf("0.do not use\n");
  printf("1.block\n");
  printf("2.robot\n");
  printf("3.bomb\n");

  int choice;
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    if (player->block > 0) {
      //printf("please select a position to place your block:-10~10\n");
      int place_position;
      scanf("%d", &place_position);
      while (place_position > 10 || place_position < -10) {
        printf("非法的位置输入！\n");
        scanf("%d", &place_position);
      }
      place_position = (player->position + place_position) > 0
                           ? (player->position + place_position) % 69
                           : (69 + (player->position + place_position)) % 69;
      map->cells[place_position].has_tool = 1;
      map->cells[place_position].show_char = '#';
      printf("你在 地图的%d 放置了路障！\n", place_position);
      player->block--;

      // map->cells[player->position].has_tool = 1;
    } else {
      printf("你没有路障！\n");
    }
    break;

  case 2:
    if (player->robot > 0) {
      for (int i = 1; i < 11; i++) {
        map->cells[i + player->position].has_tool = 0;
      }
      printf("你使用了机器人\n");
      player->robot--;

    } else {
      printf("你没有机器人！\n");
    }
    break;

  case 3:
    if (player->bomb > 0) {
      //printf("please select a position to place your bomb:-10~10\n");
      int place_position;
      scanf("%d", &place_position);
      while (place_position > 10 || place_position < -10) {
        printf("非法的位置输入！\n");
        scanf("%d", &place_position);
      }
      place_position = (player->position + place_position) > 0
                           ? (player->position + place_position) % 69
                           : (69 + (player->position + place_position)) % 69;
      map->cells[place_position].has_tool = 3;
      map->cells[place_position].show_char = '@';
      printf("你在地图的 %d 放置了炸弹！\n", place_position);
      player->bomb--;

    } else {
      printf("你没有炸弹！\n");
    }
    break;

  default:
    break;
  }
}

void useblock(Players *player, Map *map, int place_position) {
  if (player->block > 0) {
    //printf("please select a position to place your block:-10~10\n");
    while (place_position > 10 || place_position < -10) {
      printf("非法的位置输入！\n");
      return;
      //scanf("%d", &place_position);
    }
    place_position = (player->position + place_position) > 0
                         ? (player->position + place_position) % 69
                         : (69 + (player->position + place_position)) % 69;
    map->cells[place_position].has_tool = 1;
    map->cells[place_position].show_char = '#';
    printf("你在 地图的 %d 放置了路障！\n", place_position);
    player->block--;

    // map->cells[player->position].has_tool = 1;
  } else {
    printf("你没有路障！\n");
  }
}

void userobot(Players *player, Map *map) {
  if (player->robot > 0) {
    for (int i = 1; i < 11; i++) {
      map->cells[i + player->position].has_tool = 0;
    }
    printf("你使用了机器人！\n");
    player->robot--;

  } else {
    printf("你没有机器人！\n");
  }
}

void usebomb(Players *player, Map *map, int place_position) {
  if (player->bomb > 0) {
    //printf("please select a position to place your bomb:-10~10\n");
    while (place_position > 10 || place_position < -10) {
      printf("非法的位置输入！\n");
      return;
      //scanf("%d", &place_position);
    }
    place_position = (player->position + place_position) > 0
                         ? (player->position + place_position) % 69
                         : (69 + (player->position + place_position)) % 69;
    map->cells[place_position].has_tool = 3;
    map->cells[place_position].show_char = '@';
    printf("你在地图的 %d 放置了炸弹！\n", place_position);
    player->bomb--;

  } else {
    printf("你没有炸弹！\n");
  }
}