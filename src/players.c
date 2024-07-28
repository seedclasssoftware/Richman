#include "players.h"
#include "map.h"
#include <cjson/cjson.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getPlayerName(uint8_t number) {
  switch (number) {
  case QIAN_Madam:
    return "钱夫人";
  case ATUB:
    return "阿土伯";
  case SUN_Miss:
    return "孙小姐";
  case JIN_Bei:
    return "金贝贝";
  default:
    return "未知";
  }
}

void initializePlayers(const char *json_data, Players players[],
                       int num_players, Map *map) {
  // printf("json_data: %s\n", json_data);
  cJSON *root = cJSON_Parse(json_data);
  if (!root) {
    printf("Error parsing JSON data.\n");
    return;
  }
  // printf("JSON 解析成功\n");

  cJSON *map_json = cJSON_GetObjectItem(root, "MAP");
  if (!map_json) {
    printf("Error: MAP object not found.\n");
    cJSON_Delete(root);
    return;
  }
  cJSON *tool_array = cJSON_GetObjectItem(map_json, "tool");
  if (tool_array) {
    int tool_count = cJSON_GetArraySize(tool_array);
    for (int i = 0; i < tool_count; i++) {
      cJSON *tool_item = cJSON_GetArrayItem(tool_array, i);
      if (tool_item && cJSON_GetArraySize(tool_item) == 2) {
        int position = cJSON_GetArrayItem(tool_item, 0)->valueint;
        int tool_type = cJSON_GetArrayItem(tool_item, 1)->valueint;
        map->cells[position].has_tool = tool_type;
      }
    }
  }

  cJSON *user_item = cJSON_GetObjectItem(root, "user");
  const char *user = cJSON_GetStringValue(user_item);
  // printf("user: %s\n", user ? user : "null");

  cJSON *now_user_item = cJSON_GetObjectItem(root, "now_user");
  const char *now_user_name = cJSON_GetStringValue(now_user_item);
  // printf("now_user: %s\n", now_user_name ? now_user_name : "null");

  cJSON *players_array = cJSON_GetObjectItem(root, "players");
  if (!players_array) {
    // printf("Error: players array not found.\n");
    cJSON_Delete(root);
    return;
  }
  int player_count = cJSON_GetArraySize(players_array);
  // printf("player_count: %d\n", player_count);

  for (int i = 0; i < num_players; i++) {
    players[i].isPlaying = 0;
  }

  for (int i = 0; i < player_count; i++) {
    cJSON *player_json = cJSON_GetArrayItem(players_array, i);
    if (!player_json)
      continue;

    int player_number = cJSON_GetObjectItem(player_json, "number")->valueint;
    int player_index = player_number - 1;
    // printf("player_number: %d\n", player_number);

    if (player_index >= 0 && player_index < num_players) {
      players[player_index].isPlaying = 1;
      players[player_index].money =
          cJSON_GetObjectItem(player_json, "money")->valueint;
      players[player_index].point =
          cJSON_GetObjectItem(player_json, "point")->valueint;
      players[player_index].number = player_number;
      players[player_index].block =
          cJSON_GetObjectItem(player_json, "tool1")->valueint;
      players[player_index].robot =
          cJSON_GetObjectItem(player_json, "tool2")->valueint;
      players[player_index].bomb =
          cJSON_GetObjectItem(player_json, "tool3")->valueint;
      players[player_index].god =
          cJSON_GetObjectItem(player_json, "buff")->valueint;
      players[player_index].prison =
          cJSON_GetObjectItem(player_json, "continue")->valueint;
      players[player_index].hospital =
          cJSON_GetObjectItem(player_json, "debuff0")->valueint;
      players[player_index].magic =
          cJSON_GetObjectItem(player_json, "debuff1")->valueint;
      players[player_index].position =
          cJSON_GetObjectItem(player_json, "position")->valueint;
      players[player_index].isBankrupt =
          cJSON_GetObjectItem(player_json, "alive")->valueint == 0;

      // 分配玩家名称
      players[player_index].name = getPlayerName(player_number);
      printf("player_index: %d, name: %s, money: %u\n", player_index,
             players[player_index].name, players[player_index].money);

      memset(players[player_index].properties, 0,
             sizeof(players[player_index].properties));
      cJSON *properties_array = cJSON_GetObjectItem(player_json, "properties");
      if (properties_array) {
        int properties_count = cJSON_GetArraySize(properties_array);
        for (int j = 0; j < properties_count; j++) {
          cJSON *property_item = cJSON_GetArrayItem(properties_array, j);
          if (property_item && cJSON_GetArraySize(property_item) == 2) {
            int prop_position = cJSON_GetArrayItem(property_item, 0)->valueint;
            int prop_value = cJSON_GetArrayItem(property_item, 1)->valueint;
            players[player_index].properties[prop_position] = prop_value;
          }
        }
      }
    }
    extern Map map;
    // 添加同步players.properties与map.cells
    for (int i = 0; i < 70; i++) {
      if (map.cells[i].kind != 4) {
        map.cells[i].kind =
            (players[0].properties[i] | players[1].properties[i] |
             players[2].properties[i] | players[3].properties[i]);
      }
      if (players[0].properties[i]) {
        map.cells[i].owner = 1;
      } else if (players[1].properties[i]) {
        map.cells[i].owner = 2;
      } else if (players[2].properties[i]) {
        map.cells[i].owner = 3;
      } else if (players[3].properties[i]) {
        map.cells[i].owner = 4;
      } else {
        map.cells[i].owner = 0;
      }
    }
  }

  for (int i = 0; i < num_players; i++) {
    if (players[i].isPlaying && players[i].name &&
        strcmp(players[i].name, now_user_name) == 0) {
      now_user = &players[i];
      break;
    }
  }
  // printf("初始化成功\n");
  cJSON_Delete(root);
}

