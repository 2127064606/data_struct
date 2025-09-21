#include "Mstr.h"
#include <stdio.h>
#include <stdlib.h>

void InitStr(m_str *str)
{
    for(int i = 0; i < MAX_S; i++)
    {
        str->data[i] = ' ';
    }
    str->size = 0;
}
void Concat(m_str *str, char ch)
{
    str->data[str->size++] = ch;
}
char* To_String(m_str *str)
{
   return str->data;
}

void PrintStr(m_str str)
{
    for(int i = 0; i < str.size; i++)
    {
        printf("%c", str.data[i]);
    }
    printf("\n");
}
char CharAt(m_str str, int index)
{
    if(index < 0 || index >= str.size)return '\0';
    return str.data[index-1];
}
bool SubString(m_str *sub, m_str src, int pos, int len)
{
    if(pos < 0 || pos >= src.size || len < 0 || len + pos > src.size)return false;
    for(int i = pos; i < pos + len; i++)
    {
        sub->data[sub->size++] = src.data[i];
    }
    return true;
}
int StrCompare(m_str s, m_str t)
{
    int i = 0;
    while(i < s.size && i < t.size)
    {
        if(s.data[i] != t.data[i])
          return s.data[i] - t.data[i];
        i++;
    }
    return s.size - t.size;
}
int Index(m_str s, m_str t)
{
    int i = 0;
    while(i < s.size - t.size + 1)
    {
        m_str sub;
        InitStr(&sub);
        SubString(&sub, s, i, t.size);
        if(StrCompare(sub, t) == 0)return i;
        i++;
    }
    return -1;
}

int *GetNextArr(m_str t)
{
    if(t.size == 0) return NULL;
    int *next = (int *)malloc(sizeof(int) * t.size);
    next[0] = -1; // 第一个字符的next值为-1
    next[1] = 0;
    int i = 1;
    int j = 0;
    
    while(i < t.size)
    {
        if(j == -1 || t.data[i] == t.data[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    
    return next;
}
int Index_KMP(m_str s, m_str t, int next[])
{
    int i = 0;
    int j = 0;
    while(i < s.size && j < t.size)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == t.size)return i - t.size;
    else return -1;
}
