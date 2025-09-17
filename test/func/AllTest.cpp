#include <stack>
#include <iostream>
#include "AllTest.hpp"
using namespace std;

bool bracket_match(char *str, int len)
{
    stack<char> s;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else
        {
            if (s.empty())
                return false;
            char top = s.top();
            s.pop();
            bool t1 = top == '(' && str[i] == ')';
            bool t2 = top == '[' && str[i] == ']';
            bool t3 = top == '{' && str[i] == '}';
            if (t1 || t2 || t3)
                continue;
            return false;
        }
    }
    return s.empty();
}

// 判断是否为数字
int GetDigital(string num_str, int &start)
{
    int num = 0;
    for(int i = start; i < num_str.size(); i++)
    {
        if (num_str[i] >= '0' && num_str[i] <= '9')
        {
            num *= 10;
            num += num_str[i] - '0';
            start++;
        }
         else
        break;
    }
    start--;
    return num;
}

bool IsOperatorHigherOrEqual(char op1, char op2)
{
    bool rt1 = op1 == '*' || op1 == '/';
    bool rt2 = (op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-');
    return rt1 || rt2;
}

// 中缀表达式转后缀表达式
string GetSuffix(string op_str)
{
    stack<char> s;
    string suffix = "";
    for (int i = 0; i < op_str.size(); i++)
    {
        // 遇到操作数直接加入后缀表达式
        if (op_str[i] >= '0' && op_str[i] <= '9')
           {
               int num = GetDigital(op_str, i);
               suffix += ' ';
               suffix += to_string(num);
           }
        // 遇到界限符
        else if (op_str[i] == '(' || op_str[i] == ')')
        {
            if (op_str[i] == '(')
                s.push(op_str[i]);
            else
            {
                while (!s.empty() && s.top() != '(')
                {
                    suffix += s.top();
                    s.pop();
                }
                if (s.top() == '(')
                    s.pop();
            }
        }
        // 遇到运算符
        else
        {
            while (!s.empty() && s.top() != '(' && IsOperatorHigherOrEqual(s.top(), op_str[i]))
            {
                suffix += s.top();
                s.pop();
            }
            // 最后将当前运算符压入栈中
            s.push(op_str[i]);
        }
    }
    // 最后将栈中剩余的运算符加入后缀表达式
    while (!s.empty())
    {
        suffix += s.top();
        s.pop();
    }
    return suffix;
}

int OperatorCalculate(int op1, int op2, char op)
{
    switch (op)
    {
    case ('+'):
        return op1 + op2;
    case ('-'):
        return op1 - op2;
    case ('*'):
        return op1 * op2;
    case ('/'):
        return op1 / op2;
    default:
        return 0;
    }
}

// 计算后缀表达式的值
int GetOperatorValue(string suffix)
{
    stack<int> nums;
    for (int i = 0; i < suffix.size(); i++)
    {
        if (suffix[i] == ' ')
            nums.push(GetDigital(suffix, ++i));
        else
        {
            int op2 = nums.top();
            nums.pop();
            int op1 = nums.top();
            nums.pop();
            int res = OperatorCalculate(op1, op2, suffix[i]);
            nums.push(res);
        }
    }
    return nums.top();
}