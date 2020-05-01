#include <stdio.h>
#include "list.h"

typedef enum
{
  Add_To_End='a',
  Exit='m'
} Option;

void display_options(void);
Option ask_option(void);
int ask_value(void);

void display_options(void)
{
  printf("\nMain Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(m) exit\n");
}

Option ask_option(void)
{
  Option option;

  printf("Please enter the alphabet of the operation you would like to perform\n");
  option = getchar();

  while(getchar() != '\n');

  return option;
}

int ask_value(void)
{
  int value;

  printf("Please enter value\n");
  scanf("%d", &value);

  return value;
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

    switch (option)
    {
      case Add_To_End:
        value = ask_value();
        status = add_to_end(list, value);
        break;
      
      default:
        printf("Invalid option.\n");
    }

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
