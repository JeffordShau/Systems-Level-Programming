#include "library.h"
#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

/*
Tasks:
Shuffle - print out a series of randomly chosen songs.
*/

struct song_node **makeSongLibrary()
{
    int arraySize = 27;
    struct song_node **library = malloc(arraySize * sizeof(struct song_node *));
    for (int i = 0; i < arraySize; i++)
    {
        library[i] = NULL;
    }
    return library;
}

struct song_node **insertFront(struct song_node **front, char *name, char *artist)
{
    int index = tolower(artist[0]) - 'a';
    if (index < 0 || index > 26)
    {
        index = 26;
    }
    front[index] = insertSongFront(front[index], name, artist);
    return front;
}

struct song_node **insert(struct song_node **front, char *name, char *artist)
{
    int index = tolower(artist[0]) - 'a';
    if (index < 0 || index > 26)
    {
        index = 26;
    }
    front[index] = insertSong(front[index], name, artist);
    return front;
}

void delete (struct song_node **front, char *name, char *artist)
{
    int index = tolower(artist[0]) - 'a';
    if (index < 0 || index > 26)
    {
        index = 26;
    }
    front[index] = deleteSong(front[index], artist, name);
}

struct song_node *search(struct song_node **front, char *song, char *artist)
{
    int index = tolower(artist[0]) - 'a';
    if (index < 0 || index > 26)
    {
        index = 26;
    }
    return getSong(front[index], song, artist);
}

struct song_node *searchArtist(struct song_node **front, char *artist)
{
    int index = tolower(artist[0]) - 'a';
    if (index < 0 || index > 26)
    {
        index = 26;
    }
    return getArtistSong(front[index], artist);
}

void printCharacterList(struct song_node **front, char c)
{
    int index = tolower(c) - 'a';
    if (index < 0 || index > 26)
    {
        index = 26;
    }
    printSongList(front[index]);
}

void printSameCharacterSongs(struct song_node **front, char c)
{
    struct song_node *songs = NULL;
    for (int i = 0; i < 27; i++)
    {
        struct song_node *head = front[i];
        while (head != NULL)
        {
            if (tolower(head->name[0]) == tolower(c))
            {
                songs = insertSongFront(songs, head->name, head->artist);
            }
            head = head->next;
        }
    }
    printSongList(songs);
    freeSongList(songs);
}

void printArtistSongs(struct song_node **front, char *artist)
{
    int index = tolower(artist[0]) - 'a';
    if (index < 0 || index > 26)
    {
        index = 26;
    }
    struct song_node *songs = getArtistSong(front[index], artist);
    printSongList(songs);
}

void printLibrary(struct song_node **front)
{
    if (front == NULL)
    {
        printf("Library is empty\n");
        return;
    }
    for (int i = 0; i < 27; i++)
    {
        if (i == 26)
        {
            printf("Others: ");
        }
        else
        {
            printf("%c list: ", i + 'A');
        }
        printSongList(front[i]);
    }
}

void shuffle(struct song_node **front, int num)
{
    struct song_node *library = combineLibrary(front);
    struct song_node *songs = NULL;
    int size = getLength(library);
    if (num > size)
    {
        printf("Not enough songs in the library...\n");
    }
    num = MIN(num, size);
    for (int i = 0; i < num; i++)
    {
        int index = rand() % (size);
        struct song_node *song = getSongIndex(library, index);
        songs = insertSongFront(songs, song->name, song->artist);
        library = deleteSong(library, song->artist, song->name);
        size--;
    }
    printSongList(songs);
    freeSongList(songs);
    freeSongList(library);
}

struct song_node *combineLibrary(struct song_node **front)
{
    struct song_node *songs = NULL;
    for (int i = 0; i < 27; i++)
    {
        struct song_node *head = front[i];
        while (head != NULL)
        {
            songs = insertSongFront(songs, head->name, head->artist);
            head = head->next;
        }
    }
    return songs;
}

struct song_node **clear_library(struct song_node **front)
{
    for (int i = 0; i < 27; i++)
    {
        front[i] = freeSongList(front[i]);
    }
    return front;
}
