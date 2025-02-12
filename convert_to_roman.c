#include <stdio.h>
#include <string.h>

char *convert_to_roman(int number) {
  if (number > 3999 || number < 1)
    return "";

  char *result;

  return result;
}

int main() {
  char *result = convert_to_roman(3);
  if (strcmp(result, "III") != 0) {
    printf("convert_to_roman(3) = %s\texpected: III", result);
    return 1;
  }

  result = convert_to_roman(8);
  if (strcmp(result, "VIII") != 0) {
    printf("convert_to_roman(8) = %s\texpected: VIII", result);
    return 1;
  }

  result = convert_to_roman(31);
  if (strcmp(result, "XXXI") != 0) {
    printf("convert_to_roman(31) = %s\texpected: XXXI", result);
    return 1;
  }

  result = convert_to_roman(44);
  if (strcmp(result, "XLIV") != 0) {
    printf("convert_to_roman(44) = %s\texpected: XLIV", result);
    return 1;
  }

  result = convert_to_roman(87);
  if (strcmp(result, "LXXXVII") != 0) {
    printf("convert_to_roman(87) = %s\texpected: LXXXVII", result);
    return 1;
  }

  result = convert_to_roman(92);
  if (strcmp(result, "XCII") != 0) {
    printf("convert_to_roman(92) = %s\texpected: XCII", result);
    return 1;
  }

  result = convert_to_roman(222);
  if (strcmp(result, "CCXXII") != 0) {
    printf("convert_to_roman(222) = %s\texpected: CCXXII", result);
    return 1;
  }

  result = convert_to_roman(586);
  if (strcmp(result, "DLXXXVI") != 0) {
    printf("convert_to_roman(586) = %s\texpected: DLXXXVI", result);
    return 1;
  }

  result = convert_to_roman(981);
  if (strcmp(result, "CMLXXXI") != 0) {
    printf("convert_to_roman(981) = %s\texpected: CMLXXXI", result);
    return 1;
  }

  result = convert_to_roman(2053);
  if (strcmp(result, "MMLIII") != 0) {
    printf("convert_to_roman(2053) = %s\texpected: MMLIII", result);
    return 1;
  }

  result = convert_to_roman(3999);
  if (strcmp(result, "MMMCMXCIX") != 0) {
    printf("convert_to_roman(2053) = %s\texpected: MMMCMXCIX", result);
    return 1;
  }
}
