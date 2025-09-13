#ifndef LINKLIST_H
#define LINKLIST_H


typedef struct LinkList {
    int data;
    struct LinkList *next;
}link_node, *link_list;


void InitLinkNode(link_list *L, int n);
int ListInsert_L(link_list *L, int i, int e);
int GetElem_L(link_list L, int i);
int ListDelete_L(link_list *L, int i, int *e);
void MergeList_L(link_list *l1, link_list *l2, link_list *l3);


#endif