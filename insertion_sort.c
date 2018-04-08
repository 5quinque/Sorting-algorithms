#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(int argc, char **argv) {
  int *array = NULL;
  int array_size;

  int left = 0;
  int tmp;

  if (argc < 2) {
    printf("Usage: %s [size of list]\n", argv[0]);
    return 1;
  }

  array_size = atoi(argv[1]);
  fill_array(&array, array_size);
  print_array(array, array_size);

  for (int i = 0; i < array_size; i++) {
    if (array[i] > array[i - 1])
      continue;

    left = i;
    tmp = array[i];

    while (left > 0 && tmp < array[--left]) {
      array[left + 1] = array[left];
      array[left] = tmp;
    }
  }

  print_array(array, array_size);

  return 0;
}

