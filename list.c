#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List_ptr create_list(void)
{
  List_ptr list = (List_ptr )malloc(sizeof(List));

  list->head = NULL;
  list->last = NULL;
  list->count = 0;

  return list;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;

  while(p_walk != NULL)
  {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }

  printf("\n");
}

Node_ptr create_node(int value)
{
  Node_ptr node = (Node_ptr )malloc(sizeof(Node));

  if(node)
  {
    node->value = value;
    node->next = NULL;
  }
  
  return node;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr node = create_node(value);

  if(!node)
  {
    return Failure;
  }

  if(list->head == NULL)
  {
    list->head = node;
  }
  else
  {
    list->last->next = node;
  }
  
  list->last = node;
  list->count++;

  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr node = create_node(value);

  if(!node)
  {
    return Failure;
  }

  node->next = list->head;
  list->head = node;
  list->count++;

  if(list->last == NULL)
  {
    list->last = node;
  }

  return Success;
}

Status remove_from_start(List_ptr list)
{
  if(list->head == NULL)
  {
    return Failure;
  }

  Node_ptr node_to_remove = list->head;
  list->head = node_to_remove->next;
  list->count--;

  free(node_to_remove);

  if(list->head == NULL)
  {
    list->last = NULL;
  }

  return Success;
}

Status remove_from_end(List_ptr list) 
{
  if(list->last == NULL)
  {
    return Failure;
  }
  
  free(list->last);
  list->count--;

  Node_ptr second_last_node = list->head;

  if(second_last_node == list->last)
  {
    list->head = NULL;
    list->last = NULL;

    return Success;
  }

  while(second_last_node->next != list->last)
  {
    second_last_node = second_last_node->next;
  }

  second_last_node->next = NULL;
  list->last = second_last_node;

  return Success;
}
