compile: c s

c: basic_client.o pipe_networking.o
	gcc -o controlFile basic_client.o pipe_networking.o

s: basic_server.o pipe_networking.o
	gcc -o serverFile basic_server.o pipe_networking.o

client: controlFile
	./controlFile

server: serverFile
	./serverFile

basic_client.o: basic_client.c pipe_networking.h
	gcc -c basic_client.c

basic_server.o: basic_server.c pipe_networking.h
	gcc -c basic_server.c

pipe_networking.o: pipe_networking.c pipe_networking.h
	gcc -c pipe_networking.c

clean:
	rm serverFile controlFile mario
	rm *.o
