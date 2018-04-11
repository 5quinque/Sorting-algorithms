#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int * merge_sort(int *array, int array_size);
int * merge(int *left, int *right, int left_size, int right_size);

int main(int argc, char **argv) {
  int *array;
  int *sorted_array;
  int array_size;

  if (argc < 2) {
    printf("Usage: %s [size of list]\n", argv[0]);
    return 1;
  }

  array_size = atoi(argv[1]);
  fill_array(&array, array_size);
  print_array(array, array_size);

  sorted_array = calloc(array_size, sizeof(int));

  sorted_array = merge_sort(array, array_size);

  print_array(sorted_array, array_size);

  return 0;
}

int * merge_sort(int *array, int array_size) {
  int *merged = calloc(array_size, sizeof(int));
  int middle;
  int *left;
  int *right;
  int *sorted_left;
  int *sorted_right;
  int left_size;
  int right_size;

  if (array_size == 1) {
    return array;
  }

  middle = (array_size + 1) / 2;
  left_size = middle;
  right_size = array_size - middle;
  left = calloc(left_size, sizeof(int));
  right = calloc(right_size, sizeof(int));

  sorted_left = calloc(left_size, sizeof(int));
  sorted_right = calloc(right_size, sizeof(int));

  /* split array in half */
  for (int i = 0; i < array_size; i++) {
    if (i < middle) {
      left[i] = array[i];
    } else {
      right[i - middle] = array[i];
    }
    printf(" %d ", array[i]);
  }
  printf("\n");

  /* print left array */
  for (int i = 0; i < left_size; i++) {
    printf(" %d ", left[i]);
  }
  printf("\n");

  /* print right array */
  for (int i = 0; i < right_size; i++) {
    printf(" %d ", right[i]);
  }
  printf("\n");
  
  sorted_left = merge_sort(left, left_size);
  sorted_right = merge_sort(right, right_size);

  merged = merge(sorted_left, sorted_right, left_size, right_size);

  return merged;
}

int * merge(int *left, int *right, int left_size, int right_size) {
  int *merged = calloc(left_size + right_size, sizeof(int));

  /* [todo] merge them.. */
  for (int i = 0; i < left_size + right_size; i++) {
    if (left[0] < right [0]) {
      merged[i] = left[0];
      memmove(left, left + 1, left_size * sizeof(int));
    } else {
      merged[i] = right[0];
      memmove(right, right + 1, right_size * sizeof(int));
    }

  }

  return merged;
}
