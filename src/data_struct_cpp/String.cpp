#include "String.hpp"

String::String(){
    this->list = List<char>();
}

String::String(const char* str){
    this->concat(str);
}

String::String(const String& other){
    this->list = other.list;
}

String& String::operator=(const String& other){
    if(this == &other)return *this;
    this->list = other.list;
    return *this;
}

String& String::operator+=(const String& other){
    for(auto it = other.list.begin(); it!= other.list.end(); it = it->next){
        this->list.insert_tail(it->data);
    }
    return *this;
}

String String::operator+(const String& other)const{
   String res;
   for(auto it = this->list.begin(); it!= this->list.end(); it = it->next){
        res.list.insert_tail(it->data);
   }
   for(auto it = other.list.begin(); it!= other.list.end(); it = it->next){
        res.list.insert_tail(it->data);
   }
   return res;
}

void String::concat(const char* str){
    if(str == nullptr)return;
    while(*str){
        list.insert_tail(*str);
        ++str;
    }
}

void String::concat(const char& ch){
    list.insert_tail(ch);
}

char* String::get_str()const{
    char* str = new char[list.size()];
    int i = 0;
    for(auto it = list.begin(); it != list.end(); it = it->next){
        str[i] = it->data;
        ++i;
    }
    return str;
}

char String::at(int index)const{
    if(index < 0 || index >= list.size())return '\0';
    auto it = list.begin();
    for(int i = 0; i < index; ++i)it = it->next;
    return it->data;
}

char String::operator[](int index)const{
    return this->at(index);
}

int String::size()const{
    return list.size();
}

int String::compare(const String& other)const{
    auto it1 = this->list.begin();
    auto it2 = other.list.begin();
    while(it1 != this->list.end() && it2 != other.list.end()){
        if(it1->data < it2->data)return -1;
        if(it1->data > it2->data)return 1;
        it1 = it1->next;
        it2 = it2->next;
    }
    if(it1 == this->list.end() && it2 == other.list.end())return 0;
    if(it1 == this->list.end())return -1;
    return 1;
}

bool String::operator==(const String& other)const{
    return this->compare(other) == 0;
}

bool String::operator!=(const String& other)const{
    return this->compare(other) != 0;
}

bool String::operator<(const String& other)const{
   return this->compare(other) == -1;
}

bool String::operator>(const String& other)const{
   return this->compare(other) == 1;
}

std::ostream& operator<<(std::ostream& os, const String& str){
    for(auto it = str.list.begin(); it!= str.list.end(); it = it->next){
        os << it->data;
    }
    return os;
}

String String::substr(int start, int len)const{
   if(len < 0 || start < 0 || start >= list.size() || start + len > list.size())return String();
   String res;
   for(int i = start; i < start + len; ++i){
       res.list.insert_tail(this->at(i));
   }
   return res;
}

int String::index(const String& str)const{
   if(str.size() == 0 || str.size() > this->size())return -1;
   auto it1 = this->list.begin();
   auto it2 = str.list.begin();
   Node<char>* t = it1;
   int i = 0;
   int index = 0;
   while(it1!= this->list.end() && it2!= str.list.end()){
      if(it1->data == it2->data){
        it1 = it1->next;
        it2 = it2->next;
        ++i;
      }else{
        it1 = t->next;
        t = it1;
        i = index + 1;
        index = i;
        it2 = str.list.begin();
      }
   }
   if(it2 == str.list.end())return index;
   return -1;
}


int* String::next_array()const{
    int *next = new int[this->size()];
    next[0] = -1;
    int i = 0;
    int j = -1;
    while(i < this->size()){
        if( j == -1 || this->at(i) == this->at(j) ){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    return next;
}

int String::index_kmp(const String& str)const{
    int *str_next = str.next_array();
    int i = 0;
    int j = 0;
    while(i < this->size() && j < str.size()){
        if( j == -1 || this->at(i) == str.at(j) ){
            ++i;
            ++j;
        }else{
            j = str_next[j];
        }
    }
    if(j == str.size())return i - str.size();
    return -1;
}