#include "players.h"
#include <cjson/cjson.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *getPlayerName(wanjia[i]->number) {
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
                       int num_players) {
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
        player->god =
            cJSON_GetObjectItem(player_json, "buff")->valueint
                ? cJSON_GetObjectItem(player_json, "continue")->valueint
                : 0;
        player->prison =
            cJSON_GetObjectItem(player_json, "debuff0")->valueint
                ? cJSON_GetObjectItem(player_json, "decontinue")->valueint
                : 0;
        player->hospital =
            cJSON_GetObjectItem(player_json, "debuff1")->valueint
                ? cJSON_GetObjectItem(player_json, "decontinue")->valueint
                : 0;
        player->magic = 0; // Assuming 'magic' is not provided in JSON
        player->position =
            cJSON_GetObjectItem(player_json, "position")->valueint;
        // properties not implemented
      }
    }
  }

  cJSON_Delete(json);
}

void printPlayers(Players players[], int num_players) {
  for (int i = 0; i < num_players; i++) {
    Players *player = &players[i];
    printf("玩家%d:\n", player->number);
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

void chooseRoll(char players[]){
    
    printf("请选择2~4位不重复玩家，输入编号即可（1、钱夫人；2、阿土伯；3、孙小美；4、金贝贝；），如输入：12");
    int len=0;
    while(1){
        scanf("%s",players);
        len=strlen(players);
        int num[5];
        for(int i=0;i<len;i++){
            num[(int)(players[i])]++;
        }
        if(len>=2&&len<=4&&num[1]<=1&&num[2]<=1&&num[3]<=1&&num[4]<=1){
            break;
        }
        else {
            printf("您的输入不符合标准，请重新输入！");
            players[0]='\0';
        }
    }
    for(int i=0;i<len;i++){
        wanjia[i]=(pPlayers)malloc(sizeof(Players));
        wanjia[i]->name=(char*)malloc(sizeof(char)*50);
        wanjia[i]->money=initMoney;
        wanjia[i]->point=0;
        wanjia[i]->number=i;
        wanjia[i]->block=0;
        wanjia[i]->robot=0;
        wanjia[i]->bomb=0;
        wanjia[i]->god=0;
        wanjia[i]->prison=0;
        wanjia[i]->hospital=0;
        wanjia[i]->magic=0;
        wanjia[i]->position=0;
        wanjia[i]->name=names[(int)(players[i])];
    }
    printf("您选择的角色是：");
    for(int i=0;i<len;i++){
        
        printf("%s ",wanjia[i]->name);
    }
    return;
}
void init_money(){
    printf("请输入初始金额(1000-50000)，直接按回车默认为10000:");
    while(1){
        scanf("%d",&initMoney);
        if(initMoney>=1000&&initMoney<=50000){
            break;
        }
    }
    printf("初始金额为：%d",initMoney);
}

