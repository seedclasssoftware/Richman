/**
 * @file main.c
 * @author 王一赫 (wyihe5220@gmail.com)
 * @brief KMP算法的实现实验
 * @version 0.1
 * @date 2024-05-31
 * 
 * @copyright copyright (c) 2024
 *   Licensed to the Apache Software Foundation (ASF) under one
 *   or more contributor license agreements.  See the NOTICE file
 *   distributed with this work for additional information
 *   regarding copyright ownership.  The ASF licenses this file
 *   to you under the Apache License, Version 2.0 (the
 *   "License"); you may not use this file except in compliance
 *   with the License.  You may obtain a copy of the License at
 *  
 *     http://www.apache.org/licenses/LICENSE-2.0
 *  
 *   Unless required by applicable law or agreed to in writing,
 *   software distributed under the License is distributed on an
 *   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *   KIND, either express or implied.  See the License for the
 *   specific language governing permissions and limitations
 *   under the License.
 * 
 */

#include <stdio.h>
#include "kmp.h"
#include <string.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char *s = "ababcabcacbab";
    char *p = "aaaaaaaab";
    Str str1 = {strlen(s), s};
    Str str2 = {strlen(p), p};
    const int strlen2 = str1.len;
    int next[strlen2];
    GetNext(str2, next);
    printf("next:");
    for (int i = 0; i < str2.len; i++)
    {
        printf("%d ", next[i]);
    }
    printf("\n");
    int pos = KMP(str1, str2, next);
    printf("pos = %d\n", pos);
    return 0;
}