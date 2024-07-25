#ifndef KMP_H
#define KMP_H

/**
 * @struct STR
 * @brief 代表一个字符串及其长度的结构体
 */
struct STR {
    int len;   /**< 字符串的长度 */
    char *str; /**< 指向字符串的指针 */
};

/**
 * @typedef Str
 * @brief STR 结构体的别名
 */
typedef struct STR Str;

/**
 * @typedef pStr
 * @brief 指向 STR 结构体的指针的别名
 */
typedef struct STR *pStr;

/**
 * @brief 计算模式串的 next 数组，用于 KMP 算法
 *
 * @param[in] str 模式串
 * @param[out] next 存储模式串的 next 数组
 */
void GetNext(Str str, int *next);

/**
 * @brief 使用 KMP 算法在文本中查找模式串的位置
 *
 * @param[in] s 文本字符串
 * @param[in] p 模式字符串
 * @param[in] next 模式串的 next 数组
 * @return 模式串在文本中的起始位置，若未找到则返回 -1
 */
int KMP(Str s, Str p, int next[]);

#endif // !KMP_H
