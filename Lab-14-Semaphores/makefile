compile: output1 output2

output1: write.o control.o
	gcc -o output1 write.o control.o

output2: controlMain.o control.o control.h
	gcc -o output2 controlMain.o control.o

write.o: write.c
	gcc -c write.c

control.o: control.c
	gcc -c control.c

controlMain.o: controlMain.c
	gcc -c controlMain.c

write:
	./output1

control:
	./output2 $(ARGS)

clear:
	rm output1 output2 write.o control.o
