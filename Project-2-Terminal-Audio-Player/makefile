run: a.out
	./a.out

a.out: compile
	make compile

compile: main.o helpers.o linkedList.o musicLibrary.o arrowSelection.o musicPlayer.o
	gcc main.o helpers.o linkedList.o musicLibrary.o arrowSelection.o musicPlayer.o -lncurses -lmenu 

main.o: main.c
	gcc -c main.c

linkedList.o: linkedList.c
	gcc -c linkedList.c 

musicLibrary.o: musicLibrary.c
	gcc -c musicLibrary.c

arrowSelection.o: arrowSelection.c
	gcc -c arrowSelection.c -lncurses

musicPlayer.o: musicPlayer.c
	gcc -c musicPlayer.c

helpers.o: helpers.c
	gcc -c helpers.c

clear:
	rm *.o
	rm a.out
