
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

/* Вывод меню и чтение номера выбранного действия */
int Menu( void )
{
  int c = 0;

  while ((c < '0' || c > '6') && c != 27)
  {
    printf("0 : Завершить работу\n"
           "1 : Продать препарат\n"
           "2 : Принять новый препарат\n"
           "3 : Упорядочить по названию\n"
           "4 : Загрузить данные\n"
           "5 : Сохранить данные\n"
           "6 : Вывести данные\n"
           ">");
    c = getch();
    printf("%c\n\n", c);
  }
  return c;
} /* End of 'Menu' function */

/* Основная функция */
void main( void )
{
  printf("Программа - Аптека.\n"
         "Установленное количество доступных препаратов - (20).\n"
		 "Используйте латиницу для ввода названия препарата.\n \n");
  int Selection;

  Number = 0;
  while ((Selection = Menu()) != '0' && Selection != 27)
    switch (Selection)
    {
    case '1':
      Del();
      break;
    case '2':
      Add();
      break;
    case '3':
      Sort();
      break;
    case '4':
      Load();
      break;
    case '5':
      Save();
      break;
    case '6':
      Print();
      break;
    }
} /* End of 'main' function */

