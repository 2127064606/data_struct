#include <iostream>
#include "func/AllTest.hpp"

int main()
{
   char str[] = "{[()]}";
   int len = sizeof(str) / sizeof(char);
   if(bracket_match(str, len -1))std::cout << "匹配成功" << std::endl;
   else std::cout << "匹配失败" << std::endl;
}