#include <stack>
#include "AllTest.hpp"
using namespace std;

bool bracket_match(char *str, int len)
{
    stack<char> s;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else{
            if(s.empty())return false;
            char top = s.top();
            s.pop();
            bool t1 = top == '(' && str[i] == ')';
            bool t2 = top == '[' && str[i] == ']';
            bool t3 = top == '{' && str[i] == '}';
            if(t1 || t2 || t3)continue;
            return false;
        }
    }
    return s.empty();
}