#include "Queue.h"
#include <stdio.h>


void InitQueue(queue *q)
{
    q->front = q->rear = q->size = 0;
}
void EnQueue(queue *q, int e)
{
    if(q->size == MAX)return;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAX;
    q->size++;
}
int DeQueue(queue *q)
{
    if(q->size == 0)return -1;
    int e = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return e;
}
int Front(queue q)
{
    if(q.size == 0)return -1;
    return q.data[q.front];
}
bool IsEmpty(queue q)
{
    return q.size == 0;
}
void PrintQueue(queue q)
{
    while(!IsEmpty(q))
    {
        printf("%d ", DeQueue(&q));
    }
    printf("\n");
}