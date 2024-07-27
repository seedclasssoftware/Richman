#include "useprops.h"
#include "players.h"
#include "map.h"
#include <stdio.h>

void useprops(Players *player, Map *map)
{
    printf("do you want to use props?\n");
    printf("0.do not use\n");
    printf("1.block\n");
    printf("2.robot\n");
    printf("3.bomb\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (player->block > 0)
            {
                printf("please select a position to place your block:-10~10\n");
                int place_position;
                scanf("%d", &place_position);
                map->cells[player->position+place_position].has_tool = 1;
                printf("you have used block\n");
                player->block--;

                //map->cells[player->position].has_tool = 1;
            }
            else
            {
                printf("you do not have block\n");
            }
            break;

        case 2:
            if (player->robot > 0)
            {
                printf("you have used robot\n");
                player->robot--;
                for (int i = 0; i < 10; i++)
                {
                    if(map->cells[i].has_tool == 3)
                    {
                        map->cells[i].has_tool = 0;
                    }
                }
            }
            else
            {
                printf("you do not have robot\n");
            }
            break;

        case 3:
            if (player->bomb > 0)
            {
                printf("you have used bomb\n");
                player->bomb--;
                map->cells[player->position].has_tool = 3;
            }
            else
            {
                printf("you do not have bomb\n");
            }
            break;

        default:
            break;
    }


}