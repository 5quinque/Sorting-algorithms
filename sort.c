#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_array(int *array, int array_size) {
  for (int i = 0; i < array_size; i++) {
    printf(" %d ", array[i]);
  }
  printf("\n");
}

void fill_array(int **array, int array_size) {
  srand(time(NULL));
  *array = calloc(array_size, sizeof(int));

  for (int i = 0; i < array_size; i++) {
    (*array)[i] = rand() % 1000;
  }
}
