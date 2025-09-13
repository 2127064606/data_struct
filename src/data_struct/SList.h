#ifndef SLIST_H
#define SLIST_H

#define MAX_SIZE 1000

typedef struct SList{
    int data;
    int cur;
}s_node,s_list[MAX_SIZE];

void InitSList(s_list L);
int Malloc_SL(s_list L);
void Free_SL(s_list L, int k);
#endif