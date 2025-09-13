#include "BLinkList.h"
#include <stdio.h>
#include <stdlib.h>

void InitBLinkList(b_link_list *L)
{
    *L = (b_link_list)malloc(sizeof(b_node));
    (*L)->prior = NULL;
    (*L)->next = NULL;
    b_node* move = *L;
    int i;
    scanf("%d", &i);
    for(int j = 0; j < i; j++)
    {
        b_node *p = (b_node*)malloc(sizeof(b_node));
        scanf("%d", &p->data);
        p->prior = move;
        p->next = move->next;
        move->next = p;
        move = p;
    }
    move->next = NULL;
    printf("success\n");

}
bool InsertBNode(b_link_list L, int i, int e)
{
    if(i < 1)return false;
    b_node *move = L;
    int j = 0;
    while(j < i-1 && move)
    {
        move = move->next;
        j++;
    }
    if(!move)return false;
    b_node *newNode = (b_node*)malloc(sizeof(b_node));
    newNode->data = e;
    newNode->prior = move;
    newNode->next = move->next;
    if(move->next)move->next->prior = newNode;
    move->next = newNode;
    return true;
}
bool DeleteBNode(b_link_list L, int i, int *e)
{
    if(i < 1)return false;
    b_node *move = L;
    int j = 0;
    while(j < i && move)
    {
        move = move->next;
        j++;
    }
    if(!move)return false;
    if(e)
    *e = move->data;
    move->prior->next = move->next;
    if(move->next)move->next->prior = move->prior;
   // free(move);
    return true;
}
b_node *GetBNode(b_link_list L, int i)
{
    if(i < 1)return NULL;
    b_node *move = L;
    int j = 0;
    while(j < i && move)
    {
        move = move->next;
        j++;
    }
    return move;
}
int GetBNodeByValue(b_link_list L, int e)
{
    int j = 1;
    while(L->next && L->next->data != e)
    {
        L = L->next;
        j++;
    }
    if(!L->next)return -1;
    return j;
}

void PrintBLinkList(b_link_list L)
{
    while(L->next)
    {
        printf("%d ", L->next->data);
        L = L->next;
    }
    printf("\n");
}