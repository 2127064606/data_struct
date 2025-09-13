#include <stdio.h>
#include "./data_struct/List.h"
#include "./data_struct/LinkList.h"
#include <stdbool.h>
#include <stdlib.h>
#include "./data_struct/value.h"
#include "./data_struct/BLinkList.h"
#include "./data_struct/Stack.h"
#include "./data_struct/LinkStack.h"

bool compare(int a, int b) { return a == b; }



int main()
{
  link_stack *s;
  InitStack_L(s);
  Push_L(s, 1);
  Push_L(s, 2);
  Push_L(s, 3);
  PrintStack_L(*s);
  
}
