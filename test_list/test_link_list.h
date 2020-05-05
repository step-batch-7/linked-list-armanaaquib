#ifndef __TEST_LINK_LIST
#define __TEST_LINK_LIST

#include "list.h"

typedef char Message[];

void display_assert_message(Status, Message);
void assert_node_ptr(Node_ptr, Node_ptr, Message);
void assert_int(int, int, Message);

#endif
