#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int *merge_sort(int *array, int array_size);
int *merge(int *left, int *right, int left_size, int right_size);

int main(int argc, char **argv) {
  int *array;
  int *sorted_array;
  int array_size;
  int output = 1;

  if (argc < 2) {
    printf("Usage: %s [size of list]\n", argv[0]);
    return 1;
  }
  if (argc >= 3 && !strcmp(argv[2], "-q")) {
    output = 0;
  }

  array_size = atoi(argv[1]);
  fill_array(&array, array_size);

  if (output) {
    print_array(array, array_size);
  }

  sorted_array = merge_sort(array, array_size);

  if (output) {
    print_array(sorted_array, array_size);
  }

  printf("Done\n");

  free(sorted_array);
  free(array);

  return 0;
}

int *merge_sort(int *array, int array_size) {
  int *left;
  int *right;
  int *merged;
  int middle;
  int left_size;
  int right_size;

  if (array_size == 1) {
    return array;
  }

  middle = (array_size + 1) / 2;
  left_size = middle;
  right_size = array_size - middle;

  left = malloc(left_size * sizeof(int));
  right = malloc(right_size * sizeof(int));

  /* split array in half */
  memcpy(left, array, left_size * sizeof(int));
  memcpy(right, array + left_size, right_size * sizeof(int));
  
  left = merge_sort(left, left_size);
  right = merge_sort(right, right_size);

  merged = merge(left, right, left_size, right_size);

  free(left);
  free(right);

  return merged;
}

int *merge(int *left, int *right, int left_size, int right_size) {
  int *merged = calloc(left_size + right_size, sizeof(int));

  int lp = 0;
  int rp = 0;

  for (int i = 0; i < left_size + right_size; i++) {
    if (lp == left_size) {
      merged[i] = right[rp++];
      continue;
    }
    if (rp == right_size) {
      merged[i] = left[lp++];
      continue;
    }

    merged[i] = left[lp] < right[rp] ? left[lp++] : right[rp++];
  }

  return merged;
}
