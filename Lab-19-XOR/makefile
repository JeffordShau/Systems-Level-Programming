hexdump: a.out
	@./a.out hexdump $(ARGS)

encode: a.out
	@./a.out encode $(ARGS)

decode: a.out
	@./a.out decode $(ARGS)

a.out: main.o code.o code.h
	@gcc main.o code.o

main.o: main.c code.h
	@gcc -c main.c

code.o: code.c
	@gcc -c code.c