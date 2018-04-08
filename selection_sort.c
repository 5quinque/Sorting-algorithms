#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(int argc, char **argv) {
  int *array;
  int array_size;

  int lowest;
  int tmp;

  if (argc < 2) {
    printf("Usage: %s [size of list]\n", argv[0]);
    return 1;
  }

  array_size = atoi(argv[1]);
  fill_array(&array, array_size);
  print_array(array, array_size);

  for (int i = 0; i < array_size; i++) {
    lowest = i;
    for (int j = i; j < array_size; j++) {
      if (array[j] < array[lowest])
        lowest = j;
    }
    tmp = array[i];
    array[i] = array[lowest];
    array[lowest] = tmp;
  }

  print_array(array, array_size);
  return 0;
}

