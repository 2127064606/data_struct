#include "Stack.h"
#include <stdio.h>

void InitStack(stack *s)
{
    s->top = -1;
}
void Push(stack *s, int e)
{
    if(s->top == MAXSIZE-1)return;
    s->data[++s->top] = e;
}
int Pop(stack *s)
{
    if(s->top == -1)return -1;
    return s->data[s->top--];
}
int GetTop(stack *s)
{
    if(isEmpty(s))return -1;
    return s->data[s->top];
}
bool isEmpty(stack *s)
{
    return s->top == -1;
}

void PrintStack(stack *s)
{
    while(!isEmpty(s))
    {
        printf("%d ", Pop(s));
    }
    printf("\n");
}