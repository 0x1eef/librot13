#include <stdio.h>
#include <stdlib.h>
#include <rot13.h>

int
main() {
  char *str = rot13("Hello world");
  printf("%s\n", str);
  free(str);
  return 0;
}
