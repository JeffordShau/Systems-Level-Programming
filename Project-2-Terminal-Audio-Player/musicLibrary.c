#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

struct song **createLibrary()
{
  struct song **retVal = (struct song **)calloc(27, sizeof(struct song **));
  return retVal;
}

int indexConverter(char x)
{
  if (x < 65 || (x > 90 && x < 97) || x > 122)
  {
    return 0;
  } // special characters at front

  int y = 1;
  for (char i = 65; i < 91; i++)
  {
    if ((x == i) || (x == (i + 32)))
    {
      return y;
    }
    y++;
  }
  return -1;
}

char *songToString(struct song *song)
{
  char *retVal = (char *)calloc(100, sizeof(char));
  strcat(retVal, song->name);
  strcat(retVal, " - ");
  strcat(retVal, song->artist);
  return retVal;
}

struct song **addSong(struct song **library, struct song *newSong)
{
  int index = indexConverter((newSong->artist)[0]);
  library[index] = insertOrder(library[index], newSong->name, newSong->artist, newSong->path);
  return library;
}

struct song **addSongFront(struct song **library, struct song *newSong)
{
  int index = indexConverter((newSong->artist)[0]);
  library[index] = insertFront(library[index], newSong->name, newSong->artist, newSong->path);
  return library;
}

struct song *songSearch(struct song **library, char *name, char *artist)
{
  int index = indexConverter(artist[0]);
  if (library[index] == NULL)
  {
    return NULL;
  }
  return fullSearch(library[index], name, artist);
}

struct song *artistSearchLibrary(struct song **library, char *artist)
{
  int counter = 0;
  while (counter < 27)
  {
    if (library[counter] == NULL)
    {
      counter++;
      continue;
    }
    else if (artistSearch(library[counter], artist) == NULL)
    {
      counter++;
    }
    else
    {
      return artistSearch(library[counter], artist);
    }
  }
  return NULL;
}

void printLibrary(struct song **library)
{
  for (int i = 0; i < 27; i++)
  {
    if (i == 0)
    {
      printf("Special Characters:\n");
    }
    else
    {
      printf("%c:\n", 64 + i);
    }
    printf("  ");
    printList(library[i]);
  }
  printf("\n");
  return;
}

int librarySize(struct song **library)
{
  int counter = 0;
  for (int i = 0; i < 27; i++)
  {
    if (library[i] != NULL)
    {
      struct song *temp = library[i];
      while (temp != NULL)
      {
        counter++;
        temp = temp->next;
      }
    }
  }
  return counter;
}

void printLetter(struct song **library, char a)
{
  int index = indexConverter(a);
  printList(library[index]);
}

void printArtist(struct song **library, char *artist)
{
  int boolean = 0;
  for (int i = 0; i < 27; i++)
  {
    struct song *temp = library[i];
    while (temp)
    {
      if (strcmp(lowercaseString(temp->artist), lowercaseString(artist)) == 0)
      {
        boolean = 1;
        printSong(temp);
        printf(" ");
      }
      temp = temp->next;
    }
  }
  if (boolean == 0)
  {
    printf("No Song Found");
  }
}

int emptyLibrary(struct song **library)
{
  for (int i = 0; i < 26; i++)
  {
    if (library[i] != NULL)
      return 0;
  }
  return 1;
}

void shufflePlaylist(struct song **libraryOriginal)
{
  struct song *fullLibrary = NULL;
  struct song **library = libraryOriginal;
  for (int i = 0; i < 27; i++)
  {
    struct song *temp = library[i]; // createSong(library[i]->name, library[i]->artist);
    while (temp)
    {
      fullLibrary = insertFront(fullLibrary, temp->name, temp->artist, temp->path);
      temp = temp->next;
    }
  }
  int i = 5;
  while (i > 0)
  {
    struct song *shuffleSong = randomSong(fullLibrary);
    printSong(shuffleSong);
    printf("\n");
    i--;
  }
}

struct song **deleteSong(struct song **library, char *name, char *artist)
{
  int index = indexConverter(artist[0]);
  library[index] = removeSong(library[index], name, artist);
  return library;
}

struct song **clearLibrary(struct song **library)
{
  for (int i = 0; i < 27; i++)
  {
    library[i] = freeList(library[i]);
  }
  return library;
}