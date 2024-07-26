typedef struct Cell{
    char show_char;
    int kind;
    int rank;
    int has_tool;
} Cell;

typedef struct Map{
    Cell cells[70];
} Map;
