#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    int _size;

public:
    List();
    List<T>& operator=(const List<T> &other);
    ~List();
    void insert(int index, const T &data);
    void insert_head(const T &data);
    void insert_tail(const T &data);
    void remove_head();
    int remove(int index, T &data);
    int remove(const T &data);
    int size() const;
    T get(int index) const;
    T get_head() const;
    T get_tail() const;
    void clear();
    Node<T> *begin()const{ return head->next; }
    Node<T> *end()const{ return tail->next; }
};

template <typename T>
List<T>::List()
{
    head = new Node<T>();
    tail = head;
    head->next = nullptr;
    _size = 0;
}

template <typename T>
List<T>::~List()
{
    Node<T> *p = head;
    Node<T> *t = p;
    while (p != nullptr)
    {
        p = p->next;
        delete t;
        t = p;
    }
    head = tail = nullptr;
}

template <typename T>
void List<T>::insert(int index, const T &data)
{
    if (index < 1 || index > _size + 1)
        return;
    Node<T> *p = head;
    int j = 0;
    while (j < index - 1 && p != nullptr)
    {
        p = p->next;
        ++j;
    }
    Node<T> *s = new Node<T>();
    s->data = data;
    s->next = p->next;
    p->next = s;
    ++_size;
    if (s->next == nullptr)
        tail = s;
}
template <typename T>
int List<T>::remove(int index, T &data)
{
    if (index < 1 || index > _size)
        return 0;
    Node<T> *p = head;
    int j = 0;
    while (j < index - 1 && p != nullptr)
    {
        p = p->next;
        ++j;
    }
    Node<T> *t = p->next;
    p->next = t->next;
    data = t->data;
    delete t;
    --_size;
    if (p->next == nullptr)
        tail = p;
    return 1;
}

template <typename T>
int List<T>::remove(const T &data)
{
    if (head->next == nullptr)
        return 0;
    Node<T> *p = head;
    int j = 1;
    while (p->next != nullptr && p->next->data != data)
    {
        p = p->next;
        ++j;
    }
    if (p->next == nullptr)
        return 0;
    Node<T> *t = p->next;
    p->next = t->next;
    delete t;
    --_size;
    if (p->next == nullptr)
        tail = p;
    return j;
}

template <typename T>
int List<T>::size() const { return _size; }

template <typename T>
T List<T>::get(int index) const
{
    if (index < 1 || index > _size)
        return 0;
    Node<T> *p = head;
    int j = 0;
    while (j++ < index && p != nullptr)
        p = p->next;
    return p->data;
}

template <typename T>
void List<T>::clear(){
    Node<T> *p = head->next;
    Node<T> *t = p;
    while(p != nullptr){
        p = p->next;
        delete t;
        t = p;
        --_size;
    }
    head->next = nullptr;
    tail = head;
}

template <typename T>
void List<T>::insert_head(const T &data){
    Node<T> *s = new Node<T>();
    s->data = data;
    s->next = head->next;
    head->next = s;
    ++_size;
    if(s->next == nullptr)tail = s;
}

template <typename T>
void List<T>::insert_tail(const T &data){
    Node<T> *s = new Node<T>();
    s->data = data;
    s->next = nullptr;
    tail->next = s;
    tail = s;
    ++_size;
}

template <typename T>
T List<T>::get_head() const{
  
  return head->next->data;
}

template <typename T>
T List<T>::get_tail() const{
    return tail->data;
}

template <typename T>
void List<T>::remove_head(){
    if(head->next == nullptr)return;
    Node<T> *p = head->next;
    head->next = p->next;
    delete p;
    --_size;
    if(head->next == nullptr)tail = head;
}


template <typename T>
List<T>& List<T>::operator=(const List<T> &other){
    if(this == &other)return *this;
    clear();
    auto it = other.begin();
    while(it != other.end()){
        insert_tail(it->data);
        it = it->next;
    }
    return *this;
}
#endif