#include <stdio.h>
#include "test_link_list.h"

void display_assert_message(Status status, char message[])
{
  if(status == Success)
  {
    printf("%s", "- ");
  }
  else
  {
    printf("%s", "X ");
  }

  printf("%s\n", message);
}

void assert_node_ptr(Node_ptr ptr_1, Node_ptr ptr_2, char message[])
{
  display_assert_message(ptr_1 == ptr_2, message);
}

void assert_int(int value_1, int value_2, char mesaage[])
{
  display_assert_message(value_1 == value_2, mesaage);
}
