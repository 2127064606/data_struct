#include <stdio.h>
//#include "./data_struct/List.h"
#include "./data_struct/LinkList.h"
#include <stdbool.h>
#include <stdlib.h>
#include "./data_struct/value.h"
#include "./data_struct/BLinkList.h"
//#include "./data_struct/Stack.h"
#include "./data_struct/LinkStack.h"
//#include "./data_struct/Queue.h"
#include "./data_struct/LinkQueue.h"
//#include "./data_struct/MStr.h"
#include "./data_struct/LinkTree.h"
//#include "./src_cpp/List.hpp"
#include <string>
#include <iostream>
#include "./data_struct_cpp/List.hpp"
#include "./data_struct_cpp/Stack.hpp"
#include "./data_struct_cpp/Queue.hpp"
#include "./data_struct_cpp/String.hpp"

bool compare(int a, int b) { return a == b; }



int main()
{
  String str1 = "abcdefg";
  String str = "def";
  std::cout << str1.index_kmp(str) << std::endl;
}
