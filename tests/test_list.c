#include <stdio.h>
#include "test_link_list.h"
#include "list.h"

void test_create_list(void);
void test_add_to_end(void);
void test_add_to_start(void);
void test_insert_at(void);
void test_remove_from_start(void);

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

  assert_status(add_to_start(list,10), Success, "should add to start of empty list");
  assert_status(add_to_start(list,20), Success, "should add to start of list");

  printf("\n");
}

void test_insert_at(void)
{
  printf("testing insert_at()\n");

  List_ptr list = create_list();

  assert_status(insert_at(list,10, 1), Failure, "should fail if position is more than length");
  assert_status(insert_at(list,10, 0), Success, "should insert at 0 if list is empty");
  assert_status(insert_at(list,20, 1), Success, "should insert at end of the list");
  assert_status(insert_at(list,15, 1), Success, "should insert in middle of the list");

  printf("\n");
}

void test_remove_from_start(void)
{
  printf("testing remove_from_start()\n");

  Numbers numbers = {10, 20};
  List_ptr list = create_list_with_values(numbers, 2);

  assert_status(remove_from_start(list), Success, "should remove from start of the list");
  assert_status(remove_from_start(list), Success, "should remove from start of single value list");
  assert_status(remove_from_start(list), Failure, "should fail if list is empty");

  printf("\n");
}

int main(void)
{
  test_create_list();
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_remove_from_start();

  return 0;
}
