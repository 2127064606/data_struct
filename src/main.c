#include <stdio.h>
#include "./data_struct/List.h"
#include "./data_struct/LinkList.h"
#include <stdbool.h>
#include <stdlib.h>
#include "./data_struct/value.h"
#include "./data_struct/BLinkList.h"
#include "./data_struct/Stack.h"
#include "./data_struct/LinkStack.h"
#include "./data_struct/Queue.h"
#include "./data_struct/LinkQueue.h"

bool compare(int a, int b) { return a == b; }



int main()
{
  link_queue q;
  InitLinkQueue(&q);
  EnQueue_L(&q, 1);
  EnQueue_L(&q, 2);
  EnQueue_L(&q, 3);
  EnQueue_L(&q, 4);
  EnQueue_L(&q, 5);
  PrintQueue_L(q);
}
