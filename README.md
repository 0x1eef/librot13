# librot13

**Table of contents**

* <a href='#introduction'>Introduction</a>
* <a href='#usage'>Usage</a>
* <a href='#build'>Build</a>
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
#include "src/rot13.h"

int
main() 
{
  char *str = rot13("Hello world");
  printf("%s\n", str);
  free(str);
  return 0;
}
```

## <a id='build'>Build</a>

For now there is no install step.  
Instead the `Makefile` will create `librot13.so` in the project-local `build/` 
directory and from there it can be linked to during compilation. For example:

    git clone https://github.com/0x1eef/librot13
    cd librot13
    make
    gcc -Lbuild -lrot13 examples/example.c -o examples/example 
    ./examples/example



## <a id='license'>License</a>

MIT