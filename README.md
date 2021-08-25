# librot13

**Table of contents**

* <a href='#introduction'>Introduction</a>
* <a href='#usage'>Usage</a>
* <a href='#install'>Install</a>
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
main() 
{
  char *str = rot13("Hello world");
  printf("%s\n", str);
  free(str);
  return 0;
}
```

## <a id='install'>Install / uninstall</a>

**Install**

The install process is specific to Linux for now. After the shared library 
and headers are installed `gcc -lrot13` can be used for linking the shared library.

    git clone https://github.com/0x1eef/librot13
    cd librot13
    make
    sudo make install

Optionally compile and run the example 

    gcc -lrot13 examples/example.c -o example
    ./example

**Uninstall**

    sudo make uninstall

## <a id='license'>License</a>

MIT