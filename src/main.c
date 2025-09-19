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
#include "./data_struct/MStr.h"

bool compare(int a, int b) { return a == b; }



int main()
{
    // 测试KMP算法
    m_str s;
    InitStr(&s);
    Concat(&s, 'a');
    Concat(&s, 'b');
    Concat(&s, 'a');
    Concat(&s, 'b');
    Concat(&s, 'a');
    Concat(&s, 'b');
    Concat(&s, 'b');
    Concat(&s, 'b');
    m_str t;
    InitStr(&t);
    Concat(&t, 'a');
    Concat(&t, 'b');
    Concat(&t, 'a');
    printf("%d\n", Index_KMP(s, t, GetNextArr(t)));
   
}
