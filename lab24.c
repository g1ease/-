#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
    int N, M;
    int c=0,hi,i,j,times=1;
    
    // printf("Задайте целое число строк и столбцов через пробел\n");
   //  scanf("%d %d",&N,&M);    
    printf("Строк:4; Столбцов:4\n");
N=4; M=4;
    int B[N][M];


// vvodim massiv
     for (i= 0; i< 4; i++){
      for (j= 0; j< 4; j++){
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

 if (B[0][0]>0){ times= times*B[0][0];}
 if (B[0][1]>0){ times= times*B[0][1];}
 if (B[0][2]>0){ times= times*B[0][2];}
if (B[2][0]>0){ times= times*B[2][0];}
if (B[1][0]>0){ times= times*B[1][0];}
 if (B[1][1]>0){ times= times*B[1][1];}

    if (times== 1)
       printf("Нет положительных чисел или одни единицы\n");
    else
       printf("Произведение положительных чисел выше побочной диагонали: %d\n",times);
    times = 0;

    int min=B[0][1];
    for (i=0; i<4; i++){
     if (B[i][1]<min)
      min=B[i][1];}
     
    printf("Минимальное число во втором столбце=%d\n",min);
    
    for (i=0; i<4; i++){
     if (B[i][1]==min)
       hi=i;}

    
      B[hi][1]=B[3][2];

      B[3][2]=min;
     


     for (i= 0; i< N; i++){
      for (j= 0; j< M; j++){
       printf("%4d",B[i][j]);}
      puts("\n");}
        for(i=0;i<N;i++)
                free(B[i]);
     free(B);  
    return(0);}
