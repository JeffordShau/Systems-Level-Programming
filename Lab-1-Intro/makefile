compile: main.o song.o library.o
	gcc -o file main.o song.o library.o
run:
	./file
song.o: song.c song.h
	gcc -c song.c
library.o: library.c library.h song.h
	gcc -c library.c
main.o: main.c library.h song.h
	gcc -c main.c
clear:
	rm main.o song.o library.o file
