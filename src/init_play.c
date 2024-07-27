#include <stdio.h>
#include <stdlib.h>
#include "init_play.h"
#include "players.h"
#include <string.h>
#include<stdint.h>

char *player_names[] = {
    "钱夫人",
    "阿土伯",
    "孙小美",
    "金贝贝"
};

char *player_colors[] = {
    "\033[31m", // 红色
    "\033[32m", // 绿色
    "\033[34m", // 蓝色
    "\033[33m"  // 黄色
};


void init_money(uint32_t *initMoney) {
    char input[100]; // 用来存储用户输入
    printf("请输入初始金额(1000-50000)，直接按回车默认为10000: ");
    
    // 获取输入
    fgets(input, sizeof(input), stdin);
    
    // 判断用户是否输入了值
    if (input[0] == '\n') {
        *initMoney = 10000; // 默认值
    } else {
        *initMoney = atoi(input); // 将输入的字符串转换为整数
        // 检查输入是否在有效范围内
        while (*initMoney < 1000 || *initMoney > 50000) {
            printf("输入无效，请输入初始金额(1000-50000)，直接按回车默认为10000: ");
            fgets(input, sizeof(input), stdin);
            if (input[0] == '\n') {
                *initMoney = 10000; // 默认值
                break;
            } else {
                *initMoney = atoi(input); // 转换为整数
            }
        }
    }
    printf("初始金额为：%d\n", *initMoney);
}

void select_players(Players *players, int *selected_players, int num_players, uint32_t init_money) {
    char input[100];
    int count = 0;

    // 初始化所有角色
    for (int i = 0; i < 4; i++) {
        players[i].name = player_names[i];
        players[i].money = init_money;
        players[i].point = 0;
        players[i].number = i + 1;
        players[i].block = 0;
        players[i].robot = 0;
        players[i].bomb = 0;
        players[i].god = 0;
        players[i].prison = 0;
        players[i].hospital = 0;
        players[i].magic = 0;
        players[i].position = 0;
    }

    printf("请选择2-4位不重复玩家，输入编号即可(1、钱夫人;2、阿土伯;3、孙小美;4、金贝贝;),如输入:12: ");
    for (int i = 0; i < 4; i++) {
        printf("(%s%d、%s%s\033[0m); ", player_colors[i], i + 1, player_colors[i], player_names[i]);
    }
    printf("\n");
    //循环直到用户输入有效的玩家编号
    while (count < 2 || count > 4) {
        fgets(input, sizeof(input), stdin); //获取输入
        count = 0;
        int valid = 1;
        int selected[4] = {0};

        // 遍历输入的每个字符
        for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
            int index = input[i] - '1'; // 将字符转换为索引
            // 检查编号是否有效且未被选择
            if (index < 0 || index > 3 || selected[index] == 1) {
                valid = 0; // 标记为无效输入
                break;
            }
            selected[count] = index; // 存储有效编号
            count++;
        }

        // 检查输入是否有效且选择的玩家数量在2-4之间
        if (!valid || count < 2 || count > 4) {
            printf("您的输入有错误，请重新输入: ");
            count = 0; // 重置计数器以重新输入
        } else {
            printf("您选择的角色是: ");
            for (int i = 0; i < count; i++) {
                selected_players[i] = selected[i]; // 存储选择的玩家编号
                // 打印选择的玩家名字和颜色
                printf("%s%s\033[0m ", player_colors[selected[i]], players[selected[i]].name);
            }
            printf("\n");
        }
    }
}