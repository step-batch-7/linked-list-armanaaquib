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

Status clear_list(List_ptr list)
{
  Node_ptr p_walk = list->head;
  Node_ptr node_to_remove;

  while(p_walk != NULL)
  {
    node_to_remove = p_walk;
    p_walk = p_walk->next;
    
    free(node_to_remove);
  }

  list->head = NULL;
  list->last = NULL;
  list->count = 0;

  return Success;
}

void destroy_list(List_ptr list)
{
  if(clear_list(list))
  {
    free(list);
  }
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

Status insert_at(List_ptr list, int value, unsigned position)
{
  if(position > list->count)
  {
    return Failure;
  }

  if(position == 0)
  {
    return add_to_start(list, value);
  }

  if(position == list->count)
  {
    return add_to_end(list, value);
  }

  Node_ptr node = create_node(value);

  if(!node)
  {
    return Failure;
  }

  Node_ptr p_walk = list->head;
  unsigned pos = 0;

  while(pos < position - 1)
  {
    p_walk = p_walk->next;
    pos++;
  }  

  node->next = p_walk->next;
  p_walk->next = node;
  list->count++;

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

  if(list->head == list->last)
  {
    return remove_from_start(list);
  }

  free(list->last);
  list->count--;

  Node_ptr second_last_node = list->head;

  while(second_last_node->next != list->last)
  {
    second_last_node = second_last_node->next;
  }

  second_last_node->next = NULL;
  list->last = second_last_node;

  return Success;
}
