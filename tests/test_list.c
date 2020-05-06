#include <stdio.h>
#include "test_link_list.h"
#include "list.h"

void test_create_list(void);
void test_create_node(void);
void test_add_to_end(void);
void test_add_to_start(void);
void test_insert_at(void);
void test_remove_from_start(void);
void test_remove_from_end(void);
void test_remove_at(void);
void test_find_position(void);
void test_remove_first_occurrence(void);
void test_remove_all_occurrences(void);
void test_add_unique(void);
void test_clear_list(void);

void test_create_list(void)
{
  printf("testing create_list()\n");

  List_ptr list = create_list();
  assert_node_ptr(list->head, NULL, "head should be NULL");
  assert_node_ptr(list->head, NULL, "last should be NULL");
  assert_int(list->count, 0, "count should be 0");

  destroy_list(list);

  printf("\n");
}

void test_create_node(void)
{
  printf("testing create_node()\n");

  Node_ptr node = create_node(10);

  assert_int(node->value, 10, "value should be passed value");
  assert_node_ptr(node->next, NULL, "next should be null");

  printf("\n");
}

void test_add_to_end(void)
{
  printf("testing add_to_end()\n");

  List_ptr list = create_list();

  assert_status(add_to_end(list,10), Success, "should add to end of empty list");
  assert_node_ptr(list->head, &(DEREF list->head), "  head should point first node");
  assert_node_ptr(list->last, &(DEREF list->head), "  last should point first node");
  assert_int(list->count, 1, "  count should be 1");

  Node_ptr head = list->head;

  assert_status(add_to_end(list,20), Success, "should add to end of list");
  assert_node_ptr(list->head, &(DEREF head), "  head should not change");
  assert_node_ptr(list->last, &(DEREF head->next), "  last should point second node");
  assert_int(list->count, 2, "  count should increase by 1");

  destroy_list(list);

  printf("\n");
}

void test_add_to_start(void)
{
  printf("testing add_to_start()\n");

  List_ptr list = create_list();

  assert_status(add_to_start(list,10), Success, "should add to start of empty list");
  assert_node_ptr(list->head, &(DEREF list->head), "  head should point first node");
  assert_node_ptr(list->last, &(DEREF list->head), "  last should point first node");
  assert_int(list->count, 1, "  count should be 1");

  Node_ptr head = list->head;
  Node_ptr last = list->head;

  assert_status(add_to_start(list,20), Success, "should add to start of list");
  assert_node_ptr(list->head->next, &(DEREF head), "  head should point new first node");
  assert_node_ptr(list->last, &(DEREF last), "  last should not change");
  assert_int(list->count, 2, "  count should increase by 1");

  destroy_list(list);

  printf("\n");
}

void test_insert_at(void)
{
  printf("testing insert_at()\n");

  List_ptr list = create_list();

  assert_status(insert_at(list,10, 1), Failure, "should fail if position is more than length");

  assert_status(insert_at(list,10, 0), Success, "should insert at 0 if list is empty");
  assert_node_ptr(list->head, &(DEREF list->head), "  head should point first node");
  assert_node_ptr(list->last, &(DEREF list->head), "  last should point first node");
  assert_int(list->count, 1, "  count should be 1");

  Node_ptr head = list->head;

  assert_status(insert_at(list,20, 1), Success, "should insert at end of the list");
  assert_node_ptr(list->head, &(DEREF head), "  head should not change");
  assert_node_ptr(list->last, &(DEREF head->next), "  last should point end node of the list");
  assert_int(list->count, 2, "  count should increase by 1");

  Node_ptr last = list->last;

  assert_status(insert_at(list,15, 1), Success, "should insert in middle of the list");
  assert_node_ptr(list->head, &(DEREF head), "  head should not change");
  assert_node_ptr(list->last, &(DEREF last), "  last should not change");
  assert_int(list->count, 3, "  count should increase by 1");

  assert_status(insert_at(list,5, 0), Success, "should insert at 0 in the list");
  assert_node_ptr(list->head->next, &(DEREF head), "  head should point new first node");
  assert_node_ptr(list->last, &(DEREF last), "  last should not change");
  assert_int(list->count, 4, "  count should increase by 1");

  destroy_list(list);

  printf("\n");
}

void test_remove_from_start(void)
{
  printf("testing remove_from_start()\n");

  Numbers numbers = {10, 20};
  List_ptr list = create_list_with_values(numbers, 2);
  
  Node_ptr head = list->head->next;
  Node_ptr last = list->last;

  assert_status(remove_from_start(list), Success, "should remove from start of the list");
  assert_node_ptr(list->head, &(DEREF head), "  head should point the second node");
  assert_node_ptr(list->last, &(DEREF last), "  last should not change");
  assert_int(list->count, 1, "  count should decrease by 1");

  assert_status(remove_from_start(list), Success, "should remove from start of single value list");
  assert_node_ptr(list->head, NULL, "  head should be NULL");
  assert_node_ptr(list->last, NULL, "  last should be NULL");
  assert_int(list->count, 0, "  count should be 0");

  assert_status(remove_from_start(list), Failure, "should fail if list is empty");

  destroy_list(list);

  printf("\n");
}

