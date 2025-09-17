#include <iostream>
#include "func/AllTest.hpp"

int main()
{
    std::string op_str = "25*40*(92+8)-100/2";
    std::string suffix = GetSuffix(op_str);
    std::cout << suffix << std::endl;
   std::cout << GetOperatorValue(suffix) << std::endl;
}