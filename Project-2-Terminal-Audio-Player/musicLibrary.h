#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H
#include "linkedList.h"

struct song **createLibrary();
int indexConverter(char x);
struct song **addSong(struct song **library, struct song *newSong);
struct song **addSongFront(struct song **library, struct song *newSong);
void printLibrary(struct song **library);
struct song *songSearch(struct song **library, char *name, char *artist);
struct song *artistSearchLibrary(struct song **library, char *artist);
void printLetter(struct song **library, char a);
void printArtist(struct song **library, char *artist);
void shufflePlaylist(struct song **libraryOriginal);
struct song **deleteSong(struct song **library, char *name, char *artist);
struct song **clearLibrary(struct song **library);
int librarySize(struct song **library);
char *songToString(struct song *song);
#endif
