#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void InitList(list *L)
{
    L->data = (int *)malloc(sizeof(int) * 10);
    L->list_capacity = 10;
    L->size = 0;
    if (L->data == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }
    printf("InitList success\n");
}

int ListLength(list L)
{
    return L.size;
}

int ListInsert(list *L, int i, int e)
{
    if (i < 0 || i > L->size)
    {
        printf("i is error\n");
        return -1;
    }
    if (L->size + 1 > L->list_capacity)
    {
        int *temp = L->data;
        L->data = realloc(L->data, sizeof(int) * (L->list_capacity + 50));
        L->list_capacity += 50;
        for (int i = 0; i < L->size; i++)
        {
            L->data[i] = temp[i];
        }
        //  free(temp);
    }
    int *p = L->data + i;
    for (int j = L->size - 1; j > i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    *p = e;
    L->size++;
    return 1;
}

int GetElem(list L, int i)
{
    if (i < 0 || i > L.size)
        return INT_MIN;
    return L.data[i];
}

void MergeList(list *l1, list *l2, list *l3)
{
    int i = 0, j = 0, k = 0;
    if (l1 == NULL || l2 == NULL || l3 == NULL)
    {
        printf("l1 or l2 or l3 is NULL");
        return;
    }
    if (l3->size < l1->size + l2->size)
    {
        l3->data = realloc(l3->data, sizeof(int) * (l1->size + l2->size));
        l3->list_capacity = l1->size + l2->size;
    }
    l3->size = l1->size + l2->size;
    while (i < l1->size && j < l2->size)
    {
        if (l1->data[i] <= l2->data[j])
        {
            l3->data[k++] = l1->data[i++];
        }
        else
        {
            l3->data[k++] = l2->data[j++];
        }
    }
    while (i < l1->size)
    {
        l3->data[k++] = l1->data[i++];
    }

    while (j < l2->size)
    {
        l3->data[k++] = l2->data[j++];
    }
}

int ListDelete(list *L, int i, int *e)
{
    if (i < 0 || i > L->size)
    {
        printf("i is error\n");
        return -1;
    }
    *e = L->data[i];
    for (i; i < L->size - 1; i++)
    {
        L->data[i] = L->data[i + 1];
    }
    L->size--;
    return 1;
}

int LocateElem(list *L, int e, bool (*compare)(int, int))
{
    int i = 0;
    while (i < L->size && !(bool)compare(L->data[i], e))
        ++i;
    if (i >= L->size)
        return -1;
    return i;
}