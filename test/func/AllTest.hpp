#ifndef TEST_H
#define TEST_H
#include <string>

bool bracket_match(char *str, int len);

std::string GetSuffix(std::string op_str);

bool IsOperatorHigherOrEqual(char op1, char op2);

int GetOperatorValue(std::string suffix);

int OperatorCalculate(int op1, int op2, char op);

int GetDigital(std::string num_str, int &start);

#endif