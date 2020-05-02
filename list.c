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

  Ptr_to_node_ptr ptr_to_set = &list->last->next;

  if(list->head == NULL)
  {
    ptr_to_set = &list->head;
  }

  DEREF ptr_to_set = node;
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

Status remove_at(List_ptr list, unsigned position)
{
  if(position >= list->count)
  {
    return Failure;
  }
  
  if(position == 0)
  {
    return remove_from_start(list);
  }

  if(position == list->count - 1)
  {
    return remove_from_end(list);
  }

  Node_ptr p_walk = list->head;
  unsigned pos = 0;

  while(pos < position - 1)
  {
    p_walk = p_walk->next;
    pos++;
  }

  Node_ptr node_to_remove = p_walk->next;

  p_walk->next = node_to_remove->next;

  free(node_to_remove);

  return Success;
}

int find_position(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  int position = 0;

  while(p_walk != NULL)
  {
    if(p_walk->value == value)
    {
      return position;
    }

    position++;
    p_walk = p_walk->next;
  }

  return -1;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int position = find_position(list, value);

  if(position == -1)
  {
    return Failure;
  }

  return remove_at(list, position);
}

Status remove_all_occurrences(List_ptr list, int value)
{
  int position = find_position(list, value);

  if(position == -1)
  {
    return Failure;
  }

  Node_ptr p_walk = list->head;
  position = 0;

  while(p_walk != NULL)
  {
    if(p_walk->value == value)
    {
      p_walk = p_walk->next;
      remove_at(list, position);
    }
    else
    {
      p_walk = p_walk->next;
      position++;
    }
  }
  
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  if(find_position(list, value) != -1)
  {
    return Success;
  }

  Node_ptr node = create_node(value);

  if(!node)
  {
    return Failure;
  }

  return add_to_end(list, value);
}
