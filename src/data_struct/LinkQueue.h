#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "LinkList.h"

typedef struct LinkQueue
{
    link_node *front;
    link_node *rear;
    int size;
}link_queue;

void InitLinkQueue(link_queue *q);
void EnQueue_L(link_queue *q, int e);
int DeQueue_L(link_queue *q);
int Front_L(link_queue q);
int IsEmpty_L(link_queue q);
void PrintQueue_L(link_queue q); 

#endif