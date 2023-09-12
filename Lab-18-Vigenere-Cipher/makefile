encode: encodeMain.o helper.o
	@gcc -o encodeFile encodeMain.o helper.o -lm
	@./encodeFile $(ARGS)

decode: decodeMain.o helper.o
	@gcc -o decodeFile decodeMain.o helper.o -lm
	@./decodeFile $(ARGS)

crack: crackMain.o helper.o
	@gcc -o crackFile crackMain.o helper.o -lm
	@./crackFile $(ARGS)

getkey: getkeyMain.o helper.o
	@gcc -o getkeyFile getkeyMain.o helper.o -lm
	@./getkeyFile $(ARGS)

encodeMain.o: encodeMain.c helper.o
	@gcc -c encodeMain.c

decodeMain.o: decodeMain.c helper.o
	@gcc -c decodeMain.c

crackMain.o: crackMain.c helper.o
	@gcc -c crackMain.c

getkeyMain.o: getkeyMain.c helper.o
	@gcc -c getkeyMain.c

clear:
	@rm encodeMain.o helper.o

#make encode ARGS="plaintextfile keyfile"
#print the ciphertext after encoding.
#make decode ARGS="ciphertextfile keyfile"
#print the plaintext after decoding.
#make crack ARGS="ciphertextfile"
#Print the most likely plaintext after decoding it with size 1-16 keys.
#make getkey ARGS="ciphertextfile"
#Print the most likely key. Keysize 16 will be the maximum size you have to check for.