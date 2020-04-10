/* FILENAME : task_1_1.c */
/* Eugene V. Ogurtsov */
/* Last update : 23.05.2000 */
/* Физико-математический лицей № 30 */
/* Простейшая база данных.
/* Написать программу, которая позволяет оперировать
 * с базой данных учеников: добавлять нового ученика,
 * удалять ученика (по номеру), выводить на экран список
 * всех учеников, сохранять в файле и восстанавливать
 * из файла базу данных, упорядочивать учеников по фамилии.
 * В базе данных имеются поля: номер, фамилия, имя и Номерок
 * ученика. Программа должна предоставлять возможность
 * выбора с помощью меню одной из перечисленной операций. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int getch (void)
{
        int ch;
        struct termios oldt, newt;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON|ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        return ch;
}

typedef struct tagITEM
{
  char Surname[20], Name[20];
  int Nomerok;
} ITEM;

ITEM Men[20];
int Number;

void Print( void )
{
  int i;

  printf(" N  Фамилия              Имя                  Номерок\n");
  for (i = 0; i < Number; i ++)
    printf("%2i. %-20s %-20s %3i\n", i + 1, Men[i].Surname, Men[i].Name, Men[i].Nomerok);
  printf("\n");
} /* End of 'Print' function */

/* Функция для добавления элемента */
void Add( void )
{
  if (Number == 19)
  {
    fprintf(stderr, "Вешалки переполнены.\n \n");
    return;
  }
  
  int Check;
  int i;

  printf("Номерок > ");
  scanf("%i", &Check);
  for (i = 0; i < Number; i ++){
	  if (Men[i].Nomerok = Check)
		  printf(">-> Этот номерок уже был взят! <-<\n\n");
	  return;
  }
  Check = Men[Number].Nomerok;
  scanf("%i", &Men[Number].Nomerok);
  printf("Введите фамилию > ");
  scanf("%s", Men[Number].Surname);
  printf("Введите имя > ");
  scanf("%s", Men[Number].Name);
  

  Number ++;
} /* End of 'Add' function */

/* Функция для удаления элемента */
void Del( void )
{
  int i;

  Print();
  printf("Введите номерок пришедшего человека > ");
  scanf("%i", &i);
  if (i < 1 || i > Number)
  {
    fprintf(stderr, "Введите корректный номер человека из списка..(%i)\n \n", i);
    return;
  }

  for (i --; i < Number - 1; i ++)
    Men[i] = Men[i + 1];

  Number --;
} /* End of 'Del' function */

/* Функция для сохранения массива в файле */
void Save( void )
{
  FILE *F;
  int i;

  if ((F = fopen("Basa.dat", "wt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для записи файл 'Basa.dta'\n \n");
    return;
  }

  fprintf(F, "%i\n", Number);
  for (i = 0; i < Number; i ++)
    fprintf(F, "%s\n%s\n%i\n", Men[i].Surname, Men[i].Name, Men[i].Nomerok);

  fclose(F);
} /* End of 'Save' function */

/* Функция для чтения массива из файла */
void Load( void )
{
  FILE *F;
  int i;

  if ((F = fopen("Basa.dat", "rt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для чтения файл 'Basa.dta'\n \n");
    return;
  }

  fscanf(F, "%i", &Number);
  for (i = 0; i < Number; i ++)
    fscanf(F, "%s%s%i", Men[i].Surname, Men[i].Name, &Men[i].Nomerok);

  fclose(F);
} /* End of 'Load' function */

/* Функция для упорядочивания массива по фамилии */
void Sort( void )
{
  int i, j;
  ITEM Temp;

  for (j = Number - 1; j > 0; j --)
    for (i = 0; i < j; i ++)
      if (strcmp(Men[i].Surname, Men[i + 1].Surname) > 0)
      {
        Temp = Men[i];
        Men[i] = Men[i + 1];
        Men[i + 1] = Temp;
      }
} /* End of 'Sort' function */

/* Вывод меню и чтение номера выбранного пункта */
int Menu( void )
{
  int c = 0;

  while ((c < '0' || c > '6') && c != 27)
  {
    printf("0 : Завершить работу\n"
           "1 : Снять номерок\n"
           "2 : Сохранить данные\n"
           "3 : Загрузить данные\n"
           "4 : Вывести данные\n"
           "5 : Упорядоочить по имени\n"
           "6 : Повесить номерок\n"
           ">");
    c = getch();
    printf("%c\n\n", c);
  }
  return c;
} /* End of 'Menu' function */

/* Основная функция */
void main( void )
{
  printf("Программа - Именной Гардероб.\n"
         "Установленное количество мест гардероба - (20)\n"
		 "Используйте латиницу, для ввода имени клиента.\n \n");
  int Selection;

  Number = 0;
  while ((Selection = Menu()) != '0' && Selection != 27)
    switch (Selection)
    {
    case '1':
      Add();
      break;
    case '2':
      Save();
      break;
    case '3':
      Load();
      break;
    case '4':
      Print();
      break;
    case '5':
      Sort();
      break;
    case '6':
      Del();
      break;
    }
} /* End of 'main' function */

/* End of 'task_1_1.c' file */
