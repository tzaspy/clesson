#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !(FALSE)

int login();
int generate_pwd(char[], char[]);
void get_input(char[], char[]);
int insert_meal(int, char**);
void view_meals(int, char **);
int validate_isnum(char str[]);
int validate_istime(char str[]);
int str2int(char str[]);
char *calculate_type(char[], char[]);
void clear_screen();
void display_menu(char[], int, char**);
void modify_meal();

void run_tests();
void test_calculate_type();
int test_insert_meals(char **);

int main(int argc, char *argv[]) {
  char *meals[100][4];
  int size;
  int is_authorized;

  // run_tests();
  size = test_insert_meals(*meals);

/*  do
  {
    is_authorized = login();
    is_authorized = 0;
  } while (is_authorized != 0);

  insert_meal(0, *meals);
*/
  view_meals(size, *meals);
//  modify_meal();
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

void get_input(char question[], char answer[])
{
    printf("- %s: ", question);
    scanf(" %s", answer);
}

void clear_screen()
{
  int i=0;
  for (i = 0; i < 100; i++){
    printf("\n");
  }
}

void display_menu(char question[], int opt_size, char *options[])
{
  int i = 0;

  printf("\n\n%s\n", question);
  printf("Options:\n");
  for (i = 0; i < opt_size; i++)
  {
    printf("\t%s", options[i]);
  }
  printf("\n");
}

int insert_meal(int index, char *meals[])
{
  char meal[16];
  char calories[5];
  char meal_time[6];
  char type[13];
  int size;
  
  get_input("Please enter your meal", meal);

  do {
    get_input("Please enter how many calories it had", calories);
  } while (validate_isnum(calories) == FALSE);

  do {
    get_input("Please enter time of your meal [HH.MM]", meal_time);
  } while (validate_istime(meal_time) == FALSE);

  meals[index * 4 ] = meal;
  meals[index * 4 + 1] = calories;
  meals[index * 4 + 2] = meal_time;
  meals[index * 4 + 3] = calculate_type(meal_time, type);
  
  size = index + 1;
  return size;
}

void view_meals(int size, char *meals[])
{
  char meal[16];
  char calories[5];
  char m_time[6];
  char m_type[13];

  int idx;
  int sum_calories = 0;

  printf("\n|%-15s|%-8s|%-5s|%-12s|\n", 
      "Meal", "Calories", "Time", "Type");
  for (idx = 0; idx < (15+8+5+12+5); idx++)
  {
    printf("=");
  }
  printf("\n");

  for (idx = 0; idx < size; idx++)
  {
    strcpy(meal, meals[idx * 4 + 0]);
    strcpy(calories, meals[idx * 4 + 1]);
    strcpy(m_time, meals[idx * 4 + 2]);
    strcpy(m_type, meals[idx * 4 + 3]);
    sum_calories += str2int(calories);

    printf("|%-15s|%-8s|%-5s|%-12s|\n", 
        meal, calories, m_time, m_type);
  }
  printf("\n* Number of meals: %d", size);
  printf("\n* Total calories: %d\n\n", sum_calories);

}

void modify_meal(int size, char *meals[])
{
  clear_screen();
  char *question = "Which field do you want to change?";
  char *options[3] = {"[1] Meal", "[2] Calories", "[3] Meal time"};
  int opt_size = 3;
  
  display_menu(question, opt_size, options);
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

char *calculate_type(char time[], char type[])
{
    char shour[2];
    strncpy(shour, time, 2);
    int hour = str2int(shour);

    switch (hour) {
      case 5 :
      case 6 :
      case 7 :
      case 8 :
      case 9 :
      case 10 :
      case 11 :
        type = "prwino";
        break;
      case 12 :
      case 13 :
      case 14 :
      case 15 :
      case 16 :
      case 17 :
      case 18 :
      case 19 :
        type = "messimeriano";
        break;
      case 20 :
      case 21 :
      case 22 :
      case 23 :
      case 0 :
      case 1 :
      case 2 :
      case 3 :
      case 4 :
        type = "vradino";
        break;
      default :
        type = "ERROR";
    }

    return type;
}

void run_tests()
{
  int size;
  char *meals[10][4];
  size = test_insert_meals(*meals);

  test_calculate_type();
}

void test_calculate_type()
{
  int i = 0;
  char type[12];
  char* tests[] = {"15.15", "messimeriano",
                    "18.59", "messimeriano",
                    "21.00", "vradino",
                    "04.59", "vradino",
                    "05.00", "prwino",
                    "00.00", "vradino",
                    "23.59", "vradino",
                    "11.59", "prwino",
                    "12.00", "messimeriano",
                  };

  for (i = 0 ; i < 9; i++)
  {
    if (strcmp(calculate_type(tests[2*i], type), tests[2*i + 1]) == 0)
    {
      printf ("\n *** PASSED *** [%s->%s]\n", tests[2*i], tests[2*i + 1]);
    }
    else
    {
      printf ("\n !!! ERROR !!! [%s->%s]\n", tests[2*i], tests[2*i + 1]);
    }
  }
}

int test_insert_meals(char *meals[])
{
  char type[13];
  int i;
  int size;
  char *test_meals[30] = {
    "Salata", "800", "17.50",
    "Patates", "450", "13.30",
    "Gala", "50", "03.30",
    "Dimitriaka", "500", "08.45",
    "Krouasan", "300", "10.30",
    "Ceasars", "750", "19.30",
    "Melomakarona", "200", "23.10",
    "Pastitsio", "1000", "13.10",
    "Kotopoulo", "650", "14.10",
    "Portokalada", "310", "12.59"
  };
  size = 10;
  
  for (i = 0; i < size; i++)
  {
    meals[i * 4 + 0] = test_meals[i * 3 + 0];
    meals[i * 4 + 1] = test_meals[i * 3 + 1];
    meals[i * 4 + 2] = test_meals[i * 3 + 2];
    meals[i * 4 + 3] = calculate_type(test_meals[i * 3 + 2], type);
  }
  
  return size;
}