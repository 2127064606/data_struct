#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include "Queue.hpp"

template <typename T>
struct TreeNode{
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(){}
    TreeNode(const T&data):data(data),left(nullptr),right(nullptr){}

};


template <typename T>
class Tree{
    private:
        TreeNode<T>* root;
        void create(TreeNode<T>*& root);
    public:
        Tree(){ root = nullptr; }
        Tree(bool create);
        ~Tree(){}
        void preorder(TreeNode<T>* root)const;
        void inorder(TreeNode<T>* root)const;
        void postorder(TreeNode<T>* root)const;
        void levelorder()const;
        void visit(TreeNode<T>* root)const;
        TreeNode<T>* get_root()const{ return root; }
};

template <typename T>
void Tree<T>::create(TreeNode<T>*& root){
    T data;
    std::cin >> data;
    std::cin.clear();
    if(data == '#'){
        root = nullptr;
        return;
    }
    root = new TreeNode<T>(data);
    create(root->left);
    create(root->right);
}

template <typename T>
Tree<T>::Tree(bool create){
    if(!create)return;
    this->create(this->root);
}

template <typename T>
void Tree<T>::preorder(TreeNode<T>* root)const{
    if(!root)return;
    visit(root);
    preorder(root->left);
    preorder(root->right);
}

template <typename T>
void Tree<T>::inorder(TreeNode<T>* root)const{
    if(!root)return;
    inorder(root->left);
    visit(root);
    inorder(root->right);
}

template <typename T>
void Tree<T>::postorder(TreeNode<T>* root)const{
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    visit(root);
}

template <typename T>
void Tree<T>::levelorder()const{
    if(!root)return;
    Queue<TreeNode<T>*> q;
    q.enqueue(root);
    while(!q.empty()){
        TreeNode<T>* t = q.front();
        q.dequeue();
        visit(t);
        if(t->left)q.enqueue(t->left);
        if(t->right)q.enqueue(t->right);
    }
}

template <typename T>
void Tree<T>::visit(TreeNode<T>* root)const{
    if(!root)return;
    std::cout << root->data << " ";
}

#endif