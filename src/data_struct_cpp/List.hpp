#ifndef LIST_HPP
#define LIST_HPP

template<typename T>
struct Node{
    T data;
    Node<T> *next;
};

template<class T>
class List{
    private:
        Node<T> *head;
        int _size;
    public:
        List();
        ~List();
        void insert(int index, const T& data);
        int remove(int index, T&data);
        int remove(const T& data);
        int size()const;
        T get(int index)const;
};



#endif