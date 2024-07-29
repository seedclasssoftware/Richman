/**
 * @file map.c
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

#include "map.h"
#include "players.h"
#include <stdio.h>

void map_init(Map *map) {
  // 初始化show_char、init chars
  for (int i = 0; i < 70; i++) {
    map->cells[i].show_char = '0';
    map->cells[i].init_char = '0';
    map->cells[i].kind = 0;
    map->cells[i].rank = 0;
    map->cells[i].has_tool = 0;
    map->cells[i].owner = 0;
  }

  // map->cells[i].owner = 1;
  for (int i = 64; i < 70; i++) {
    map->cells[i].show_char = '$';
    map->cells[i].init_char = '$';
  }

  map->cells[0].show_char = 'S';
  map->cells[28].show_char = 'T';
  map->cells[35].show_char = 'G';
  map->cells[63].show_char = 'P';
  map->cells[14].show_char = 'P';
  map->cells[49].show_char = 'P';

  map->cells[0].init_char = 'S';
  map->cells[28].init_char = 'T';
  map->cells[35].init_char = 'G';
  map->cells[63].init_char = 'P';
  map->cells[14].init_char = 'P';
  map->cells[49].init_char = 'P';

  // 初始化kind
  map->cells[0].kind = 4;
  map->cells[28].kind = 4;
  map->cells[35].kind = 4;
  map->cells[63].kind = 4;
  map->cells[14].kind = 4;
  map->cells[49].kind = 4;

  for (int i = 64; i < 70; i++) {
    map->cells[i].kind = 4;
  }
  // 初始化rank
  for (int i = 0; i < 29; i++) {
    map->cells[i].rank = 1;
  }

  for (int i = 29; i < 35; i++) {
    map->cells[i].rank = 2;
  }

  for (int i = 35; i < 64; i++) {
    map->cells[i].rank = 3;
  }
}

void map_print(Map *map) {
  // 第一个
  if (map->cells[0].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[0].show_char);
  } else if (map->cells[0].show_char ==
             'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[0].show_char);
  } else if (map->cells[0].show_char ==
             'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[0].show_char);
  } else if (map->cells[0].show_char == 'S' &&
             players[2].position == 0 && players[2].isPlaying == 1
             ) // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[0].show_char);
  } else {
    printf("\033[0m%c\033[0m", map->cells[0].show_char);
  }
  // 第一行除了第一个
  for (int i = 1; i < 29; i++) {
    if (map->cells[i].show_char ==
        'Q') // 最高优先级，如果钱夫人站在这，显示红色
    {
      printf("\033[31m%c\033[31m", map->cells[i].show_char);
    }

    else if (map->cells[i].show_char ==
             'A') // 次优先级，如果阿土伯站在这，显示绿色
    {
      printf("\033[32m%c\033[32m", map->cells[i].show_char);
    }

    else if (map->cells[i].show_char ==
             'S') // 再次优先级，如果孙小美站在这，显示蓝色
    {
      printf("\033[34m%c\033[34m", map->cells[i].show_char);
    }

    else if (map->cells[i].show_char ==
             'J') // 最次优先级，如果金贝贝站在这，显示黄色
    {
      printf("\033[33m%c\033[33m", map->cells[i].show_char);
    }

    else if (map->cells[i].owner == 1) // Q Red
    {
      printf("\033[31m%c\033[31m", map->cells[i].show_char);
    } else if (map->cells[i].owner == 2) // A Green
    {
      printf("\033[32m%c\033[32m", map->cells[i].show_char);
    } else if (map->cells[i].owner == 3) // S Blue
    {
      printf("\033[34m%c\033[34m", map->cells[i].show_char);
    } else if (map->cells[i].owner == 4) // J Yellow
    {
      printf("\033[33m%c\033[33m", map->cells[i].show_char);
    } else // no owner
    {
      printf("\033[0m%c\033[0m", map->cells[i].show_char);
    }
  }
  printf("\n");

  // 第二行
  if (map->cells[69].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[69].show_char);
  }

  else if (map->cells[69].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[69].show_char);
  }

  else if (map->cells[69].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[69].show_char);
  }

  else if (map->cells[69].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[69].show_char);
  } else {
    printf("\033[0m%c\033[0m", map->cells[69].show_char);
  }

  for (int i = 0; i < 27; i++) {
    printf(" ");
  }

  // printf("%c", map->cells[29].show_char);
  if (map->cells[29].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[29].show_char);
  }

  else if (map->cells[29].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[29].show_char);
  }

  else if (map->cells[29].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[29].show_char);
  }

  else if (map->cells[29].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[29].show_char);
  }

  else if (map->cells[29].owner == 1) // Q Red
  {
    printf("\033[31m%c\033[31m", map->cells[29].show_char);
  } else if (map->cells[29].owner == 2) // A Green
  {
    printf("\033[32m%c\033[32m", map->cells[29].show_char);
  } else if (map->cells[29].owner == 3) // S Blue
  {
    printf("\033[34m%c\033[34m", map->cells[29].show_char);
  } else if (map->cells[29].owner == 4) // J Yellow
  {
    printf("\033[33m%c\033[33m", map->cells[29].show_char);
  } else // no owner
  {
    printf("\033[0m%c\033[0m", map->cells[29].show_char);
  }

  printf("\n");

  // 第三行
  if (map->cells[68].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[68].show_char);
  }

  else if (map->cells[68].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[68].show_char);
  }

  else if (map->cells[68].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[68].show_char);
  }

  else if (map->cells[68].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[68].show_char);
  } else {
    printf("\033[0m%c\033[0m", map->cells[68].show_char);
  }

  for (int i = 0; i < 27; i++) {
    printf(" ");
  }

  // printf("%c", map->cells[30].show_char);
  if (map->cells[30].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[30].show_char);
  }

  else if (map->cells[30].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[30].show_char);
  }

  else if (map->cells[30].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[30].show_char);
  }

  else if (map->cells[30].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[30].show_char);
  }

  else if (map->cells[30].owner == 1) // Q Red
  {
    printf("\033[31m%c\033[31m", map->cells[30].show_char);
  } else if (map->cells[30].owner == 2) // A Green
  {
    printf("\033[32m%c\033[32m", map->cells[30].show_char);
  } else if (map->cells[30].owner == 3) // S Blue
  {
    printf("\033[34m%c\033[34m", map->cells[30].show_char);
  } else if (map->cells[30].owner == 4) // J Yellow
  {
    printf("\033[33m%c\033[33m", map->cells[30].show_char);
  } else // no owner
  {
    printf("\033[0m%c\033[0m", map->cells[30].show_char);
  }

  printf("\n");

  // 第四行
  if (map->cells[67].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[67].show_char);
  }

  else if (map->cells[67].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[67].show_char);
  }

  else if (map->cells[67].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[67].show_char);
  }

  else if (map->cells[67].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[67].show_char);
  } else {
    printf("\033[0m%c\033[0m", map->cells[67].show_char);
  }

  for (int i = 0; i < 27; i++) {
    printf(" ");
  }

  // printf("%c", map->cells[31].show_char);
  if (map->cells[31].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[31].show_char);
  }

  else if (map->cells[31].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[31].show_char);
  }

  else if (map->cells[31].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[31].show_char);
  }

  else if (map->cells[31].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[31].show_char);
  }

  else if (map->cells[31].owner == 1) // Q Red
  {
    printf("\033[31m%c\033[31m", map->cells[31].show_char);
  } else if (map->cells[31].owner == 2) // A Green
  {
    printf("\033[32m%c\033[32m", map->cells[31].show_char);
  } else if (map->cells[31].owner == 3) // S Blue
  {
    printf("\033[34m%c\033[34m", map->cells[31].show_char);
  } else if (map->cells[31].owner == 4) // J Yellow
  {
    printf("\033[33m%c\033[33m", map->cells[31].show_char);
  } else // no owner
  {
    printf("\033[0m%c\033[0m", map->cells[31].show_char);
  }

  printf("\n");

  // 第五行
  if (map->cells[66].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[66].show_char);
  }

  else if (map->cells[66].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[66].show_char);
  }

  else if (map->cells[66].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[66].show_char);
  }

  else if (map->cells[66].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[66].show_char);
  } else {
    printf("\033[0m%c\033[0m", map->cells[66].show_char);
  }

  for (int i = 0; i < 27; i++) {
    printf(" ");
  }

  // printf("%c", map->cells[32].show_char);
  if (map->cells[32].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[32].show_char);
  }

  else if (map->cells[32].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[32].show_char);
  }

  else if (map->cells[32].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[32].show_char);
  }

  else if (map->cells[32].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[32].show_char);
  }

  else if (map->cells[32].owner == 1) // Q Red
  {
    printf("\033[31m%c\033[31m", map->cells[32].show_char);
  } else if (map->cells[32].owner == 2) // A Green
  {
    printf("\033[32m%c\033[32m", map->cells[32].show_char);
  } else if (map->cells[32].owner == 3) // S Blue
  {
    printf("\033[34m%c\033[34m", map->cells[32].show_char);
  } else if (map->cells[32].owner == 4) // J Yellow
  {
    printf("\033[33m%c\033[33m", map->cells[32].show_char);
  } else // no owner
  {
    printf("\033[0m%c\033[0m", map->cells[32].show_char);
  }

  printf("\n");

  // 第六行
  if (map->cells[65].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[65].show_char);
  }

  else if (map->cells[65].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[65].show_char);
  }

  else if (map->cells[65].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[65].show_char);
  }

  else if (map->cells[65].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[65].show_char);
  } else {
    printf("\033[0m%c\033[0m", map->cells[65].show_char);
  }

  for (int i = 0; i < 27; i++) {
    printf(" ");
  }

  // printf("%c", map->cells[33].show_char);
  if (map->cells[33].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[33].show_char);
  }

  else if (map->cells[33].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[33].show_char);
  }

  else if (map->cells[33].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[33].show_char);
  }

  else if (map->cells[33].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[33].show_char);
  }

  else if (map->cells[33].owner == 1) // Q Red
  {
    printf("\033[31m%c\033[31m", map->cells[33].show_char);
  } else if (map->cells[33].owner == 2) // A Green
  {
    printf("\033[32m%c\033[32m", map->cells[33].show_char);
  } else if (map->cells[33].owner == 3) // S Blue
  {
    printf("\033[34m%c\033[34m", map->cells[33].show_char);
  } else if (map->cells[33].owner == 4) // J Yellow
  {
    printf("\033[33m%c\033[33m", map->cells[33].show_char);
  } else // no owner
  {
    printf("\033[0m%c\033[0m", map->cells[33].show_char);
  }

  printf("\n");

  // 第七行
  if (map->cells[64].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[64].show_char);
  }

  else if (map->cells[64].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[64].show_char);
  }

  else if (map->cells[64].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[64].show_char);
  }

  else if (map->cells[64].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[64].show_char);
  } else {
    printf("\033[0m%c\033[0m", map->cells[64].show_char);
  }

  for (int i = 0; i < 27; i++) {
    printf(" ");
  }

  // printf("%c", map->cells[34].show_char);
  if (map->cells[34].show_char == 'Q') // 最高优先级，如果钱夫人站在这，显示红色
  {
    printf("\033[31m%c\033[31m", map->cells[34].show_char);
  }

  else if (map->cells[34].show_char ==
           'A') // 次优先级，如果阿土伯站在这，显示绿色
  {
    printf("\033[32m%c\033[32m", map->cells[34].show_char);
  }

  else if (map->cells[34].show_char ==
           'S') // 再次优先级，如果孙小美站在这，显示蓝色
  {
    printf("\033[34m%c\033[34m", map->cells[34].show_char);
  }

  else if (map->cells[34].show_char ==
           'J') // 最次优先级，如果金贝贝站在这，显示黄色
  {
    printf("\033[33m%c\033[33m", map->cells[34].show_char);
  }

  else if (map->cells[34].owner == 1) // Q Red
  {
    printf("\033[31m%c\033[31m", map->cells[34].show_char);
  } else if (map->cells[34].owner == 2) // A Green
  {
    printf("\033[32m%c\033[32m", map->cells[34].show_char);
  } else if (map->cells[34].owner == 3) // S Blue
  {
    printf("\033[34m%c\033[34m", map->cells[34].show_char);
  } else if (map->cells[34].owner == 4) // J Yellow
  {
    printf("\033[33m%c\033[33m", map->cells[34].show_char);
  } else // no owner
  {
    printf("\033[0m%c\033[0m", map->cells[34].show_char);
  }

  printf("\n");

  // 第八行
  for (int i = 63; i > 34; i--) {
    // printf("%c", map->cells[i].show_char);
    if (map->cells[i].show_char ==
        'Q') // 最高优先级，如果钱夫人站在这，显示红色
    {
      printf("\033[31m%c\033[31m", map->cells[i].show_char);
    }

    else if (map->cells[i].show_char ==
             'A') // 次优先级，如果阿土伯站在这，显示绿色
    {
      printf("\033[32m%c\033[32m", map->cells[i].show_char);
    }

    else if (map->cells[i].show_char ==
             'S') // 再次优先级，如果孙小美站在这，显示蓝色
    {
      printf("\033[34m%c\033[34m", map->cells[i].show_char);
    }

    else if (map->cells[i].show_char ==
             'J') // 最次优先级，如果金贝贝站在这，显示黄色
    {
      printf("\033[33m%c\033[33m", map->cells[i].show_char);
    }

    else if (map->cells[i].owner == 1) // Q Red
    {
      printf("\033[31m%c\033[31m", map->cells[i].show_char);
    } else if (map->cells[i].owner == 2) // A Green
    {
      printf("\033[32m%c\033[32m", map->cells[i].show_char);
    } else if (map->cells[i].owner == 3) // S Blue
    {
      printf("\033[34m%c\033[34m", map->cells[i].show_char);
    } else if (map->cells[i].owner == 4) // J Yellow
    {
      printf("\033[33m%c\033[33m", map->cells[i].show_char);
    } else // no owner
    {
      printf("\033[0m%c\033[0m", map->cells[i].show_char);
    }
  }
  printf("\n");
}
