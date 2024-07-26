#include "players.h"
#include <cjson/cjson.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *getPlayerName(uint8_t number) {
  switch (number) {
  case QIAN_Madam:
    return "钱夫人";
  case ATUB:
    return "阿土伯";
  case SUN_Miss:
    return "孙小姐";
  case JIN_Bei:
    return "金贝";
  default:
    return "未知";
  }
}

void initializePlayers(const char *json_data, Players players[], int num_players) {
    cJSON *json = cJSON_Parse(json_data);
    if (!json) {
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *players_json = cJSON_GetObjectItem(json, "players");
    if (!players_json || !cJSON_IsArray(players_json)) {
        printf("Error getting players array\n");
        cJSON_Delete(json);
        return;
    }

    int array_size = cJSON_GetArraySize(players_json);
    for (int i = 0; i < array_size; i++) {
        cJSON *player_json = cJSON_GetArrayItem(players_json, i);
        if (player_json) {
            int player_number = cJSON_GetObjectItem(player_json, "number")->valueint;
            if (player_number >= 1 && player_number <= num_players) {
                Players *player = &players[player_number - 1];
                player->number = player_number;
                player->name = getPlayerName(player->number);
                player->money = cJSON_GetObjectItem(player_json, "money")->valueint;
                player->point = cJSON_GetObjectItem(player_json, "point")->valueint;
                player->block = cJSON_GetObjectItem(player_json, "tool1")->valueint;
                player->robot = cJSON_GetObjectItem(player_json, "tool2")->valueint;
                player->bomb = cJSON_GetObjectItem(player_json, "tool3")->valueint;
                player->god = cJSON_GetObjectItem(player_json, "buff")->valueint ? cJSON_GetObjectItem(player_json, "continue")->valueint : 0;
                player->prison = cJSON_GetObjectItem(player_json, "debuff0")->valueint ? cJSON_GetObjectItem(player_json, "decontinue")->valueint : 0;
                player->hospital = cJSON_GetObjectItem(player_json, "debuff1")->valueint ? cJSON_GetObjectItem(player_json, "decontinue")->valueint : 0;
                player->magic = 0; // Assuming 'magic' is not provided in JSON
                player->position = cJSON_GetObjectItem(player_json, "position")->valueint;
                // properties not implemented
            }
        }
    }

    cJSON_Delete(json);
}

{
  FILE *fp = fopen(".res/users.json", "r");
  if (fp == NULL) {
    printf("文件打开失败\n");
    return -1;
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
  // 初始化玩家
  Players players[4];
  initializePlayers(json_data, players, 4);
  // 打印玩家信息
  for (int i = 0; i < 4; i++) {
    printf("玩家%d:\n", i + 1);
    printf("金钱：%d\n", players[i].money);
    printf("点数：%d\n", players[i].point);
    printf("编号：%d\n", players[i].number);
    printf("障碍：%d\n", players[i].block);
    printf("机器娃娃：%d\n", players[i].robot);
    printf("炸弹：%d\n", players[i].bomb);
    printf("财神：%d\n", players[i].god);
    printf("财神持续回合：%d\n", players[i].god);
    printf("监狱：%d\n", players[i].prison);
    printf("医院：%d\n", players[i].hospital);
    printf("魔法：%d\n", players[i].magic);
    printf("位置：%d\n", players[i].position);
    printf("\n");
  }
}