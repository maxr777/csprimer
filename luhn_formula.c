#include <stdio.h>

int validate(long number) {
  int counter = 0, sum = 0, last_digit = number % 10;
  number /= 10;

  while (number > 0) {
    int digit = number % 10;

    if (counter % 2 == 0)
      digit *= 2;
    else
      digit *= 1;

    if (digit > 9)
      sum += digit - 9;
    else
      sum += digit;

    number /= 10;
    counter++;
  }

  if ((10 - (sum % 10)) % 10 == last_digit)
    return 1;

  return 0;
}

int main() {
  if (validate(17893729974L) != 1)
    return 1;

  printf("test 1 passed\n");

  if (validate(4539148803436467L) != 1)
    return 1;

  printf("test 2 passed\n");

  if (validate(6011000990139424L) != 1)
    return 1;

  printf("test 3 passed\n");

  if (validate(4539148803436468L) == 1)
    return 1;

  printf("test 4 passed\n");

  if (validate(6011000990139425L) == 1)
    return 1;

  printf("test 5 passed\n");

  if (validate(30569309825065L) == 1)
    return 1;

  printf("test 6 passed\n");
}
