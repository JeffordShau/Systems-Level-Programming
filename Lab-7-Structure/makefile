compile: main.o struct.o struct.h
	gcc -o struct main.o struct.o

run:
	./struct

main.o: main.c
	gcc -c main.c

struct.o: struct.c
	gcc -c struct.c

clear:
	rm struct.h.gch struct.o main.o
