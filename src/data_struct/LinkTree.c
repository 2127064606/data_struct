#include "LinkTree.h"
#include <stdio.h>
#include <stdlib.h>

void InitTree(l_tree *tree)
{
    *tree = NULL;
}
void CreateTree(l_tree *tree)
{
    char ch;
    scanf("%c", &ch); 
    getchar();  
    printf("current char:%c\n", ch);
    if(ch == '#')return;
    *tree = (l_tree)malloc(sizeof(t_node));
     (*tree)->left = NULL;
     (*tree)->right = NULL;
     (*tree)->data = ch;
     CreateTree(&(*tree)->left);
     CreateTree(&(*tree)->right);
}
void PreOrder(l_tree tree)
{
    if(tree)
    {
        Visit(tree);
        PreOrder(tree->left);
        PreOrder(tree->right);
    }
   
}
void InOrder(l_tree tree)
{
    if(tree)
    {
        InOrder(tree->left);
        Visit(tree);
        InOrder(tree->right);
    }
   
}
void PostOrder(l_tree tree)
{
    if(tree)
    {
        PostOrder(tree->left);
        PostOrder(tree->right);
        Visit(tree);
    }
  
}
void LevelOrder(l_tree tree)
{
    l_tree q[200];
    int front = 0, rear = 0;
    if(tree)q[rear++] = tree;
    while(front != rear)
    {
        l_tree top = q[front++];
        Visit(top);
        if(top->left)q[rear++] = top->left;
        if(top->right)q[rear++] = top->right;
    }
}
void DestroyTree(l_tree *tree)
{

}

void Visit(l_tree tree)
{
    if(tree)
    printf("%c", tree->data);
}