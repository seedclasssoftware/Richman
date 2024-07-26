# include "players.h"
# include <cjson/cjson.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


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
            players[i].name = NULL; // Name is not provided in JSON
            players[i].money = cJSON_GetObjectItem(player_json, "money")->valueint;
            players[i].point = cJSON_GetObjectItem(player_json, "point")->valueint;
            players[i].number = cJSON_GetObjectItem(player_json, "number")->valueint;
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