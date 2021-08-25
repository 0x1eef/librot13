CC=gcc

librot13: clean
	mkdir -p build
	$(CC) -c -fpic src/rot13.c -o build/librot13.o
	$(CC) -shared -o build/librot13.so build/librot13.o

example: librot13
	gcc -Lbuild -lrot13 examples/example.c -o examples/example
	./examples/example

clean:
	rm build/*
