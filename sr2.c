#include <stdio.h>
#include <stdlib.h>
#include <string.h>FILE *F;

// ITEM 
  str Men[9];
  int i;

  if ((F = fopen("1.txt", "rt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для чтения файл '1.txt'\n \n");
    return;
  }

//  fscanf(F, "%i", &Number);
//  for (i = 0; i < Number; i ++)
    fscanf(F, "%s\n", Men[i].kod);

  fclose(F);
