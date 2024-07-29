#include "god_appear.h"
#include "map.h"
#include "players.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 财神爷出现倒计时
int god_countdown = 0;
int god_position = -1;

void god_appear(Map *map) {
  srand((unsigned)time(NULL));
  int god_position = rand() % 70;
  while ((map->cells[god_position].kind == 4) ||
         (map->cells[god_position].has_tool != 0) ||
         (map->cells[god_position].show_char == 'Q') ||
         (map->cells[god_position].show_char == 'A') ||
         (map->cells[god_position].show_char == 'S') ||
         (map->cells[god_position].show_char == 'J')) {
    god_position = rand() % 70;
  }
  map->cells[god_position].show_char = 'F';
  map->cells[god_position].has_tool = 3;
  // 打印白色转义符
  printf("\033[0m");
  printf("财神爷出现在位置 %d\n", god_position);
}
void god_init(int player_count) { // 初始化财神爷出现的倒计时
  srand((unsigned)time(NULL));
  god_countdown = (rand() % 11) + 10;
  god_countdown = god_countdown * player_count;
}

void god_time(Map *map, Players players[], int player_count) {
  int all_players = 0;
  for (int i = 0; i < player_count; i++) {
    if (players[i].isPlaying || players[i].isBankrupt) {
      all_players++;
    }
  }

  static int god_timer = 5;

  if (god_countdown > 0) {
    god_countdown--;
    // 打印白色转义符
    printf("\033[0m");
    printf("距离财神爷出现还有 %d 轮\n", god_countdown / all_players);
    if (god_countdown == 0) {
      god_appear(map);
    }
  } else if (god_position != -1) {
    for (int i = 0; i < player_count; i++) {
      if (players[i].isPlaying && players[i].position == god_position) {
        players[i].god = 1;
        map->cells[god_position].show_char = map->cells[god_position].init_char;
        god_position = -1;
        printf("%s 捡到了财神爷\n", players[i].name);

        // 重置倒计时和计时器
        // srand((unsigned)time(NULL));
        // god_countdown = (rand() % 11) + 10;
        god_init(player_count);

        god_timer = 5;
        return; // 这里使用 return 来结束函数，避免后续计时器的处理
      }
    }

    if (god_position != -1) {
      god_timer--;
      if (god_timer == 0) {
        map->cells[god_position].show_char = map->cells[god_position].init_char;
        printf("财神爷消失了\n");
        god_position = -1;
        god_timer = 5;
        // 重置倒计时
        // srand((unsigned)time(NULL));
        // god_countdown = (rand() % 11) + 10;
        god_init(player_count);
      }
    }
  }
}
