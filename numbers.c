#include <stdio.h>
#include "list.h"

typedef enum
{
  Add_To_End='a',
  Add_To_Start='b',
  Insert_At='c',
  Remove_From_Start='e',
  Remove_From_End='f',
  Remove_At='g',
  Remove_First_Occurrence='h',
  Remove_All_Occurrences='i',
  Clear_List='j',
  Find_Position='k',
  Display_List='l',
  Exit='m'
} Option;

void clear_input_buffer(void);
unsigned ask_position(void);
int ask_value(void);
Status perform_operaton(List_ptr, Option);
void display_options(void);
Option ask_option(void);
void display_search_result(int, int);

void display_search_result(int value, int position)
{
  if(position != -1)
  {
      printf("%d is present in the list at position %d\n", value, position);
  }
  else
  {
      printf("%d is not present in the list\n", value);
  }
}

void clear_input_buffer(void)
{
  while(getchar() != '\n');
}

unsigned ask_position(void)
{
  int position;

  printf("Please enter position\n");
  scanf("%d", &position);

  clear_input_buffer();

  return position;
}

int ask_value(void)
{
  int value;

  printf("Please enter value\n");
  scanf("%d", &value);

  clear_input_buffer();

  return value;
}

Status perform_operaton(List_ptr list, Option option)
{
  int value;
  unsigned position;
  Status status = Failure;

  switch (option)
  {
    case Add_To_End:
      value = ask_value();
      status = add_to_end(list, value);
      break;

    case Add_To_Start:
      value = ask_value();
      status = add_to_start(list, value);
      break;

    case Insert_At:
      value = ask_value();
      position = ask_position();
      status = insert_at(list, value, position);
      break;

    case Remove_From_Start:
      status = remove_from_start(list);
      break;
      
    case Remove_From_End:
      status = remove_from_end(list);
      break;

    case Remove_At:
      position = ask_position();
      status = remove_at(list, position);
      break;

    case Remove_First_Occurrence:
      value = ask_value();
      status = remove_first_occurrence(list, value);
      break;

    case Remove_All_Occurrences:
      value = ask_value();
      status = remove_all_occurrences(list, value);
      break;

    case Find_Position:
      value = ask_value();
      position = find_position(list, value);
      display_search_result(value, position);
      status = Success;
      break;

    case Clear_List:
      status = clear_list(list);
      break;

    case Display_List:
      display(list);
      status = Success;
      break;
    
    default:
      printf("Invalid option.\n");
  }

  return status;
}

void display_options(void)
{
  printf("\nMain Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
}

Option ask_option(void)
{
  Option option;

  printf("Please enter the alphabet of the operation you would like to perform\n");
  option = getchar();

  clear_input_buffer();

  return option;
}

int main(void)
{
  List_ptr list = create_list();
  Option option;
  int value;

  display_options();
  option = ask_option();

  while(option != Exit)
  {
    Status status = Failure;

    status = perform_operaton(list, option);

    if(status == Success)
    {
      printf("Operation successfull.\n");
    }
    else
    {
      printf("Operation Fail.\n");
    }
    
    display_options();
    option = ask_option();
  }

  destroy_list(list);

  return 0;
}
