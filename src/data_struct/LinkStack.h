#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef struct LinkStack
{
    int data;
    struct LinkStack *next;  
}s_node, *link_stack;


void InitStack_L(link_stack *s);
void Push_L(link_stack *s, int e);
int Pop_L(link_stack *s);
int GetTop_L(link_stack s);
int isEmpty_L(link_stack s);
void PrintStack_L(link_stack s);

#endif