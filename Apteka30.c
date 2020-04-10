
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

int k,l,e;
int z=6;



typedef struct tagITEM
{
  char name[9];
  int kolvo;
  int kod;
} ITEM;

ITEM Men[9];
int Number=6;

   

void Print( void )
{
  int i;

  printf(" N  kod              nazvanie                  kolvo\n");
  for (i = 0; i < 9; i ++)
    printf("%2i. %-20d %-20s %3d\n", i + 1, Men[i].kod, Men[i].name, Men[i].kolvo);
  printf("\n");
} /* End of 'Print' function */


/* Функция для сохранения массива в файле */
void Save( void )
{
  FILE *F;
  int i;

  if ((F = fopen("Basa1.dat", "wt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для записи файл 'Basa.dta'\n \n");
    return;
  }

  fprintf(F, "%i\n", Number);
  for (i = 0; i < Number; i ++)
    fprintf(F, "%d\n%s\n%d\n", Men[i].kod, Men[i].name, Men[i].kolvo);

  fclose(F);
} /* End of 'Save' function */

/* Функция для чтения массива из файла */
void Load( void )
{
  FILE *F;
  int i;

  if ((F = fopen("Basa1.dat", "rt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для чтения файл 'Basa.dta'\n \n");
    return;
  }

  fscanf(F, "%i", &Number);
  for (i = 0; i < Number; i ++)
    fscanf(F, "%i\n%s\n%i", &Men[i].kod, Men[i].name, &Men[i].kolvo);

  fclose(F);
} /* End of 'Load' function */


/* Функция для добавления элемента */
void Add( void )
{
  if (Number == 9)
  {
    fprintf(stderr, "Kolvo preparatov max.\n \n");
    return;
  }
  
  int Check;
int i;
int e=0;
int v;

  Print();
  printf("Введите kod dobav preparata > ");
  scanf("%i", &l);
  if (l % 1000 != 0 && l < 111)
  {
    fprintf(stderr, "Введите корректный kod preparata..%i\n \n", i);
    return;
  }

  for (i= 0; i < Number ; i ++){
 if (Men[i].kod == l){
     Men[i].kolvo = Men[i].kolvo + 1;
     e=1;}}


if(e==0){
Men[z].kod = l;
Men[z].kolvo =  1;
  printf("Введите nazvanie preparata > ");
  scanf("%s", Men[z].name);
z+=1;}

printf("Preparat dobavlen.\n");
}
 /* int i;

  printf("Kod preparata > ");
    Check = getch();
  scanf("%i", &Check);
  for (i = 0; i < Number; i ++){
	  if (Men[i].kod == Check){
              printf("Preparat dobavlen.\n");
		  Men[i].kolvo += 1;}
	  return;
  }
  Men[Number].kod = Check;
  printf("Введите nazvanie preparata > ");
  scanf("%s", Men[Number].name);

  Number ++; */
 /* End of 'Add' function */


/* Функция для prodazhi preparata */
void Del( void )
{
  int i;

  Print();
  printf("Введите kod prod preparata > ");
  scanf("%i", &l);
  if (l % 1000 != 0 && l < 111)
  {
    fprintf(stderr, "Введите корректный kod preparata..%i\n \n", i);
    return;
  }
//l=i;
// FILE *F;
  for (i= 0; i < Number ; i ++){


 if (Men[i].kod == l)
     Men[i].kolvo = Men[i].kolvo - 1;}
     printf("Preparat prodan.\n"); 

    /* if (Men[i].kod == &l && Men[i].kolvo == &e)
      k=i;
     else *Men[i].kolvo = *Men[i].kolvo - 1;}
     
for (i = k; i < Number-1 ; i ++){
     
      Men[i]=Men[i+1];} */

 
} /* End of 'Del' function */

/* Функция для упорядочивания массива по nazvaniy */
void Sort( void )
{
  int i, j;
  ITEM Temp;
//typedef struct tagITEM
//{
  /*char Temp2;
  int Temp1;
  int Temp3;*/
//} ITEM;
//int strncmp (const char *__s1, const char *__s2, size_t __n);

  for (j = z-1; j > 0; j --)
    for (i = 0; i < j; i ++)
      if (strcmp(Men[i].name, Men[i + 1].name) > 0)
      {
  Temp = Men[i];
        Men[i] = Men[i + 1];
        Men[i + 1] = Temp;
    /*    Temp1 = Men[i].kod;
        Men[i].kod = Men[i + 1].kod;
        Men[i + 1].kod = Temp1;
 Temp2 = *Men[i].name;
        *Men[i].name = *Men[i + 1].name;
        *Men[i + 1].name = Temp2;
 Temp2 = Men[i].kolvo;
        Men[i].kolvo = Men[i + 1].kolvo;
        Men[i + 1].kolvo = Temp2; */
      }
} /* End of 'Sort' function */





/* Вывод меню и чтение номера выбранного действия */
int Menu( void )
{
  int c = 0;

  while ((c < '0' || c > '6') && c != 27)
  {
    printf("0 : Завершить работу\n"
           "1 : Продать препарат\n"
           "2 : Принять новый препарат\n"
           "3 : Упорядочить по nazvaniy\n"
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
         "Установленное количество доступных препаратов - (6).\n"
		 "Используйте латиницу для ввода названия i koda препарата.\n \n");
  int Selection;

  Number = 6;
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

