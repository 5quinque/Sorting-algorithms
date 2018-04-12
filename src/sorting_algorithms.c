#include <stdlib.h>
#include <string.h>
#include "sorting_algorithms.h"

void insert(int *array, int array_size) {
  int left = 0;
  int tmp;

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
}

void bubble(int *array, int array_size) {
  int swapped = 1;
  int tmp;

  while (swapped) {
    swapped = 0;
    for (int i = 0; i < array_size - 1; i++) {
      /*if (array[i] <= array[i + 1]) {*/
        /*continue;*/
      /*}*/
      if (array[i] > array[i + 1]) {
        swapped = 1;
        tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
      }
    }
  }
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

void selection(int *array, int array_size) {
  int lowest;
  int tmp;

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
}
