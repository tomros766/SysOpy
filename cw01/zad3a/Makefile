CC=gcc
CFLAGS=-c -Wall
Op=O0

all: static_lib shared_lib clean

main:
	make clean
	$(CC) $(CFLAGS) library.c
	$(CC) -Wall library.o main.c -o main

static_lib:
	$(CC) -$(Op) -c library.c
	ar rcs library.a library.o

shared_lib:
	$(CC) -$(Op) -c -fPIC library.c
	$(CC) -$(Op) -shared -fPIC -o library.so library.o

zad3_static:
	make static_lib
	make tests

zad3_shared:
	make shared_lib
	make tests


tests:

	touch results3.txt
	./main create_table 100 compare_pairs a.txt:b.txt a.txt:c.txt a.txt:d.txt a.txt:e.txt a.txt:f.txt b.txt:c.txt b.txt:d.txt b.txt:e.txt b.txt:f.txt c.txt:e.txt d.txt:f.txt d.txt:e.txt remove_block 1 remove_block 3 remove_block 5 compare_pairs b.txt:c.txt remove_block 2
clean:
	rm -f block
	rm -f *.o tmp
	rm -f *.so tmp
	rm -f *.a tmp
	rm -f main tmp
