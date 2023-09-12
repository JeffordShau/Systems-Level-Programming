compile: main.o pop.o
	gcc -o structrw main.o pop.o -lm

run:
	./structrw $(ARGS)

main.o: main.c
	gcc -c main.c

pop.o: pop.c pop.h
	gcc -c pop.c pop.h 

clear:
	rm main.o pop.h.gch pop.o structrw nyc_pop.dat
