#ifndef STRING_HPP
#define STRING_HPP
#include "List.hpp"

class String{
    private:
        List<char> list;
    public:
        String();
        String(const char* str);
       String(const String& other);
        ~String(){}
        String& operator=(const String& other);
        String& operator+=(const String& other);
        String operator+(const String& other)const;
        bool operator==(const String& other)const;
        bool operator!=(const String& other)const;
        bool operator<(const String& other)const;
        bool operator>(const String& other)const;
        char operator[](int index)const;
        void concat(const char& ch);
        void concat(const char* str);
        char at(int index)const;
        char* get_str()const;
        int size()const;
        int compare(const String& other)const;//-1 this < other; 0 this == other; 1 this > other;
        friend std::ostream& operator<<(std::ostream& os, const String& str);
        String substr(int start, int len)const;
        int index(const String& str)const;
        int* next_array()const;
        int index_kmp(const String& str)const;
};






#endif