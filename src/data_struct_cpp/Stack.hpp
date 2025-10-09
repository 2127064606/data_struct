#ifndef STACK_HPP
#define STACK_HPP
#include "List.hpp"
template <class T>
class Stack{
    private:
        List<T> list;
    public:
        Stack();
        ~Stack();
        void push(T data);
        void pop();
        T top();
        int size();
        bool empty();
        void clear();
};

template <typename T>
Stack<T>::Stack(){
   
}

template <typename T>
Stack<T>::~Stack(){
    list.~List();
}

template <typename T>
void Stack<T>::push(T data){
    list.insert_head(data);
}

template <typename T>
void Stack<T>::pop(){
    list.remove_head();
}
template <typename T>
T Stack<T>::top(){
    return list.get_head();
}

template <typename T>
int Stack<T>::size(){
    return list.size();
}

template <typename T>
bool Stack<T>::empty(){
    return list.size() == 0;
}

template <typename T>
void Stack<T>::clear(){
    while(!empty()){
        pop();
    }
}

#endif