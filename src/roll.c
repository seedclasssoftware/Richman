#include "players.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int roll_num() {
    // 使用当前时间作为种子
    srand(time(NULL));
    // 生成1到6之间的随机数
    int steps = rand() % 6 + 1;
    return steps;
}

void change_position(pPlayers now_user,int steps){
    printf("当前你色子的点数为：%d\n",steps);
    printf("你");
}