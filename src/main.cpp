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
//#include "./data_struct/LinkTree.h"
//#include "./src_cpp/List.hpp"
#include <string>
#include <iostream>
#include "./data_struct_cpp/List.hpp"
#include "./data_struct_cpp/Stack.hpp"
#include "./data_struct_cpp/Queue.hpp"
#include "./data_struct_cpp/String.hpp"
#include "./data_struct_cpp/Tree.hpp"
#include "./data_struct_cpp/Math.hpp"
#include "./data_struct_cpp/Graph.hpp"
bool compare(int a, int b) { return a == b; }
void visit(const char& c){std::cout<< c << std::endl;}



int main()
{
  Graph<char> g;
  g.add_vertex('A');
  g.add_vertex('B');
  g.add_vertex('C');
  g.add_vertex('D');
  g.add_vertex('E');
  g.add_edge('A', 'B');
  g.add_edge('A', 'C');
  g.add_edge('B', 'D');
  g.add_edge('C', 'D');
  g.add_edge('D', 'E');
  g.print();
  g.bfsTraveral(visit);
}
