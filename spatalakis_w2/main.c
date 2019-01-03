#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Meals
{
   char  food[50];
   int   calories;
   char  meal_time[5];
};

int login();
int generate_pwd(char[], char[]);

int main(int argc, char *argv[]) {
  int is_authorized;
  do
  {
    is_authorized = login();
  } while (is_authorized != 0);

  return 0;
}

int login()
{
  int is_authorized;
  char username[15];
  char password[15];
  char * expected_pwd;

  printf("Please enter your username: ");
  scanf("%s", username);
  printf("Please enter your password: ");
  scanf("%s", password);

  expected_pwd = (char *)malloc(sizeof(char)*15);
  generate_pwd(username, expected_pwd);
  is_authorized = strcmp(password, expected_pwd);
  free(expected_pwd);

  return is_authorized;
}

int generate_pwd(char username[], char *pwd)
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