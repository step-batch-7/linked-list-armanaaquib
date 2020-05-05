#include <stdio.h>
#include "test_link_list.h"
#include "list.h"

void test_create_list(void);
void test_add_to_end(void);
void test_add_to_start(void);

void test_create_list(void)
{
  printf("testing create_list()\n");

  List_ptr list = create_list();
  assert_node_ptr(list->head, NULL, "head NULL");
  assert_node_ptr(list->head, NULL, "last NULL");
  assert_int(list->count, 0, "count 0");

  printf("\n");
}

void test_add_to_end(void)
{
  printf("testing add_to_end()\n");

  List_ptr list = create_list();

  assert_status(add_to_end(list,10), Success, "should add to end of empty list");
  assert_status(add_to_end(list,20), Success, "should add to end of list");

  printf("\n");
}

void test_add_to_start(void)
{
  printf("testing add_to_start()\n");

  List_ptr list = create_list();

  assert_status(add_to_end(list,10), Success, "should add to start of empty list");
  assert_status(add_to_end(list,20), Success, "should add to start of list");

  printf("\n");
}

int main(void)
{
  test_create_list();
  test_add_to_end();
  test_add_to_start();

  return 0;
}
