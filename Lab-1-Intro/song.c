#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// allocate memory for a song_node
struct song_node *makeSong(char *song_name, char *song_artist)
{
  struct song_node *new_song = malloc(sizeof(struct song_node));
  strcpy(new_song->name, song_name);
  strcpy(new_song->artist, song_artist);
  new_song->next = NULL;
  return new_song;
}

// get the length of a linked list by iterating through all values
int getLength(struct song_node *head)
{
  int length = 0;
  while (head)
  {
    length++;
    head = head->next;
  }
  return length;
}

struct song_node *getSongIndex(struct song_node *head, int index)
{
  int i = 0;
  while (i < index)
  {
    head = head->next;
    i++;
  }
  return head;
}

// insert song_node at the front and return pointer to new_song
struct song_node *insertSongFront(struct song_node *front, char *song_name, char *song_artist)
{
  if (front == NULL)
  {
    front = makeSong(song_name, song_artist);
    return front;
  }
  struct song_node *new_song = malloc(sizeof(struct song_node));
  strcpy(new_song->name, song_name);
  strcpy(new_song->artist, song_artist);
  new_song->next = front;
  return new_song;
}

// insert song_node alphabetically by artist, then song_name and return pointer to front
struct song_node *insertSong(struct song_node *front, char *song_name, char *song_artist)
{
  if (front == NULL)
  {
    front = makeSong(song_name, song_artist);
    return front;
  }
  struct song_node *head = front;
  struct song_node *trail = front;
  struct song_node *new_song = makeSong(song_name, song_artist);
  front = front->next;
  while (front)
  {
    if ((strcasecmp(front->artist, song_artist) == 0 && strcasecmp(front->name, song_name) > 0) || strcasecmp(front->artist, song_artist) > 0)
    {
      trail->next = new_song;
      new_song->next = front;
      return head;
    }
    trail = trail->next;
    front = front->next;
  }
  // if last song in the list
  trail->next = new_song;
  return head;
}

// remove song_node with specific artist and song name and returns pointer to front
struct song_node *deleteSong(struct song_node *front, char *artist, char *song)
{
  struct song_node *head = front;
  struct song_node *temp;
  // target card is first card
  if (strcasecmp(front->name, song) == 0 && strcasecmp(front->artist, artist) == 0)
  {
    temp = front;
    front = front->next;
    free(temp);
    return front;
  }

  // target song is not first
  struct song_node *trail = front;
  front = front->next;
  while (front)
  {
    if (strcasecmp(front->name, song) == 0 && strcasecmp(front->artist, artist) == 0)
    {
      trail->next = front->next;
      free(front);
      return head;
    }
    trail = front;
    front = front->next;
  }
  return head;
}

// print entire list
void printSongList(struct song_node *front)
{
  printf("[ ");
  while (front != NULL)
  {
    printf("{%s, %s} | ", front->artist, front->name);
    front = front->next;
  }
  printf("]\n");
}

// find and return a pointer to a node based on artist and song name
struct song_node *getSong(struct song_node *front, char *song_name, char *song_artist)
{
  struct song_node *song = NULL;
  while (front)
  {
    if (strcmp(front->artist, song_artist) == 0 && strcmp(front->name, song_name) == 0)
    {
      song = insertSongFront(song, front->name, front->artist);
      if (song)
      {
        printf("Song found! ");
        return song;
      }
    }
    front = front->next;
  }
  printf("Artist not found ");
  return NULL;
}

// find and return a pointer to the first song of an artist based on artist song_name
struct song_node *getArtistSong(struct song_node *front, char *song_artist)
{
  struct song_node *songs = NULL;
  while (front)
  {
    if (strcasecmp(front->artist, song_artist) == 0)
    {
      songs = insertSongFront(songs, front->name, front->artist);
    }
    front = front->next;
  }
  if (songs == NULL)
  {
    printf("Artist not found ");
  }
  else {
    printf("Song found! ");
  }
  return songs;
}

struct song_node *getSameCharacterSongs(struct song_node *front, char c)
{
  struct song_node *songs = NULL;
  while (front)
  {
    if (tolower(front->name[0]) == tolower(c))
    {
      songs = insertSongFront(songs, front->name, front->artist);
    }
    front = front->next;
  }
  return songs;
}

// return a pointer to random element in the list
struct song_node *randomSong(struct song_node *front)
{
  if (front == NULL)
  {
    return NULL;
  }
  struct song_node *temp = front;
  int songCounter = getLength(front);
  if (songCounter == 0)
  {
    return front;
  }
  int randNum = rand() % (songCounter + 1);
  for (int i = 0; i < randNum; i++)
  {
    temp = temp->next;
  }
  return temp;
}

// free entire list
struct song_node *freeSongList(struct song_node *front)
{
  if (!front)
  {
    return front;
  }
  struct song_node *head = front;
  struct song_node *temp;
  while (front)
  {
    temp = front;
    front = front->next;
    free(temp);
    temp = NULL;
  }
  front = NULL;
  return front;
}
