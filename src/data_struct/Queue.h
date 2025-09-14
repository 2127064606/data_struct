#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10

typedef struct Queue
{
    int data[MAX];
    int front;
    int rear;
    int size;
}queue;

void InitQueue(queue *q);
void EnQueue(queue *q, int e);
int DeQueue(queue *q);
int Front(queue q);
bool IsEmpty(queue q);
void PrintQueue(queue q);

#endif