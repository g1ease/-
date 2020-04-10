#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    int N, M,hi,hj=1;
    int c=0,in,i,j,times=1;
    srand(time(NULL));
    printf("Задайте целое число строк и столбцов через пробел\n");
    scanf("%d %d",&N,&M);    
    printf("Строк:%d; Столбцов:%d\n",N,M);
    int B[N][M];
    
     for (i= 0; i< N; i++){
      for (j= 0; j< M; j++){
       scanf("%d",&N);
B[i][j]=N;
       }
      puts("\n");}

for (i= 0; i< N; i++){
      for (j= 0; j< M; j++){
       printf("%4d",B[i][j]);}
      puts("\n");}
        for(i=0;i<N;i++);


  printf("%4d",B[i][j]);
    for (i= N-2; i>=0; i--){
     c++;
     for (j= 0; j< c; j++){
      if (B[i][j]>0)  
       times= times*B[i][j];}}
    if (times== 1)
       printf("Нет положительных чисел или одни единицы\n");
    else
       printf("Произведение положительных чисел выше побочной диагонали: %d\n",times);
    int min=B[0][hj];
    for (i=0; i<N; i++){
     if (B[i][hj]<min)
      min=B[i][hj];}
      hi=i;
    printf("Минимальное число во втором столбце=%d\n",min);
    
    if (N<1 || M<1){
     printf("Невозможно поменять место элемента, т.к матрица мала\n");}
    else{
for (i=0; i<N; i++){
     if (B[i][1]<min)
      min=B[i][1];}
      hi=i;
      in=B[3][2];
      B[hi][1]=in;}

      B[3][2]=min;
     


     for (i= 0; i< N; i++){
      for (j= 0; j< M; j++){
       printf("%4d",B[i][j]);}
      puts("\n");}
        for(i=0;i<N;i++)
                free(B[i]);
     free(B);  
    return(0);}
