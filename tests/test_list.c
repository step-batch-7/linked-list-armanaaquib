#include <stdio.h>
#include "test_link_list.h"
#include "list.h"

void test_create_list(void);

void test_create_list(void)
{
  printf("testing create_list()\n");

  List_ptr list = create_list();
  assert_node_ptr(list->head, NULL, "head NULL");
  assert_node_ptr(list->head, NULL, "last NULL");
  assert_int(list->count, 0, "count 0");

  printf("\n");
}

int main(void)
{
  test_create_list();

  return 0;
}
