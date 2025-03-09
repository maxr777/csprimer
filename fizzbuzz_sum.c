int fizzbuzz_sum(int n) {
  if (n < 3)
    return 0;

  int result = 0;
  result += 3 * (n / 3) * ((n / 3) + 1) / 2;
  result += 5 * (n / 5) * ((n / 5) + 1) / 2;
  result -= 15 * (n / 15) * ((n / 15) + 1) / 2;

  return result;
}

int main() {
  if (fizzbuzz_sum(9) != 23)
    return 1;

  if (fizzbuzz_sum(10) != 33)
    return 1;

  if (fizzbuzz_sum(15) != 60)
    return 1;
}
