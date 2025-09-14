#include <iostream>
#include "func/AllTest.hpp"

int main()
{
    std::string op_str = "1+2*3+(4*5+6)*7";
    std::string suffix = GetSuffix(op_str);
    std::cout << GetOperatorValue(suffix) << std::endl;
}