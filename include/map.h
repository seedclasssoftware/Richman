#ifndef  MAP_H
#define MAP_H
typedef struct Cell{
    char show_char;
    //字符 S 起点、 T 道具屋、 $ 矿地、 H 医院
    //M 魔法屋、G 礼品屋、P 监狱、0 普通地段
    
    int kind;//地的种类  0 空地 1 茅屋 2 洋房 3 摩天楼 特殊建筑为4
    int rank;//地段      1 地段一 2 地段二 3 地段三
    int has_tool;//道具  1 路障、3 炸弹、0 没有道具
    int owner;//地主     1,2,3,4 0表示无主
} Cell;

typedef struct Map{
    Cell cells[70];
} Map;

#endif