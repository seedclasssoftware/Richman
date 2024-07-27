/**
 * author： 史少博
 */
#include "earthup.h"


int is_your_earth(Players player,Cell* cells)
{
    if((*cells).owner==player.number)
    {
        return 1;
    }
    else
        return 0;
}

void earth_up(pPlayers player,Cell* cells)
{
    //判断是否为当前角色的土地
    if(is_your_earth(*player,cells)==1)       
    {
        //判断当前土地的种类是否为空地、茅屋或洋房
        if((*cells).kind==0||(*cells).kind==1||(*cells).kind==2)
        {
            //如果是第一地段但当前资金小于200则退出
            if ((*cells).rank == 1 && (*player).money < 200)
                return;
            //如果是第二地段但当前资金小于500则退出
            else if ((*cells).rank == 2 && (*player).money < 500)
                return;
            //如果是第三地段但当前资金小于300则退出
            else if ((*cells).rank == 3 && (*player).money < 300)
                return;
            else
            {
                printf("请问是否需要升级您的地产!\n");
                printf("y.升级\n");
                printf("n.不升级\n");
                printf("y.升级\n");
                printf("n.不升级\n");
                while(1)
                {
                    char c;
                    char if_earth_up;
                    if_earth_up = getchar();
                    //选择升级地产
                    if(if_earth_up=='y' && getchar()=='\n')
                    {
                        if((*cells).rank == 1)
                        {
                            (*player).money -= 200;
                            (*cells).kind += 1;
                            return;
                        }
                        else if((*cells).rank == 2)
                        {
                            (*player).money -= 500;
                            (*cells).kind += 1;
                            return;
                        }
                        else if((*cells).rank == 3)
                        {
                            (*player).money -= 300;
                            (*cells).kind += 1;
                            return;
                        }
                    }
                    //选择不升级地产
                    else if(if_earth_up=='n' && getchar()=='\n')
                    {
                        return;
                    }
                    //输入错误
                    else
                    {
                        printf("输入错误！\n");
                        printf("y.升级\n");
                        printf("n.不升级\n");
                        printf("y.升级\n");
                        printf("n.不升级\n");
                        while ((c = getchar()) != EOF && c != '\n');
                        continue;
                    }
                }
            }
        }
    }
}

void test_earth_up(void)
{
    printf("hell0 world!\n");
    Map map_for_earth_up_test;
    map_init(&map_for_earth_up_test);
    
    map_print(&map_for_earth_up_test);
    
    Players player_use_for_test_earth_up;
    player_use_for_test_earth_up.money=699;
    player_use_for_test_earth_up.number=1;
    player_use_for_test_earth_up.position=6;

    map_for_earth_up_test.cells[5].owner=1;
    map_for_earth_up_test.cells[5].rank=2;
    map_for_earth_up_test.cells[5].kind=2;
    earth_up(&player_use_for_test_earth_up,&(map_for_earth_up_test.cells[5]));
    printf("%d,%d,%d,%d\n",map_for_earth_up_test.cells[5].owner,map_for_earth_up_test.cells[5].rank,map_for_earth_up_test.cells[5].kind,player_use_for_test_earth_up.money);
    
}
