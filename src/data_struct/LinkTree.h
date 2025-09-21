#ifndef LINKTREE_H
#define LINKTREE_H



typedef struct TreeNode 
{
    char data;
    struct TreeNode* left, * right;
}t_node, *l_tree;

void InitTree(l_tree *tree);
void CreateTree(l_tree *tree);
void PreOrder(l_tree tree);
void InOrder(l_tree tree);
void PostOrder(l_tree tree);
void LevelOrder(l_tree tree);
void DestroyTree(l_tree *tree);
void Visit(l_tree tree);

#endif