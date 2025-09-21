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
#include "./data_struct/LinkTree.h"

bool compare(int a, int b) { return a == b; }



int main()
{
    l_tree *tree;
    InitTree(tree);
    CreateTree(tree);
    PreOrder(*tree);    
    printf("\n");
    InOrder(*tree);
    printf("\n");
    PostOrder(*tree);
    printf("\n");
    LevelOrder(*tree);
    printf("\n");
}
