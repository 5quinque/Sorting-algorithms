#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int merge_sort(int *array, int left, int right);
void merge();

int main(int argc, char **argv) {
  int *array;
  int array_size;

  if (argc < 2) {
    printf("Usage: %s [size of list]\n", argv[0]);
    return 1;
  }

  array_size = atoi(argv[1]);
  fill_array(&array, array_size);
  print_array(array, array_size);

  merge_sort(array, 0, array_size);

  return 0;
}

int merge_sort(int *array, int left, int right) {
  int tmp;
  int middle = (left + right) / 2;


  for (int i = left; i < right; i++) {
    printf(" %d ", array[i]);
  }
  printf("\n");
  printf("l: %d m: %d r: %d\n", left, middle, right);
  
  if (right == left) {
    return array[left];
  }

  tmp = merge_sort(array, left, middle);
  tmp = merge_sort(array, middle + 1, right);

  return -1;
}
