CC=gcc
prefix=/usr/local
exec_prefix=${DESTDIR}$(prefix)
includedir=$(DESTDIR)$(prefix)/include
libdir=$(DESTDIR)$(exec_prefix)/lib
builddir=./tmp
soname=librot13.so

librot13:
	mkdir -p $(builddir)
	$(CC) -c -fpic src/rot13.c -o $(builddir)/librot13.o
	$(CC) -shared -o $(builddir)/$(soname) $(builddir)/librot13.o

install:
	cp $(builddir)/$(soname) $(libdir)
	cp src/rot13.h $(includedir)

uninstall:
	rm $(libdir)/$(soname) $(includedir)/rot13.h

example: librot13
	gcc -lrot13 -Isrc -L$(builddir) examples/example.c -o tmp/example
	LD_LIBRARY_PATH=$(builddir) ./tmp/example

clean:
	rm -rf $(builddir)
