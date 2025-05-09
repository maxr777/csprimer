#include <assert.h>
#include <stdio.h>

int bitcount(long number) {
  int result = 0;
  while (number > 0) {
    if ((number & 0x00000001) == 1)
      ++result;
    number = number >> 1;
  }
  return result;
}

int main() {
  assert(bitcount(0) == 0);
  assert(bitcount(1) == 1);
  assert(bitcount(3) == 2);
  assert(bitcount(8) == 1);
  assert(bitcount(0xffffffff) == 32);
  printf("OK\n");
}
