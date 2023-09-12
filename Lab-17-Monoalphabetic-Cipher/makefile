frequency: frequencyMain.o cipher.o
	@gcc -o frequencyFile frequencyMain.o cipher.o -lm
	@./frequencyFile $(ARGS)

distance: distanceMain.o cipher.o
	@gcc -o distanceFile distanceMain.o cipher.o -lm
	@./distanceFile $(ARGS)

decode: decodeMain.o cipher.o
	@gcc -o decodeFile decodeMain.o cipher.o -lm
	@./decodeFile $(ARGS)

vigenere: VigenereHWMain.o cipher.o
	@gcc -o vigenereFile VigenereHWMain.o cipher.o -lm
	@./vigenereFile $(ARGS)

frequencyMain.o: frequencyMain.c cipher.h
	@gcc -c frequencyMain.c

distanceMain.o: distanceMain.c cipher.h
	@gcc -c distanceMain.c

decodeMain.o: decodeMain.c cipher.h
	@gcc -c decodeMain.c

VigenereHWMain.o: VigenereHWMain.c cipher.h
	@gcc -c VigenereHWMain.c

cipher.o: cipher.c cipher.h
	@gcc -c cipher.c

clear:
	@rm frequencyFile distanceFile decodeFile decodeMain.o decodeMain.o frequencyMain.o cipher.o