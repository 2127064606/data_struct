#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

void InitLinkNode(link_list *L, int n)
{
    *L = (link_list)malloc(sizeof(link_node));
    (*L)->next = NULL;
    link_list move = *L;
    for (int i = 0; i < n; i++)
    {
        link_list temp = (link_list)malloc(sizeof(link_node));
        int e;
        scanf("%d", &e);
        temp->data = e;
        temp->next = move->next;
        move->next = temp;
        move = temp;
    }
}
int ListInsert_L(link_list *L, int i, int e)
{
    if (i < 1)
        return -1;
    link_list move = *L;
    int j = 0;
    while (j < i - 1 && move->next)
    {
        move = move->next;
        ++j;
    }

    if (!move)
        return -1;
    link_list temp = (link_list)malloc(sizeof(link_node));
    temp->data = e;
    temp->next = move->next;
    move->next = temp;
}
int GetElem_L(link_list L, int i)
{
    if (i < 1)
        return INT_MIN;
    int j = 0;
    link_list move = L->next;
    while (j < i && move->next)
    {
        j++;
        move = move->next;
    }
    if (!move)
        return INT_MIN;
    return move->data;
}

int GetLength_L(link_list *L)
{
    int j = 0;
    link_list move = *L;
    while (move->next)
        ++j;
    return j;
}

int ListDelete_L(link_list *L, int i, int *e)
{
    if (i < 1)
        return -1;
    int j = 0;
    link_list move = *L;
    while (j++ < i - 1 && move->next)
        move = move->next;
    if (!move->next)
        return -1;
    *e = move->next->data;
    link_list temp = move->next;
    move->next = move->next->next;
    free(temp);
    temp = NULL;
    return 1;
}

void MergeList_L(link_list *l1, link_list *l2, link_list *l3)
{
    if (l3 == NULL)
        return;
    link_list p1 = (*l1)->next;
    link_list p2 = (*l2)->next;
    link_list p3 = *l3;
    while (p1 && p2)
    {
        if (p1->data <= p2->data)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
        p3->next = p1 ? p1 : p2;
    }
}