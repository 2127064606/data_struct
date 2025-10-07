#include "List.hpp"

template <typename T>
List<T>::List()
{
    head = new Node<T>();
    head->next = nullptr;
    _size = 0;
}

template <typename T>
List<T>::~List()
{
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
    return j;
}

template <typename T>
int List<T>::size() const { return _size; }