extern Map map;

void printPlayers(Players players[], int num_players) {
  for (int i = 0; i < num_players; i++) {
    Players *player = &players[i];
    printf("玩家%d:\n", player->number);
    printf("名字：%s\n", player->name);
    printf("金钱：%d\n", player->money);
    printf("点数：%d\n", player->point);
    printf("编号：%d\n", player->number);
    printf("障碍：%d\n", player->block);
    printf("机器娃娃：%d\n", player->robot);
    printf("炸弹：%d\n", player->bomb);
    printf("财神：%d\n", player->god);
    printf("财神持续回合：%d\n", player->god);
    printf("监狱：%d\n", player->prison);
    printf("医院：%d\n", player->hospital);
    printf("魔法：%d\n", player->magic);
    printf("位置：%d\n", player->position);
    printf("是否参与游戏：%d\n", player->isPlaying);
    printf("是否破产：%d\n", player->isBankrupt);
    printf("资产：");
    for (int i = 0; i < 70; i++) {
      if (map.cells[i].owner == now_user->number) {
        printf("%d ,", i);
      }
    }
    printf("\n");
  }
}

void print_from_file() {
  FILE *fp = fopen(".res/users.json", "r");
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
  // 打印玩家信息
  printPlayers(players, 4);
}

/**
 * @brief 将玩家信息转换为 JSON 字符串
 *
 * @param players
 * @param num_players
 * @param map
 * @param now_user
 * @return char*
 */
char *convertToJson(Players players[], int num_players, Map *map,
                    pPlayers now_user) {
  cJSON *root = cJSON_CreateObject();

  // 添加 MAP
  cJSON *map_json = cJSON_CreateObject();
  cJSON *tool_array = cJSON_CreateArray();
  for (int i = 0; i < 70; i++) {
    if (map->cells[i].has_tool != 0) {
      cJSON *tool_item = cJSON_CreateArray();
      cJSON_AddItemToArray(tool_item, cJSON_CreateNumber(i));
      cJSON_AddItemToArray(tool_item,
                           cJSON_CreateNumber(map->cells[i].has_tool));
      cJSON_AddItemToArray(tool_array, tool_item);
    }
  }
  cJSON_AddItemToObject(map_json, "tool", tool_array);
  cJSON_AddItemToObject(root, "MAP", map_json);

  // 添加 now_user
  cJSON_AddStringToObject(root, "now_user", &now_user->cap);

  // 添加 user 字段
  char user_string[5] = "";
  if (players[QIAN_Madam - 1].isPlaying)
    strcat(user_string, "1");
  if (players[ATUB - 1].isPlaying)
    strcat(user_string, "2");
  if (players[SUN_Miss - 1].isPlaying)
    strcat(user_string, "3");
  if (players[JIN_Bei - 1].isPlaying)
    strcat(user_string, "4");
  cJSON_AddStringToObject(root, "user", user_string);

  // 添加 players
  cJSON *players_array = cJSON_CreateArray();
  for (int i = num_players; i >= 0; i--) {
    if(i < num_players && i >= 0)
    {
      if (players[i].isPlaying) {
        cJSON *player_json = cJSON_CreateObject();
        cJSON_AddNumberToObject(player_json, "number", players[i].number);
        cJSON_AddNumberToObject(player_json, "money", players[i].money);
        cJSON_AddNumberToObject(player_json, "point", players[i].point);
        cJSON_AddNumberToObject(player_json, "tool1", players[i].block);
        cJSON_AddNumberToObject(player_json, "tool2", players[i].robot);
        cJSON_AddNumberToObject(player_json, "tool3", players[i].bomb);
        cJSON_AddNumberToObject(player_json, "buff", players[i].god);
        cJSON_AddNumberToObject(player_json, "continue", players[i].prison);
        cJSON_AddNumberToObject(player_json, "debuff0", players[i].hospital);
        cJSON_AddNumberToObject(player_json, "debuff1", players[i].magic);
        cJSON_AddNumberToObject(player_json, "position", players[i].position);
        cJSON_AddNumberToObject(player_json, "alive", !players[i].isBankrupt);
        extern Map map;
        cJSON *properties_array = cJSON_CreateArray();
        for (int j = 0; j < 70; j++) {
          if ((map.cells[j].owner - 1) == i) {
            cJSON *property_item = cJSON_CreateArray();
            cJSON_AddItemToArray(property_item, cJSON_CreateNumber(j));
            cJSON_AddItemToArray(property_item,
                                 cJSON_CreateNumber(map.cells[j].kind == 4
                                                        ? 0
                                                        : map.cells[j].kind));
            cJSON_AddItemToArray(properties_array, property_item);
          }
        }
        cJSON_AddItemToObject(player_json, "properties", properties_array);

        cJSON_AddItemToArray(players_array, player_json);
      }
    }
  }
  cJSON_AddItemToObject(root, "players", players_array);

  // 转换为字符串
  char *json_string = cJSON_Print(root);
  cJSON_Delete(root);

  return json_string;
}
