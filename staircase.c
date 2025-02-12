#include <stdio.h>

int staircase_stepper(int steps) {
  if (steps <= 0)
    return 0;

  switch (steps) {
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 4;
  }

  int result = 0;
  result = staircase_stepper(steps - 1) + staircase_stepper(steps - 2) + staircase_stepper(steps - 3);

  return result;
}

int main() {
  int result = staircase_stepper(1);
  if (result != 1) {
    printf("staircase_stepper(1) = %d\nexpected: 1\n", result);
    return 1;
  }

  result = staircase_stepper(2);
  if (result != 2) {
    printf("staircase_stepper(1) = %d\nexpected: 2\n", result);
    return 1;
  }

  result = staircase_stepper(3);
  if (result != 4) {
    printf("staircase_stepper(3) = %d\nexpected: 4\n", result);
    return 1;
  }

  result = staircase_stepper(4);
  if (result != 7) {
    printf("staircase_stepper(4) = %d\nexpected: 7\n", result);
    return 1;
  }

  result = staircase_stepper(5);
  if (result != 13) {
    printf("staircase_stepper(5) = %d\nexpected: 13\n", result);
    return 1;
  }

  result = staircase_stepper(6);
  if (result != 24) {
    printf("staircase_stepper(6) = %d\nexpected: 24\n", result);
    return 1;
  }
}
