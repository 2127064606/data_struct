#include "SList.h"

void InitSList(s_list L){
    for(int i = 0; i < MAX_SIZE - 1; i++){
        L[i].cur = i + 1;
    }
    L[MAX_SIZE - 1].cur = 0;
}

int Malloc_SL(s_list L){
    int i = L[0].cur;
    if(L[0].cur)L[0].cur = L[i].cur;
    return i;
}

void Free_SL(s_list L, int k){
    L[k].cur = L[0].cur;
    L[0].cur = k;
}