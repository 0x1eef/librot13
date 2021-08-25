# librot13

**Table of contents**

* <a href='#introduction'>Introduction</a>
* <a href='#usage'>Usage</a>
* <a href='#install'>Install / uninstall</a>
* <a href='#license'>License</a>

## <a id='introduction'>Introduction</a>

librot13 is a shared library written in C that implements the 
[rot13 substitution cipher](https://en.wikipedia.org/wiki/ROT13).
It was written for fun and to learn more about C and shared libraries
on Linux.

## <a id='usage'>Usage</a>

```C
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

```

## <a id='install'>Install / uninstall</a>

**Install**

The install process is specific to Linux for now. After the shared library 
and headers are installed `gcc -lrot13` can be used for linking the shared 
library. By default headers are installed to `/usr/local/include` and the 
shared library is installed to `/usr/local/lib`.

    git clone https://github.com/0x1eef/librot13
    cd librot13
    make
    sudo make install

Optionally compile and run the example 

    gcc -lrot13 examples/example.c -o tmp/example
    ./tmp/example

**Uninstall**

    sudo make uninstall

## <a id='license'>License</a>

MIT