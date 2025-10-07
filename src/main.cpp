#include <stdio.h>
//#include "./data_struct/List.h"
#include "./data_struct/LinkList.h"
#include <stdbool.h>
#include <stdlib.h>
#include "./data_struct/value.h"
#include "./data_struct/BLinkList.h"
#include "./data_struct/Stack.h"
#include "./data_struct/LinkStack.h"
#include "./data_struct/Queue.h"
#include "./data_struct/LinkQueue.h"
#include "./data_struct/MStr.h"
#include "./data_struct/LinkTree.h"
//#include "./src_cpp/List.hpp"
#include <string>
#include <iostream>
#include "./data_struct_cpp/List.cpp"

bool compare(int a, int b) { return a == b; }



int main()
{
   List<int> list;
   list.insert(1, 1);
   list.insert(2, 2);
   list.insert(3, 3);
   list.insert(4, 4);
   list.insert(5, 5);
   int data;
   int k = list.remove(5);
   std::cout<< "k:"<< k << "\nsize:" << list.size() << std::endl;

}
