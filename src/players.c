# include "players.h"
# include <cjson/cjson.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


const char* getPlayerName(uint8_t number) {
    switch (number) {
        case QIAN_Madam: return "钱夫人";
        case ATUB: return "阿土伯";
        case SUN_Miss: return "孙小姐";
        case JIN_Bei: return "金贝";
        default: return "未知";
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

    for (int i = 0; i < num_players; i++) {
        cJSON *player_json = cJSON_GetArrayItem(players_json, i);
        if (player_json) {
            players[i].number = cJSON_GetObjectItem(player_json, "number")->valueint;
            players[i].name = getPlayerName(players[i].number);
            players[i].money = cJSON_GetObjectItem(player_json, "money")->valueint;
            players[i].point = cJSON_GetObjectItem(player_json, "point")->valueint;
            players[i].block = cJSON_GetObjectItem(player_json, "tool1")->valueint;
            players[i].robot = cJSON_GetObjectItem(player_json, "tool2")->valueint;
            players[i].bomb = cJSON_GetObjectItem(player_json, "tool3")->valueint;
            players[i].god = cJSON_GetObjectItem(player_json, "buff")->valueint ? cJSON_GetObjectItem(player_json, "continue")->valueint : 0;
            players[i].prison = cJSON_GetObjectItem(player_json, "debuff0")->valueint ? cJSON_GetObjectItem(player_json, "decontinue")->valueint : 0;
            players[i].hospital = cJSON_GetObjectItem(player_json, "debuff1")->valueint ? cJSON_GetObjectItem(player_json, "decontinue")->valueint : 0;
            players[i].magic = 0; // Assuming 'magic' is not provided in JSON
            players[i].position = cJSON_GetObjectItem(player_json, "position")->valueint;
            // properties not implemented
        }
    }

    cJSON_Delete(json);
}