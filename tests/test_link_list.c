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

void assert_status(Status status_1, Status status_2, char mesaage[])
{
  display_assert_message(status_1 == status_2, mesaage);
}


List_ptr create_list_with_values(Numbers numbers, unsigned count)
{
  List_ptr list = create_list();
  Node_ptr node;
  
  node = create_node(numbers[0]);

  list->head = node;
  list->last = node;
  list->count++;

  for(unsigned i = 1; i < count; i++)
  {
    node = create_node(numbers[i]);

    list->last->next = node;
    list->last = node;
  }

  return list;
}
