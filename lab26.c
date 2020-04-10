#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
    int N,M;
    int c=0,hi,i,j,t=1,min,p;
    
     printf("Задайте целое число строк и столбцов через пробел\n");
     scanf("%d %d",&N,&M);    
    printf("Строк:%d; Столбцов:%d\n",N,M);

    p=N*M;

  
int *B = (int*)malloc(p * sizeof(int));

// vvodim massiv
     for (i= 0; i< p; i++){
      
       scanf("%d",&N);
       B[i]=N;}
       
      puts("\n");

// vyvodim massiv
for (i= 0; i< 4; i++){
       printf("%d  ",B[i]);}
      puts("\n");
for (i= 4; i< 8; i++){
       printf("%d  ",B[i]);}
      puts("\n");
for (i= 8; i< 12; i++){
       printf("%d  ",B[i]);}
      puts("\n");
for (i= 12; i< 16; i++){
       printf("%d  ",B[i]);}
      puts("\n");

     //  for(i=0;i<N;i++);
  // printf("%4d",B[i][j]);
  //  for (i= N-1; i>=0; i--){
  //   c++;
  //  for (j= N-2; j>=0; j--){
  //    if (B[i][j]>0)  
  //      times= times*B[i][j];}}

 if (B[0]>0){ t= t*B[0];}
 if (B[1]>0){ t= t*B[1];}
 if (B[2]>0){ t= t*B[2];}
if (B[4]>0){ t= t*B[4];}
if (B[5]>0){ t= t*B[5];}
 if (B[8]>0){ t= t*B[8];}

    if (t== 1)
       printf("Нет положительных чисел или одни единицы\n");
    else
       printf("Произведение положительных чисел выше побочной диагонали: %d\n",t);
    // times = 0;

    min=B[1];
    for (i=1; i< 2; i++){
     if (B[i]<min)
      min=B[i];}
 for (i=5; i< 6; i++){
     if (B[i]<min)
      min=B[i];}
 for (i=9;i< 10; i++){
     if (B[i]<min)
      min=B[i];}
 for (i=13;i< 14; i++){
     if (B[i]<min)
      min=B[i];}
     
    printf("Минимальное число во втором столбце=%d\n",min);
    
    
for (i=1;i< 2; i++){
     if (B[i]==min)
      hi=i;}
 for (i=5;i< 6; i++){
     if (B[i]==min)
      hi=i;}
 for (i=9;i< 10; i++){
     if (B[i]==min)
     hi=i;}
 for (i=13;i< 14; i++){
     if (B[i]==min)
      hi=i;}

    
      B[hi]=B[14];

      B[14]=min;
     
// vyvodim massiv
for (i= 0; i< 4; i++){
       printf("%d  ",B[i]);}
      puts("\n");
for (i= 4; i< 8; i++){
       printf("%d  ",B[i]);}
      puts("\n");
for (i= 8; i< 12; i++){
       printf("%d  ",B[i]);}
      puts("\n");
for (i= 12; i< 16; i++){
       printf("%d  ",B[i]);}
      puts("\n");

        
     free(B);  
    return(0);}
