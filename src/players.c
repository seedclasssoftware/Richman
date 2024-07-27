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

// void initializePlayers(const char *json_data, Players players[],
//                        int num_players) {
//   cJSON *json = cJSON_Parse(json_data);
//   if (!json) {
//     printf("Error parsing JSON\n");
//     return;
//   }

//   cJSON *players_json = cJSON_GetObjectItem(json, "players");
//   if (!players_json || !cJSON_IsArray(players_json)) {
//     printf("Error getting players array\n");
//     cJSON_Delete(json);
//     return;
//   }

//   int array_size = cJSON_GetArraySize(players_json);
//   for (int i = 0; i < array_size; i++) {
//     cJSON *player_json = cJSON_GetArrayItem(players_json, i);
//     if (player_json) {
//       int player_number = cJSON_GetObjectItem(player_json,
//       "number")->valueint; if (player_number >= 1 && player_number <=
//       num_players) {
//         Players *player = &players[player_number - 1];
//         player->number = player_number;
//         player->name = getPlayerName(player->number);
//         player->money = cJSON_GetObjectItem(player_json, "money")->valueint;
//         player->point = cJSON_GetObjectItem(player_json, "point")->valueint;
//         player->block = cJSON_GetObjectItem(player_json, "tool1")->valueint;
//         player->robot = cJSON_GetObjectItem(player_json, "tool2")->valueint;
//         player->bomb = cJSON_GetObjectItem(player_json, "tool3")->valueint;
//         player->god =
//             cJSON_GetObjectItem(player_json, "buff")->valueint
//                 ? cJSON_GetObjectItem(player_json, "continue")->valueint
//                 : 0;
//         player->prison =
//             cJSON_GetObjectItem(player_json, "debuff0")->valueint
//                 ? cJSON_GetObjectItem(player_json, "decontinue")->valueint
//                 : 0;
//         player->hospital =
//             cJSON_GetObjectItem(player_json, "debuff1")->valueint
//                 ? cJSON_GetObjectItem(player_json, "decontinue")->valueint
//                 : 0;
//         player->magic = 0; // Assuming 'magic' is not provided in JSON
//         player->position =
//             cJSON_GetObjectItem(player_json, "position")->valueint;
//         // properties not implemented
//       }
//     }
//   }

//   cJSON_Delete(json);
// }

// 辅助函数，用于解析玩家属性
void parsePlayer(cJSON *player_json, Players *player, const char *player_name) {
  player->name = malloc(strlen(player_name) + 1);
  strcpy(player->name, player_name);
  player->money = cJSON_GetObjectItem(player_json, "money")->valueint;
  player->point = cJSON_GetObjectItem(player_json, "point")->valueint;
  player->number = cJSON_GetObjectItem(player_json, "number")->valueint;
  player->block = cJSON_GetObjectItem(player_json, "tool1")->valueint;
  player->robot = cJSON_GetObjectItem(player_json, "tool2")->valueint;
  player->bomb = cJSON_GetObjectItem(player_json, "tool3")->valueint;
  player->god = cJSON_GetObjectItem(player_json, "buff")->valueint;
  player->prison = cJSON_GetObjectItem(player_json, "continue")->valueint;
  player->hospital = cJSON_GetObjectItem(player_json, "debuff0")->valueint;
  player->magic = cJSON_GetObjectItem(player_json, "debuff1")->valueint;
  player->position = cJSON_GetObjectItem(player_json, "position")->valueint;
}

void initializePlayers(const char *json_data, Players players[],
                       int num_players, Map *map) {
  // 解析 JSON 数据
  cJSON *root = cJSON_Parse(json_data);
  if (root == NULL) {
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL) {
      fprintf(stderr, "Error before: %s\n", error_ptr);
    }
    return;
  }

  // 获取 players 对象
  cJSON *players_json = cJSON_GetObjectItem(root, "players");
  if (players_json == NULL) {
    fprintf(stderr, "Error: players object not found in JSON data.\n");
    cJSON_Delete(root);
    return;
  }

  // 获取 JIN_Bei 的值
  cJSON *jin_bei_json = cJSON_GetObjectItem(players_json, "JIN_Bei");
  if (jin_bei_json == NULL) {
    fprintf(stderr, "Error: JIN_Bei object not found in JSON data.\n");
    cJSON_Delete(root);
    return;
  }

  // 遍历 players 对象并初始化 Players 结构体数组
  int index = 0;
  cJSON *player_json = NULL;
  cJSON_ArrayForEach(player_json, players_json) {
    const char *player_name = player_json->string;
    if (index >= num_players) {
      break;
    }
    if (player_name) {
      // 根据 JIN_Bei 键的值选择初始化
      if (strcmp(player_name, "JIN_Bei") == 0) {
        parsePlayer(jin_bei_json, &players[index], player_name);
      } else {
        parsePlayer(player_json, &players[index], player_name);
      }
      index++;
    }
  }

  // 获取 MAP 对象
  cJSON *map_json = cJSON_GetObjectItem(root, "MAP");
  if (map_json == NULL) {
    fprintf(stderr, "Error: MAP object not found in JSON data.\n");
    cJSON_Delete(root);
    return;
  }

  // 获取 tool 数组并填充 Map
  cJSON *tool_array = cJSON_GetObjectItem(map_json, "tool");
  if (tool_array != NULL && cJSON_IsArray(tool_array)) {
    int tool_count = cJSON_GetArraySize(tool_array);
    for (int i = 0; i < tool_count; i++) {
      cJSON *tool_item = cJSON_GetArrayItem(tool_array, i);
      if (cJSON_IsArray(tool_item)) {
        cJSON *index_item = cJSON_GetArrayItem(tool_item, 0);
        cJSON *tool_type_item = cJSON_GetArrayItem(tool_item, 1);
        if (cJSON_IsNumber(index_item) && cJSON_IsNumber(tool_type_item)) {
          int index = index_item->valueint;
          int tool_type = tool_type_item->valueint;
          if (index >= 0 && index < 70) {
            map->cells[index].has_tool = tool_type;
          }
        }
      }
    }
  }

  cJSON_Delete(root);
}

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
  cJSON_AddStringToObject(root, "now_user", now_user->name);

  // 添加 players
  cJSON *players_json = cJSON_CreateObject();
  for (int i = 0; i < num_players; i++) {
    cJSON *player_json = cJSON_CreateObject();
    cJSON_AddNumberToObject(player_json, "money", players[i].money);
    cJSON_AddNumberToObject(player_json, "point", players[i].point);
    cJSON_AddNumberToObject(player_json, "number", players[i].number);
    cJSON_AddNumberToObject(player_json, "tool1", players[i].block);
    cJSON_AddNumberToObject(player_json, "tool2", players[i].robot);
    cJSON_AddNumberToObject(player_json, "tool3", players[i].bomb);
    cJSON_AddNumberToObject(player_json, "buff", players[i].god);
    cJSON_AddNumberToObject(player_json, "continue", players[i].prison);
    cJSON_AddNumberToObject(player_json, "debuff0", players[i].hospital);
    cJSON_AddNumberToObject(player_json, "debuff1", players[i].magic);
    cJSON_AddNumberToObject(player_json, "position", players[i].position);

    cJSON_AddItemToObject(players_json, players[i].name, player_json);
  }
  cJSON_AddItemToObject(root, "players", players_json);

  char *json_string = cJSON_Print(root);
  cJSON_Delete(root);

  return json_string;
}