void test_remove_from_end(void)
{
  printf("testing remove_from_end()\n");

  Numbers numbers = {10, 20};
  List_ptr list = create_list_with_values(numbers, 2);

  Node_ptr head = list->head;
  Node_ptr last = list->head;

  assert_status(remove_from_end(list), Success, "should remove from end of the list");
  assert_node_ptr(list->head, &(DEREF head), "  head should not change");
  assert_node_ptr(list->last, &(DEREF last), "  last should point first node");
  assert_int(list->count, 1, "  count should decrease by 1");

  assert_status(remove_from_end(list), Success, "should remove from end of single value list");
  assert_node_ptr(list->head, NULL, "  head should be NULL");
  assert_node_ptr(list->last, NULL, "  last should be NULL");
  assert_int(list->count, 0, "  count should be 0");

  assert_status(remove_from_end(list), Failure, "should fail if list is empty");

  destroy_list(list);

  printf("\n");
}

void test_remove_at(void)
{
  printf("testing remove_at()\n");

  Numbers numbers = {5, 10, 20, 30};
  List_ptr list = create_list_with_values(numbers, 4);

  Node_ptr head = list->head->next;
  Node_ptr last = list->last;

  assert_status(remove_at(list, 0), Success, "should remove at 0 from the list");
  assert_node_ptr(list->head, &(DEREF head), "  head should point second node");
  assert_node_ptr(list->last, &(DEREF last), "  last should not change");
  assert_int(list->count, 3, "  count should decrease by 1");

  assert_status(remove_at(list, 1), Success, "should remove from middle of the list");
  assert_node_ptr(list->head, &(DEREF head), "  head should not change");
  assert_node_ptr(list->last, &(DEREF last), "  last should not change");
  assert_int(list->count, 2, "  count should decrease by 1");

  last = head;

  assert_status(remove_at(list, 1), Success, "should remove from end of the list");
  assert_node_ptr(list->head, &(DEREF head), "  head should not change");
  assert_node_ptr(list->last, &(DEREF last), "  last should point to second last node");
  assert_int(list->count, 1, "  count should decrease by 1");

  assert_status(remove_at(list, 0), Success, "should remove at 0 of single value list");
  assert_node_ptr(list->head, NULL, "  head should be NULL");
  assert_node_ptr(list->last, NULL, "  last should be NULL");
  assert_int(list->count, 0, "  count should be 0");

  assert_status(remove_at(list, 0), Failure, "should fail if position is more than length");

  destroy_list(list);

  printf("\n");
}

void test_find_position(void)
{
  printf("testing find_position()\n");

  Numbers numbers = {5, 10, 5, 10};
  List_ptr list = create_list_with_values(numbers, 4);

  assert_int(find_position(list, 10), 1, "should give position of first occurrance");
  assert_int(find_position(list, 20), -1, "should give -1 if value is not present in the list");

  destroy_list(list);

  printf("\n");
}

void test_remove_first_occurrence(void)
{
  printf("testing remove_first_occurrence()\n");

  Numbers numbers = {5, 10, 5, 10};
  List_ptr list = create_list_with_values(numbers, 4);

  assert_status(remove_first_occurrence(list, 10), Success, "should remove first occurrance");
  assert_int(list->count, 3, "  count should decrase by 1");
  assert_status(find_position(list, 10), 2, "  valid first occurrence after removing");

  assert_status(remove_first_occurrence(list, 20), Failure, "should fail if value is not present in the list");

  destroy_list(list);

  printf("\n");
}

void test_remove_all_occurrences(void)
{
  printf("testing remove_all_occurrences()\n");

  Numbers numbers = {5, 10, 5, 10};
  List_ptr list = create_list_with_values(numbers, 4);

  assert_status(remove_all_occurrences(list, 10), Success, "should remove all occurrances");
  assert_int(list->count, 2, " count should decrease by no of values present in the list");
  assert_status(find_position(list, 10), -1, " all occurrences removed");

  assert_status(remove_all_occurrences(list, 20), Failure, "should fail if value is not present in the list");

  destroy_list(list);

  printf("\n");
}

void test_add_unique(void)
{
  printf("testing add_unique()\n");

  Numbers numbers = {5, 10};
  List_ptr list = create_list_with_values(numbers, 2);

  assert_status(add_unique(list, 10), Failure, "should not add if value is already present");
  assert_status(add_unique(list, 20), Success, "should add if value is not present in the list");

  destroy_list(list);

  printf("\n");
}

void test_clear_list(void)
{
  printf("testing clear_list()\n");

  Numbers numbers = {5, 10, 15};
  List_ptr list = create_list_with_values(numbers, 3);

  assert_status(clear_list(list), Success, "should clear list");
  assert_node_ptr(list->head, NULL, "  head should be NULL");
  assert_node_ptr(list->head, NULL, "  last should be NULL");
  assert_int(list->count, 0, "  count should be 0");

  destroy_list(list);

  printf("\n");
}

int main(void)
{
  test_create_list();
  test_create_node();
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_find_position();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_add_unique();
  test_clear_list();

  print_tests_status();

  return 0;
}
