CC=gcc
prefix=/usr/local
exec_prefix=${DESTDIR}$(prefix)
includedir=$(DESTDIR)$(prefix)/include
libdir=$(DESTDIR)$(exec_prefix)/lib

librot13:
	mkdir -p tmp
	$(CC) -c -fpic src/rot13.c -o tmp/librot13.o
	$(CC) -shared -o tmp/librot13.so tmp/librot13.o

install:
	cp tmp/librot13.so $(libdir)
	cp src/rot13.h $(includedir)

uninstall:
	rm $(libdir)/librot13.so $(includedir)/rot13.h

clean:
	rm -rf tmp
