#include "map.h"
#include <stdio.h>

void map_init(Map *map)
{
    //初始化show_char
    for (int i = 0; i < 70; i++)
    {
        map->cells[i].show_char = '0';
        map->cells[i].kind = 0;
        map->cells[i].rank = 0;
        map->cells[i].has_tool = 0;
        map->cells[i].owner = 0;
    }

    for (int i=64;i<70;i++ )
    {
        map->cells[i].show_char = '$';
    }

    map->cells[0].show_char = 'S';
    map->cells[28].show_char = 'T';
    map->cells[35].show_char = 'G';
    map->cells[63].show_char = 'M';
    map->cells[14].show_char = 'H';
    map->cells[49].show_char = 'P';

    //初始化kind
    map->cells[0].kind = 4;
    map->cells[28].kind = 4;
    map->cells[35].kind = 4;
    map->cells[63].kind = 4;
    map->cells[14].kind = 4;
    map->cells[49].kind = 4;

    for (int i = 64; i < 70; i++)
    {
        map->cells[i].kind = 4;
    }

    //初始化rank
    for(int i=0;i<29;i++)
    {
        map->cells[i].rank = 1;
    }

    for(int i=29;i<35;i++)
    {
        map->cells[i].rank = 2;
    }

    for(int i=35;i<64;i++)
    {
        map->cells[i].rank = 3;
    }
    
}

void map_print(Map *map)
{
    for (int i = 0; i < 29; i++)
    {
        printf("%c", map->cells[i].show_char);
    }
    printf("\n");

    //第二行
    printf("%c", map->cells[69].show_char);
    for (int i = 0; i < 27; i++)
    {
        printf(" ");
    }
    printf("%c", map->cells[29].show_char);
    printf("\n");

    //第三行
    printf("%c", map->cells[68].show_char);
    for (int i = 0; i < 27; i++)
    {
        printf(" ");
    }
    printf("%c", map->cells[30].show_char);
    printf("\n");

    //第四行
    printf("%c", map->cells[67].show_char);
    for (int i = 0; i < 27; i++)
    {
        printf(" ");
    }
    printf("%c", map->cells[31].show_char);
    printf("\n");

    //第五行
    printf("%c", map->cells[66].show_char);
    for (int i = 0; i < 27; i++)
    {
        printf(" ");
    }
    printf("%c", map->cells[32].show_char);
    printf("\n");

    //第六行
    printf("%c", map->cells[65].show_char);
    for (int i = 0; i < 27; i++)
    {
        printf(" ");
    }
    printf("%c", map->cells[33].show_char);
    printf("\n");
    
    //第七行
    printf("%c", map->cells[64].show_char);
    for (int i = 0; i < 27; i++)
    {
        printf(" ");
    }
    printf("%c", map->cells[34].show_char);
    printf("\n");

    for (int i = 63; i > 34; i--)
    {
        printf("%c", map->cells[i].show_char);
        
    }
    printf("\n");
}