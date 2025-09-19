#ifndef MSTR_H
#define MSTR_H
#include <stdbool.h>

#define MAX_S 1000

typedef struct MStr
{
    char data[MAX_S];
    int size;
}m_str;

void InitStr(m_str *str);
void Concat(m_str *str, char ch);
char* To_String(m_str *str);
void PrintStr(m_str str);
char CharAt(m_str str, int index);
bool SubString(m_str *sub, m_str src, int pos, int len);
int StrCompare(m_str s, m_str t);
int Index(m_str s, m_str t);
int *GetNextArr(m_str t);
int Index_KMP(m_str s, m_str t, int next[]);

#endif