#ifndef SONG_H
#define SONG_H
struct song_node
{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct song_node *makeSong(char *song_name, char *song_artist);
int getLength(struct song_node *head);
struct song_node *insertSongFront(struct song_node *front, char *song_name, char *song_artist);
struct song_node *insertSong(struct song_node *front, char *song_name, char *song_artist);
int insertSongHelper(char *string1, char *string2);

struct song_node *getSongIndex(struct song_node *head, int index);
struct song_node *getSong(struct song_node *start, char *song_name, char *song_artist);
struct song_node *getArtistSong(struct song_node *front, char *song_artist);
struct song_node *getSameCharacterSongs(struct song_node *front, char c);
struct song_node *randomSong(struct song_node *front);

struct song_node *deleteSong(struct song_node *front, char *name, char *artist);

struct song_node *freeSongList(struct song_node *front);
void printSongList(struct song_node *front);
#endif
