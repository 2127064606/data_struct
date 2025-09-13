#ifndef LIST_H
#define LIST_H

typedef struct List
{
    int *data;
    int size;
    int list_capacity;
} list;

void InitList(list *L);                       // 初始化线性表
int ListLength(list L);                       // 返回线性表的长度
int GetElem(list L, int i);                   // 返回线性表中第i个元素
int ListInsert(list *L, int i, int e);        // 在线性表第i个位置插入元素e
void MergeList(list *l1, list *l2, list *l3); // 将l1和l2合并成l3
int ListDelete(list *L, int i, int *e);       // 删除线性表第i个元素
int LocateElem(list *L, int e, bool(*compare)(int,int));               // 返回线性表中元素e的位置

#endif