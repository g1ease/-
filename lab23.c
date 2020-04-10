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
    
// vvodim massiv
     for (i= 0; i< N; i++){
      for (j= 0; j< M; j++){
       scanf("%d",&N);
       B[i][j]=N;
       }
      puts("\n");}

// vyvodim massiv
for (i= 0; i< N; i++){
      for (j= 0; j< M; j++){
       printf("%4d",B[i][j]);}
      puts("\n");}

     //  for(i=0;i<N;i++);
  // printf("%4d",B[i][j]);
  //  for (i= N-1; i>=0; i--){
  //   c++;
  //  for (j= N-2; j>=0; j--){
  //    if (B[i][j]>0)  
  //      times= times*B[i][j];}}

 if (B[0][1]>0){ times= times*B[0][1];}
 if (B[0][2]>0){ times= times*B[0][2];}
 if (B[0][3]>0){ times= times*B[0][3];}
if (B[1][2]>0){ times= times*B[1][2];}
if (B[1][3]>0){ times= times*B[1][3];}
 if (B[2][3]>0){ times= times*B[2][3];}

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
