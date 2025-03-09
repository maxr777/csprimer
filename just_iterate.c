#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int binary_search(int number, int arr[], int size) {
  int index = 0, lower_bound = 0, upper_bound = size - 1, found = 0;

  while (upper_bound > (lower_bound + 1)) {
    index = (lower_bound + upper_bound) / 2;
    if (arr[index] == number)
      return index;
    else if (arr[index] < number)
      lower_bound = index;
    else if (arr[index] > number)
      upper_bound = index;
  }

  return -1;
}

int iterate_search(int number, int arr[], int size) {
  if (size <= 0)
    return -1;

  if (arr[0] > number)
    return -1;
  if (arr[size - 1] < number)
    return -1;

  for (int i = 0; i < size; i++) {
    if (arr[i] == number)
      return i;
  }

  return -1;
}

void fill_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand();
  }
}

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

double current_time_ns() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return (double)ts.tv_sec * 1.0e9 + (double)ts.tv_nsec; // Return nanoseconds
}

int main() {
  srand(time(NULL));

  int arr_size = 100;
  int *arr = malloc(arr_size * sizeof(int));
  fill_array(arr, arr_size);
  qsort(arr, arr_size, sizeof(int), compare);
  int index = 0 + rand() % (arr_size - 0 + 1);
  int number = arr[index];

  double start, end;
  start = current_time_ns();
  binary_search(number, arr, arr_size);
  end = current_time_ns();
  double elapsed_binary = end - start;

  start = current_time_ns();
  iterate_search(number, arr, arr_size);
  end = current_time_ns();
  double elapsed_iterate = end - start;

  printf("size = %d\tbinary search = %.2f\titerate search = %.2f\n", arr_size, elapsed_binary, elapsed_iterate);

  arr_size = 100;
  int *arr1 = malloc(arr_size * sizeof(int));
  fill_array(arr1, arr_size);
  qsort(arr1, arr_size, sizeof(int), compare);
  index = 0 + rand() % (arr_size - 0 + 1);
  number = arr1[index];

  start = current_time_ns();
  binary_search(number, arr1, arr_size);
  end = current_time_ns();
  elapsed_binary = end - start;

  start = current_time_ns();
  iterate_search(number, arr1, arr_size);
  end = current_time_ns();
  elapsed_iterate = end - start;

  printf("size = %d\tbinary search = %.2f\titerate search = %.2f\n", arr_size, elapsed_binary, elapsed_iterate);
}
