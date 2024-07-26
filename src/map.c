void map_init(Map *map);
void map_print(Map *map);
void map_init(Map *map)
{
    for (int i = 0; i < 70; i++)
    {
        map->cells[i].show_char = '0';
        map->cells[i].kind = 0;
        map->cells[i].rank = 0;
        map->cells[i].has_tool = 0;
    }

    for (int i=64,i<70;i++ )
    {
        map->cells[i].show_char = '$';
    }

    map->cells[0].show_char = 'S';
    map->cells[28].show_char = 'T';
    map->cells[35].show_char = 'G';
    map->cells[63].show_char = 'M';
    map->cells[14].show_char = 'H';
    map->cells[49].show_char = 'P';
}

void map_print(Map *map)
{
    for (int i = 0; i < 29; i++)
    {
        printf("%c", map->cells[i].show_char);
        printf("\n");
    }

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
    printf("%c", map->cells[32].show_char);
    printf("\n");


}