
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
float summa=100;



typedef struct tagITEM
{
  char name[9];
  int kolvo;
  int kod;
  float tsena;
} ITEM;


int Number=6;
int size=4;
ITEM Men[6];
void*realloc(void* Men, size_t size);
// Men = (int*)realloc(, Number * sizeof(int));

/* Функция для очистки кассы */
void Del1 ( void )
{
  summa=0;
  printf("Касса пуста.\n\n");
} 
/* End of 'Del1' function */ 


/* Функция для вывода суммы */
void Print1( void )
{
  printf("В кассе: %f", summa);
  printf(" рублей.\n\n");
} /* End of 'Print1' function */

/* Функция для вывода массива */
void Print( void )
{
  int i;

  printf(" N  Код                 Название            Количество             Цена (р.)\n");
  for (i = 0; i < 9; i ++)
    printf("%2i. %-20d %-20s %-20d %3f\n", i + 1, Men[i].kod, Men[i].name, Men[i].kolvo, Men[i].tsena);
  printf("\n");
} /* End of 'Print' function */


/* Функция для сохранения массива в файле */
void Save( void )
{
  FILE *F;
  int i;

  if ((F = fopen("Basa32.dat", "wt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для записи файл 'Basa31.dat'\n \n");
    return;
  }

  fprintf(F, "%i\n", Number);
  for (i = 0; i < Number; i ++)
    fprintf(F, "%d\n%s\n%d\n%f\n", Men[i].kod, Men[i].name, Men[i].kolvo, Men[i].tsena);

  fclose(F);
} /* End of 'Save' function */


/* Функция для чтения массива из файла */
void Load( void )
{
  FILE *F;
  int i;

  if ((F = fopen("Basa32.dat", "rt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для чтения файл 'Basa31.dat'\n \n");
    return;
  }

  fscanf(F, "%i", &Number);
  for (i = 0; i < Number; i ++)
    fscanf(F, "%i\n%s\n%i\n%f\n", &Men[i].kod, Men[i].name, &Men[i].kolvo, &Men[i].tsena);

  fclose(F);
} /* End of 'Load' function */


/* Функция для добавления элемента */
void Add( void )
{
 /* if (z == 9)
  {
    fprintf(stderr, "Количество препаратов максимально.\n \n");
    return;
  }*/
  
  int Check;
int i;
int e=0;
int v;

  Print();
  printf("Введите код добавляемого препарата > ");
  scanf("%i", &l);
  if (l % 1000 != 0 && l < 111)
  {
    fprintf(stderr, "Введите корректный код препарата.\n \n");
    return;
  }

  for (i= 0; i < Number ; i ++){
 if (Men[i].kod == l){
     Men[i].kolvo = Men[i].kolvo + 1;
     e=1;}}

if(e==0){
Number+=1;
Men=realloc(Men, Number * sizeof(int));
Men[z].kod = l;
Men[z].kolvo =  1;
  printf("Введите название препарата > ");
  scanf("%s", Men[z].name);
  printf("Введите цену препарата > ");
  scanf("%f", &Men[z].tsena);
z+=1;}

printf("Препарат добавлен.\n\n");
}
 /* End of 'Add' function */


/* Функция для prodazhi preparata */
void Del( void )
{
  int i;

  Print();
  printf("Введите код продаваемого препарата > ");
  scanf("%i", &l);
  if (l % 1000 != 0 && l < 111)
  {
    fprintf(stderr, "Введите корректный код препарата.\n \n");
    return;
  }

  for (i= 0; i < Number ; i ++){
 if (Men[i].kod == l){
     Men[i].kolvo = Men[i].kolvo - 1;
     summa+= Men[i].tsena;
     printf("Препарат продан.\n\n"); }}

} /* End of 'Del' function */


/* Функция для упорядочивания массива по nazvaniy */
void Sort( void )
{
  int i, j;
  ITEM Temp;

  for (j = z-1; j > 0; j --)
    for (i = 0; i < j; i ++)
      if (strcmp(Men[i].name, Men[i + 1].name) > 0)
      {
  Temp = Men[i];
        Men[i] = Men[i + 1];
        Men[i + 1] = Temp;
      }
} /* End of 'Sort' function */





/* Вывод меню и чтение номера выбранного действия */
int Menu( void )
{
  int c = 0;

  while ((c < '0' || c > '8') && c != 27)
  {
    printf("0 : Завершить работу\n"
           "1 : Продать препарат\n"
           "2 : Принять новый препарат\n"
           "3 : Упорядочить по названию\n"
           "4 : Загрузить данные\n"
           "5 : Сохранить данные\n"
           "6 : Вывести данные\n"
           "7 : Вывести данные о сумме в кассе\n"
           "8 : Очистить кассу\n"
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
         "Установленное количество доступных препаратов - (9).\n"
		 "Используйте латиницу для ввода названия и кода препарата.\n \n");
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
    case '7':
      Print1();
      break;
    case '8':
      Del1();
      break;
    }
} /* End of 'main' function */

