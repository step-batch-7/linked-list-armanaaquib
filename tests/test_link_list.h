#ifndef __TEST_LINK_LIST
#define __TEST_LINK_LIST

#include "list.h"

typedef char *Message;
typedef int Numbers[];

void display_assert_message(Status, Message);
void assert_node_ptr(Node_ptr, Node_ptr, Message);
void assert_int(int, int, Message);
void assert_status(Status, Status, Message);

List_ptr create_list_with_values(Numbers, unsigned);

void print_tests_status(void);

#endif
