#include "earthup.h"


int is_your_earth(Players player,Cell* cells)
{
    if(cells[player.position].owner==player.number)
    {
        return 1;
    }
    else
        return 0;
}

void earth_up(pPlayers player,Cell* cells)
{
    if(is_your_earth(*player,cells)==1)
    {
        if(cells[(*player).position].kind==0||cells[(*player).position].kind==1||cells[(*player).position].kind==2)
        {
            if (cells[(*player).position].rank == 1 && (*player).money < 200)
                return;
            else if (cells[(*player).position].rank == 2 && (*player).money < 500)
                return;
            else if (cells[(*player).position].rank == 3 && (*player).money < 300)
                return;
            else
            {
                printf("请问是否需要升级您的地产!\n");
                printf("1.升级\n");
                printf("2.不升级\n");
                while(1)
                {
                    char c;
                    char if_earth_up;
                    if_earth_up = getchar();
                    if(if_earth_up=='1')
                    {
                        if(cells[(*player).position].rank == 1)
                        {
                            (*player).money -= 200;
                            cells[(*player).position].kind += 1;
                            return;
                        }
                        else if(cells[(*player).position].rank == 2)
                        {
                            (*player).money -= 500;
                            cells[(*player).position].kind += 1;
                            return;
                        }
                        else if(cells[(*player).position].rank == 3)
                        {
                            (*player).money -= 300;
                            cells[(*player).position].kind += 1;
                            return;
                        }
                    }
                    else if(if_earth_up=='2')
                    {
                        return;
                    }
                    else
                    {
                        printf("输入错误！\n");
                        while ((c = getchar()) != EOF && c != '\n');
                        continue;
                    }
                }
            }
        }
    }
}