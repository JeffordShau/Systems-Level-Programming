compile: main.o parse.o
	gcc -o file main.o parse.o

run:
	./file

main.o: main.c
	gcc -c main.c

parse.o: parse.c parse.h
	gcc -c parse.c parse.h

clear:
	rm main.o parse.o parse.h.gch
