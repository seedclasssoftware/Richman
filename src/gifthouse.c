#include<stdio.h>
#include "gifthouse.h"

void gifthouse_event_process(Players *player)
{
    printf("Welcome to the gift house!\n");

    printf("You have 3 choices:\n");
    printf("1. 2000 money\n");
    printf("2. 200 points\n");
    printf("3. 1 godBuff\n");
    printf("Please input your choice(1-3): ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            player->money += 2000;
            break;

        case 2:
            player->point += 200;
            break;

        case 3:
            player->god = 5;
            break;

    }

    printf("You have got your gift!\n");
}