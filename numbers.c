#include <stdio.h>
#include "list.h"

typedef enum
{
  Add_To_End='a',
  Add_To_Start='b',
  Display_List='l',
  Exit='m'
} Option;

void display_options(void);
void clear_input_buffer(void);
Option ask_option(void);
int ask_value(void);
Status perform_operaton(List_ptr, Option);

void clear_input_buffer(void)
{
  while(getchar() != '\n');
}

void display_options(void)
{
  printf("\nMain Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
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
      
    case Display_List:
      display(list);
      status = Success;
      break;
    
    default:
      printf("Invalid option.\n");
  }

  return status;
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

  return 0;
}
