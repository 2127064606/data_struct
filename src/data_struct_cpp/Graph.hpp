#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "List.hpp"
#include "Queue.hpp"
#include <map>

template <typename T>
struct Vertex {
    T value;
    List<T> adj; // 存放邻接点的链表
    Vertex(){}
    Vertex(const T& v) : value(v) {}
    Vertex<T>& operator=(const Vertex<T>& other){
        if(this == &other)return *this;
        value = other.value;
        adj = other.adj;
        return *this;
    }
      Vertex(const Vertex& other) : value(other.value), adj(other.adj) {}

};

template <typename T>
class Graph {
    private:
        List<Vertex<T>> tables;
    public:
        Graph() {};
        ~Graph() {};
        void add_vertex(const T& value);
        void add_edge(const T& v1, const T& v2); //有向图
        bool adj_acent(const T& from, const T& to);
        List<T> neighbors(const T& v);
        T first_nerighbor(const T& v);
        T next_nerighbor(const T& v, const T& w);
        void bfs(const T& start, std::map<T, bool>& visited, void (*visit)(const T&));
        void bfsTraveral(void(*visit)(const T&));
        void print()const;
};


template <typename T>
void Graph<T>::add_vertex(const T& value){
    Vertex<T> v(value);
    tables.insert_head(v);
}
template <typename T>
void Graph<T>::add_edge(const T& v1, const T& v2){
    auto it = tables.begin();
    while(it != tables.end()){
        if(it->data.value == v1){
            it->data.adj.insert_head(v2);
        }
        it = it->next;
    }
}
template <typename T>
void Graph<T>::print() const{
    auto it = tables.begin();
    while(it!= tables.end()){
        std::cout << it->data.value << "->";
        it->data.adj.print();
        it = it->next;
    }
}

template <typename T>
bool Graph<T>::adj_acent(const T& from, const T& to){
    auto it = tables.begin();
    while(it != tables.end()){
        if(it->data.value == from){
        Vertex<T> v = it->data;
        auto it2 = v.adj.begin();
        while(it2 != v.adj.end()){
            if(it2->data == to)return true;
            it2 = it2->next;
        }
            return false;
        }
        it = it->next;
    }
    return false;
}

template <typename T>
List<T> Graph<T>::neighbors(const T& v){
    auto it = tables.begin();
    while(it != tables.end()){
        if(it->data.value == v){
            return it->data.adj;
        }
        it = it->next;
    }
    return List<T>();
}

template <typename T>
T Graph<T>::first_nerighbor(const T& v){
    auto it = tables.begin();
    while(it != tables.end()){
        if(it->data.value == v && !it->data.adj.empty())return it->data.adj.begin()->data;
        it = it->next;
    }
    return T();
}

template <typename T>
T Graph<T>::next_nerighbor(const T& v, const T& w){
    auto it = tables.begin();
    while(it != tables.end()){
        if(it->data.value == v){
            Vertex<T> vt = it->data;
            auto it2 = vt.adj.begin();
            while(it2 != vt.adj.end()){
                if(it2->data == w && it2->next!= nullptr)return it2->next->data;
                it2 = it2->next;
            }
            return T();
        }
        it = it->next;
    }
    return T();
}

template <typename T>
void Graph<T>::bfs(const T& start, std::map<T, bool>& visited, void (*visit)(const T&)){
    Queue<T> q;
    visit(start);
    q.enqueue(start);
    visited[start] = true;
    while(!q.empty()){
        T v = q.front();
        q.dequeue();
        for(auto it = first_nerighbor(v); it != T(); it = next_nerighbor(v, it)){
           if(!visited[it]){
                visit(it);
                visited[it] = true;
                q.enqueue(it);
           }
        }
    }
}

template <typename T>
void Graph<T>::bfsTraveral(void(*visit)(const T&)){
    std::map<T, bool>visited;
    auto it = tables.begin();
    while(it != tables.end()){
        visited[it->data.value] = false;
        it = it->next;
    }
    for(auto pt = visited.begin(); pt != visited.end(); pt++){  // 去掉 & 符号
        if(!pt->second){
            bfs(pt->first, visited, visit);
        }
    }
}

#endif