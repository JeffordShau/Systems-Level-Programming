#ifndef LIBRARY_H
#define LIBRARY_H
struct song_node **makeSongLibrary();
struct song_node **insertFront(struct song_node **front, char *name, char *artist);
struct song_node **insert(struct song_node **front, char *name, char *artist);
struct song_node *search(struct song_node **front, char *song, char *artist);
struct song_node *searchArtist(struct song_node **front, char *artist);
struct song_node *combineLibrary(struct song_node **front);
void printCharacterList(struct song_node **front, char c);
void printArtistSongs(struct song_node **front, char *artist);
void printSameCharacterSongs(struct song_node **front, char c);
void printLibrary(struct song_node **front);
void shuffle(struct song_node **front, int num);
void delete (struct song_node **front, char *name, char *artist);
struct song_node **clear_library(struct song_node **front);
#endif
