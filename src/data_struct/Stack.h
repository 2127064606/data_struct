#ifndef STACK_H
#define STACK_H

#define MAXSIZE 1000
typedef struct Stack
{
    int data[MAXSIZE];
    int top;
}stack;

void InitStack(stack *s);
void Push(stack *s, int e);
int Pop(stack *s);
int GetTop(stack *s);
bool isEmpty(stack *s);
void PrintStack(stack *s);

#endif