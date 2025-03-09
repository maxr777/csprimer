int binary_search(int number, int arr[], int size) {
  if (size <= 0)
    return -1;

  if (size == 1) {
    if (arr[0] == number) {
      return 0;
    } else {
      return -1;
    }
  }

  if (arr[0] == number)
    return 0;
  if (arr[size - 1] == number)
    return size - 1;

  if (arr[0] > number)
    return -1;
  if (arr[size - 1] < number)
    return -1;

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

int main() {
  if (binary_search(666, (int[]){666}, 1) != 0)
    return 1;
  if (binary_search(777, (int[]){666}, 1) != -1)
    return 2;
  if (binary_search(6, (int[]){1, 2}, 2) != -1)
    return 3;
  if (binary_search(6, (int[]){1, 6}, 2) != 1)
    return 4;
  if (binary_search(1, (int[]){1, 2}, 2) != 0)
    return 5;
  if (binary_search(2, (int[]){1, 2, 3}, 3) != 1)
    return 6;
  if (binary_search(-1, (int[]){1, 2, 3}, 3) != -1)
    return 7;
  if (binary_search(4, (int[]){1, 2, 3}, 3) != -1)
    return 8;
  if (binary_search(6, (int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, 11) != 5)
    return 9;
  if (binary_search(8, (int[]){1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12}, 11) != -1)
    return 10;
  if (binary_search(6, (int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10) != 5)
    return 11;
  if (binary_search(2, (int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10) != 1)
    return 12;
  if (binary_search(8, (int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10) != 7)
    return 13;
  if (binary_search(3, (int[]){-1, 1, 2, 4, 5, 6, 7, 8, 9, 10}, 10) != -1)
    return 14;
}
