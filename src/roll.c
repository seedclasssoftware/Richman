#include "players.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int roll_num() {
    // 使用当前时间作为种子
    srand(time(NULL));

    // 生成1到6之间的随机数
    int random_number = rand() % 6 + 1;

    

    return 0;
}