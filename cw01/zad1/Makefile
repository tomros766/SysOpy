CC=gcc
CFLAGS=-c -Wall
all: static_lib shared_lib clean

main:
	make clean
	$(CC) $(CFLAGS) library.c
	$(CC) -Wall library.o main.c -o main

static_lib:
	$(CC)  -c library.c
	ar rcs library.a library.o

shared_lib:
	$(CC) -c -fPIC library.c
	$(CC) -shared -fPIC -o library.so library.o


clean:
	rm -f block
	rm -f *.o tmp
	rm -f *.so tmp
	rm -f *.a tmp
	rm -f main tmp
