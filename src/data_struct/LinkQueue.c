#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>
// 不带头结点的链式队列
void InitLinkQueue(link_queue *q)
{
    if (q == NULL)
        q = (link_queue *)malloc(sizeof(link_queue));
    q->front = q->rear = NULL;
    q->size = 0;
}
void EnQueue_L(link_queue *q, int e)
{
    link_node *p = (link_node *)malloc(sizeof(link_node));
    p->data = e;
    p->next = NULL;
    if (q->size == 0)
    {
        q->front = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
    q->size++;
}
int DeQueue_L(link_queue *q)
{
    if(q->size == 0)return -1;
    int e = q->front->data;
    link_node *p = q->front;
    if(q->front == q->rear)
        q->rear = q->front = NULL;
    else
        q->front = q->front->next;
    q->size--;
    free(p);
    return e;
}
int Front_L(link_queue q)
{
    if(q.size == 0)return -1;
    return q.front->data;
}
int IsEmpty_L(link_queue q)
{
    return q.size == 0;
}
void PrintQueue_L(link_queue q)
{
    while(!IsEmpty_L(q))
    {
        printf("%d ", DeQueue_L(&q));
    }
    printf("\n");
}