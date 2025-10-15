#ifndef MATH_HPP
#define MATH_HPP
#include "String.hpp"
#include "Stack.hpp"


class Math{
    public:
        static bool isdigit(char c);
        static String getdigit(const String& str, int& index);
        static int priority(char op);
        static int calculate(int left, int right, char op);
        static String getsuffix(const String& str);
        static int calculate(const String& suffix);
};


#endif