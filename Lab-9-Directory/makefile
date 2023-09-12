compile: main.o directory.o
	gcc -o file main.o directory.o

run:
	./file $(ARGS)

directory.o: directory.c directory.h
	gcc -c directory.c directory.h

main.o: main.c
	gcc -c main.c

clear:
	rm directory.h.gch directory.o file main.o
