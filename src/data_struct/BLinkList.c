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
    
}
bool DeleteBNode(b_link_list L, int i, int *e)
{

}
b_node *GetBNode(int i)
{

}
int GetBNodeByValue(int e)
{

}