typedef struct Cell{
    char show_char;//字符
    int kind;//地的种类
    int rank;//地段
    int has_tool;//道具
} Cell;

typedef struct Map{
    Cell cells[70];
} Map;
