#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !(FALSE)

int login();
int generate_pwd(char[], char[]);
int get_input(char[], char[]);
int insert_meal(int, char**);
int validate_isnum(char str[]);
int validate_istime(char str[]);
int str2int(char str[]);

int main(int argc, char *argv[]) {
  char *meals[100][5];
  int is_authorized;

  do
  {
    is_authorized = login();
    is_authorized = 0;
  } while (is_authorized != 0);

  insert_meal(1, *meals);
  return 0;
}

int login()
{
  int is_authorized;
  char username[15];
  char password[15];
  char expected_pwd[15];

  get_input("Please enter your username", username);
  get_input("Please enter your password", password);

  generate_pwd(username, expected_pwd);
  is_authorized = strcmp(password, expected_pwd);

  return is_authorized;
}

int generate_pwd(char username[], char pwd[])
{
  int i;
  for (i = 0; i <= strlen(username); i++) {
    if (i % 2 == 0)
    {
      pwd[i] = toupper(username[i]);
    } else {
      pwd[i] = tolower(username[i]);
    }
  }
  return 0;
}

int get_input(char question[], char answer[])
{
    printf("- %s: ", question);
    scanf("%s", answer);
    return 0;
}

int insert_meal(int index, char *meals[])
{
  char food[15];
  char calories[3];
  char meal_time[5];
  char type[15];
  
  get_input("Please enter what was your meal", food);
  do {
    get_input("Please enter how many calories it had", calories);
  } while (validate_isnum(calories) == FALSE);

  do {  
  get_input("Please enter time of your meal [HH.MM]", meal_time);
  } while (validate_istime(meal_time) == FALSE);
}

int validate_isnum(char str[])
{
  int i;
  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] < '0' || str[i] > '9')
      return FALSE;
  }
  return TRUE;
}

int validate_istime(char str[])
{
  char shour[2];
  char smin[2];
  int hour;
  int min;

  if (strlen(str) != 5)
  {
    return FALSE;
  }

  if (str[2] != '.')
  {
    return FALSE;
  }

  strncpy(shour, str, 2);
  hour = str2int(shour);
  strncpy(smin, str + 3, 2);
  min = str2int(smin);

  if (hour < 0 || hour > 23)
  {
    return FALSE;
  }

  if (min < 0 || min > 59)
  {
    return FALSE;
  }

  return TRUE;
}

int str2int(char str[]){
  int i;
  int num = 0;
  int class = 1;
  if (validate_isnum(str) == FALSE)
    return -1;

  for (i = strlen(str) - 1; i >= 0; i--)
  {
    int digit = str[i] - 48;
    num += (digit * class);
    class *= 10;
  }
  return num;
}