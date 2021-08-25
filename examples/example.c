#include <stdio.h>
#include <stdlib.h>
#include <rot13.h>

int
main() {
  char *str1, *str2;

  str1 = rot13("Hello world");
  str2 = rot13(str1);
  printf("encoded: %s\n", str1);
  printf("decoded: %s\n", str2);
  free(str1);
  free(str2);

  return 0;
}
