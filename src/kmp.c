#include "kmp.h"

// #define DEBUG
#ifdef DEBUG
#include <stdio.h>
#endif // DEBUG

/**
 * @brief Get the Next object
 * 
 * @param p 模式串
 * @param next next数组 
 */
void GetNext(Str p, int next[])
{
    int i = 0, j = -1;
    next[0] = -1;

#ifdef DEBUG
    printf("p.len = %d\n", p.len);
    printf("next[0] = -1\n");
#endif

    while (i < p.len) {
        if (j == -1 || p.str[i] == p.str[j]) {
            i++;
            j++;
            next[i] = j;
#ifdef DEBUG
            printf("i = %d, j = %d\n", i, j);
            printf("next[%d] = %d\n", i, j);
#endif
        } else {
            j = next[j];
#ifdef DEBUG
            printf("j = next[j] = %d\n", j);
#endif
        }
    }
}

/**
 * @brief KMP算法
 * 
 * @param s 主串
 * @param p 模式串
 * @param next next数组
 * @return int 
 */
int KMP(Str s, Str p, int next[])
{
    int i = 0, j = 0;

    while (i < s.len && j < p.len) {
        if (j == -1 || s.str[i] == p.str[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    if (j == p.len) {
        return i - j;
    } else {
        return -1;
    }
}