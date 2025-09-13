#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

// 不带头结点的链栈
void InitStack_L(link_stack *s)
{
    *s = NULL;
}
void Push_L(link_stack *s, int e)
{
    s_node *p = (s_node *)malloc(sizeof(s_node));
    p->data = e;
    if (*s == NULL)
    {
        *s = p;
        p->next = NULL;
    }
    else
    {
        p->next = *s;
        *s = p;
    }
}
int Pop_L(link_stack *s)
{
    if(*s == NULL)return -1;
    int e;
    s_node *p = NULL;
    e = (*s)->data;
    p = *s;
    if((*s)->next)
      *s = p->next;
    else
      *s = NULL;
    free(p);
    return e;
}
int GetTop_L(link_stack s)
{
    if(isEmpty_L(s))return -1;
    return s->data;
}
int isEmpty_L(link_stack s)
{
    return s == NULL;
}
void PrintStack_L(link_stack s)
{
    while(s)
    {
        printf("%d ", Pop_L(&s));
    }
}