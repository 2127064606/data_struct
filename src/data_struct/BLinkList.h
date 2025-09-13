#ifndef BLINKLIST_H
#define BLINKLIST_H


typedef struct BLinkList
{
    int data;
    struct BLinkList *prior;
    struct BLinkList *next;
}b_node,*b_link_list;


void InitBLinkList(b_link_list *L);
bool InsertBNode(b_link_list, int i, int e);
bool DeleteBNode(b_link_list L, int i, int *e);
b_node *GetBNode(int i);
int GetBNodeByValue(int e);

#endif