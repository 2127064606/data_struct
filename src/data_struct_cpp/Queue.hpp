#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "List.hpp"

template <class T>
class Queue{
    private:
        List<T> list;
    public:
        Queue();
        ~Queue();
        void enqueue(const T& data);
        void dequeue();
        T front()const;
        int size()const;
        bool empty()const;
        void clear();
};


template <typename T>
Queue<T>::Queue(){

}

template <typename T>
Queue<T>::~Queue(){
    list.~List();
}

template <typename T>
void Queue<T>::enqueue(const T& data){
    list.insert_tail(data);
}

template <typename T>
void Queue<T>::dequeue(){
    list.remove_head();
}

template <typename T>
T Queue<T>::front()const{
    return list.get_head();
}

template <typename T>
int Queue<T>::size()const{
    return list.size();
}

template <typename T>
bool Queue<T>::empty()const{
    return list.size() == 0;
}

template <typename T>
void Queue<T>::clear(){
    while(!empty()){
        dequeue();
    }
}
#endif