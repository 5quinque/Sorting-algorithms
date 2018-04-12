#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"
#include "sorting_algorithms.h"

int main(int argc, char **argv) {
  int *array;
  int *tmp_array;
  int array_size = 0;
  int output = 1;

  int c;

  while ((c = getopt(argc, argv, "l:q")) != -1) {
    switch (c) {
    case 'l':
      array_size = atoi(optarg);
      break;
    case 'q':
      output = 0;
      break;
    case '?':
      printf("Usage: %s [-l size of list] [-q]\n", argv[0]);
      return 1;
    default:
      break;
    }
  }
  if (!array_size) {
    printf("Usage: %s [-l size of list] [-q]\n", argv[0]);                    
    return 1;
  }

  printf("Bubble Sort:\n");
  fill_array(&array, array_size);
  if (output)
    print_array(array, array_size);
  bubble(array, array_size);
  if (output)
    print_array(array, array_size);
  printf("\n");

  printf("Insert Sort:\n");
  fill_array(&array, array_size);
  if (output)
    print_array(array, array_size);
  insert(array, array_size);
  if (output)
    print_array(array, array_size);
  printf("\n");
  
  printf("Selection Sort:\n");
  fill_array(&array, array_size);
  if (output)
    print_array(array, array_size);
  selection(array, array_size);
  if (output)
    print_array(array, array_size);
  printf("\n");

  printf("Merge Sort:\n");
  fill_array(&array, array_size);
  if (output)
    print_array(array, array_size);
  tmp_array = merge_sort(array, array_size);
  if (output)
    print_array(tmp_array, array_size);
  printf("\n");

  free(array);
  free(tmp_array);

  return 0;
}

