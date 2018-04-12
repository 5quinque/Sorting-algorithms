#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int srand_init = 0;

void print_array(int *array, int array_size) {
  for (int i = 0; i < array_size; i++) {
    printf(" %d ", array[i]);
  }
  printf("\n");
}

void fill_array(int **array, int array_size) {
  if (!srand_init) {
    srand(time(NULL));
    srand_init = 1;
  }

  if (*array != NULL)
    free(*array);
  
  *array = calloc(array_size, sizeof(int));

  for (int i = 0; i < array_size; i++) {
    (*array)[i] = rand() % 1000;
  }
}
