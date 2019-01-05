#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !(FALSE)



char meals[100][4][16];
char vmeals[100][4][16];
int size = 0;
int vsize = 0;

int login();
int generate_pwd(char[], char[]);
void get_input(char[], char[]);
int add_meal();
void view_meals(int);
char *get_meal(char[]);
char *get_calories(char[]);
char *get_time(char[]);
int validate_isnum(char[]);
int validate_istime(char[]);
int str2int(char[]);
char *calculate_type(char[], char[]);
void display_menu(char[], int, char**);
void modify_meal();
void run_tests();
void test_calculate_type();
void test_insert_meals();
void test_update_vmeals();
void reset_view();
void update_view_meal(int, int);

int main(int argc, char *argv[])
{
  int is_authorized;
  // run_tests();

/*  do
  {
    is_authorized = login();
    is_authorized = 0;
  } while (is_authorized != 0);
*/
//  size = add_meal();
  test_insert_meals();
  test_update_vmeals();
  view_meals(TRUE);
  modify_meal(size-1);
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
  for (i = 0; i < 50; i++){
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
    printf("\t%s\n", options[i]);
  }
  printf("\n");
}

int add_meal()
{
  char ml[16];
  char cl[5];
  char tm[6];
  char tp[13];
  int index = size;
  strcpy(&meals[index][0][0], get_meal(ml));
  strcpy(&meals[index][1][0], get_calories(cl));
  strcpy(&meals[index][2][0], get_time(tm));
  strcpy(&meals[index][3][0], calculate_type(tm, tp));

  size++;
  return size;
}

char *get_meal(char meal[])
{
  get_input("Please enter your meal", meal);
  return meal;
}

char *get_calories(char calories[]) {
  do {
    get_input("Please enter how many calories it had", calories);
  } while (validate_isnum(calories) == FALSE);
  return calories;
}

char *get_time(char meal_time[]) {
  do {
    get_input("Please enter time of your meal [HH.MM]", meal_time);
  } while (validate_istime(meal_time) == FALSE);
  return meal_time;
}

void view_meals(int show_stats)
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

  for (idx = 0; idx < vsize; idx++)
  {
    strcpy(meal, &vmeals[idx][0][0]);
    strcpy(calories, &vmeals[idx][1][0]);
    strcpy(m_time, &vmeals[idx][2][0]);
    strcpy(m_type, &vmeals[idx][3][0]);
    sum_calories += str2int(calories);

    printf("|%-15s|%-8s|%-5s|%-12s|\n", 
        meal, calories, m_time, m_type);
  }

  if (show_stats == TRUE) {
    printf("\n* Number of meals: %d", size);
    printf("\n* Total calories: %d\n", sum_calories);
  }
}

void modify_meal(int idx)
{
  char sel[5];
  char str[16];
  int i;
  char last_meal[4][16];
  char *question = "Which field do you want to change?";
  char *options[3] = {"[1] Meal", "[2] Calories", "[3] Meal time"};
  int opt_size = 3;

//  clear_screen();
  reset_view();
  update_view_meal(idx, 0);
  view_meals(FALSE);

  display_menu(question, opt_size, options);
  get_input("Please type your option [1/2/3]", sel);
  switch (str2int(sel))  {
    case 1 :
      strcpy(&meals[idx][0][0], get_meal(str));
      break;
    case 2 :
      strcpy(&meals[idx][1][0], get_calories(str));
      break;
    case 3 :
      strcpy(&meals[idx][3][0], get_time(str));
      strcpy(&meals[idx][4][0], calculate_type(&meals[idx][3][0], str));
      break;
    default :
      printf ("\nThe option is not valid!\nReturning to main menu\n");
  }
  reset_view();
  update_view_meal(idx, 0);
  view_meals(FALSE);
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

void test_insert_meals()
{
  int i;
  char type[13];
  char *test_meals[10][3] = {
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
    strcpy(&meals[i][0][0], test_meals[i][0]);
    strcpy(&meals[i][1][0], test_meals[i][1]);
    strcpy(&meals[i][2][0], test_meals[i][2]);
    strcpy(&meals[i][3][0], calculate_type(test_meals[i][2], type));
  }
}

void test_update_vmeals()
{
  int i, j;
  reset_view();
  for (i = 0; i < size; i++)
  {
    update_view_meal(i, i);
  }
}

void reset_view()
{
  vsize = 0;
}

void update_view_meal(int from_row, int to_row)
{
  int j;
  for (j = 0; j < 4; j++)
  {
    strcpy(&vmeals[to_row][j][0], &meals[from_row][j][0]);
  }
  vsize++;
}

