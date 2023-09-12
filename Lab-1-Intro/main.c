#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "library.h"

int main()
{

  printf("________________________\n");

  printf("\nTesting insertSong starting null\n");
  struct song_node *test = NULL;
  printf("\nAdding Without Me by Halsey\n");
  test = insertSong(test, "Without Me", "Halsey");
  printSongList(test);
  test = freeSongList(test);
  printf("________________________\n");

  printf("\nTesting insertSongFront starting null\n");
  printf("\nAdding Without Me by Halsey\n");
  // struct song_node *song1 = makeSong("Without Me", "Halsey");
  // struct song_node *head = song1;
  struct song_node *head = NULL;
  head = insertSongFront(head, "Without Me", "Halsey");
  printSongList(head);
  printf("________________________\n");

  printf("\nTesting insertSong to middle and end\n");
  struct song_node *song = NULL;
  printf("\nAdding Lovely by Billie Ellish to Front\n");
  head = insertSongFront(head, "Lovely", "Billie Ellish");
  printSongList(head);
  printf("\nAdding Perfect by Ed Sheeran\n");
  head = insertSong(head, "Perfect", "Ed Sheeran");
  printSongList(head);
  printf("\nAdding Shape of You by Ed Sheeran\n");
  head = insertSong(head, "Shape of You", "Ed Sheeran");
  printSongList(head);
  printf("________________________\n");

  printf("\nTesting Search for song given artist and song name\n");
  printf("\nSearching for Lovely by Billie Ellish\n");
  song = getSong(head, "Lovely", "Billie Ellish");
  printSongList(song);
  freeSongList(song);
  printf("\nSearching for Shape of You by Ed Sheeran\n");
  song = getSong(head, "Shape of You", "Ed Sheeran");
  printSongList(song);
  freeSongList(song);
  printf("\nSearching for Without Me by Halsey\n");
  song = getSong(head, "Without Me", "Halsey");
  printSongList(song);
  freeSongList(song);
  printf("\nSearching for A by A\n");
  song = getSong(head, "A", "A");
  printSongList(song);
  freeSongList(song);
  printf("________________________\n");

  printf("\nTesting Search for first song given artist\n");
  printf("\nSearching for Billie Ellish\n");
  struct song_node *songs = getArtistSong(head, "Billie Ellish");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for Ed Sheeran\n");
  songs = getArtistSong(head, "Ed Sheeran");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for by Halsey\n");
  songs = getArtistSong(head, "Halsey");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for A by A\n");
  songs = getArtistSong(head, "A");
  printSongList(songs);
  freeSongList(songs);
  printf("________________________\n");

  printf("\nTesting random song generation\n");
  printf("\nTrial 1\n");
  struct song_node *random = randomSong(head);
  printf("{%s, %s}\n", random->name, random->artist);
  printf("\nTrial 2\n");
  random = randomSong(head);
  printf("{%s, %s}\n", random->name, random->artist);
  printf("\nTrial 3\n");
  random = randomSong(head);
  printf("{%s, %s}\n", random->name, random->artist);
  printf("\nTrial 4\n");
  random = randomSong(head);
  printf("{%s, %s}\n", random->name, random->artist);
  printf("________________________\n");

  printf("\nTesting Delete Song from front, middle, end\n");
  printf("\nOriginal song list\n");
  printSongList(head);
  printf("\nDelete Lovely by Billie Ellish\n");
  head = deleteSong(head, "Billie Ellish", "Lovely");
  printSongList(head);
  printf("\nDelete Shape of You by Ed Sheeran\n");
  head = deleteSong(head, "Ed Sheeran", "Shape of You");
  printSongList(head);
  printf("\nDelete Without Me by Halsey\n");
  head = deleteSong(head, "Halsey", "Without Me");
  printSongList(head);
  printf("________________________\n");

  printf("\nTesting Free Song List\n");
  head = freeSongList(head);
  printSongList(head);
  printf("________________________________________________\n");
  printf("________________________________________________\n");

  printf("\nTesting Print Library\n");
  struct song_node **libraryHead = makeSongLibrary();
  printLibrary(libraryHead);
  printf("________________________________________________\n");

  printf("\nTesting insertFront\n");
  printf("\nAdding Heat Waves by Glass Animals to Front\n");
  libraryHead = insertFront(libraryHead, "Heat Waves", "Glass Animals");
  printLibrary(libraryHead);
  printf("________________________________________________\n");

  printf("\nTesting insert\n");
  printf("\nAdding The Other Side of Paradise by Glass Animals\n");
  libraryHead = insert(libraryHead, "The Other Side of Paradise", "Glass Animals");
  printLibrary(libraryHead);
  printf("\nAdding Take a Slice by Glass Animals\n");
  libraryHead = insert(libraryHead, "Take a Slice", "Glass Animals");
  printLibrary(libraryHead);
  printf("\nAdding Alone by Alan Walker\n");
  libraryHead = insert(libraryHead, "Alone", "Alan Walker");
  printLibrary(libraryHead);
  printf("\nAdding One Call Away by Charlie Puth\n");
  libraryHead = insert(libraryHead, "One Call Away", "Charlie Puth");
  printLibrary(libraryHead);
  printf("\nAdding Faded by Alan Walker\n");
  libraryHead = insert(libraryHead, "Faded", "Alan Walker");
  printLibrary(libraryHead);
  printf("________________________________________________\n");

  printf("\nTesting song search given artist and song name\n");
  printf("\nSearching for Heat Waves by Glass Animals\n");
  songs = search(libraryHead, "Heat Waves", "Glass Animals");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for The Other Side of Paradise by Glass Animals\n");
  songs = search(libraryHead, "The Other Side of Paradise", "Glass Animals");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for Take a Slice by Glass Animals\n");
  songs = search(libraryHead, "Take a Slice", "Glass Animals");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for One Call Away by Charlie Puth\n");
  songs = search(libraryHead, "One Call Away", "Charlie Puth");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for A by A\n");
  songs = search(libraryHead, "A", "A");
  printSongList(songs);
  freeSongList(songs);
  printf("________________________________________________\n");

  printf("\nTesting search all songs given artist\n");
  printf("\nSearching for Glass Animals\n");
  songs = searchArtist(libraryHead, "Glass Animals");
  printSongList(songs);
  freeSongList(songs);
  printf("\nSearching for A\n");
  songs = searchArtist(libraryHead, "A");
  printSongList(songs);
  freeSongList(songs);
  printf("________________________________________________\n");

  printf("\nPrinting songs with artists that start with G\n");
  printCharacterList(libraryHead, 'G');
  printf("\nPrinting songs with artists that start with A\n");
  printCharacterList(libraryHead, 'A');
  printf("\nPrinting songs with artists that start with T\n");
  printCharacterList(libraryHead, 'T');
  printf("________________________________________________\n");

  printf("\nPrinting songs that start with G\n");
  printSameCharacterSongs(libraryHead, 'G');
  printf("\nPrinting songs that start with A\n");
  printSameCharacterSongs(libraryHead, 'A');
  printf("\nPrinting songs that start with T\n");
  printSameCharacterSongs(libraryHead, 'T');
  printf("________________________________________________\n");

  printf("\nPrinting songs by Glass Animals\n");
  printArtistSongs(libraryHead, "Glass Animals");
  printf("\nPrinting songs by Alan Walker\n");
  printArtistSongs(libraryHead, "Alan Walker");
  printf("\nPrinting songs by A\n");
  printArtistSongs(libraryHead, "A");
  printf("________________________________________________\n");

  printf("\nTesting Shuffle of different list lengths with no duplicates\n");
  printf("\nList of length 1\n");
  shuffle(libraryHead, 1);
  printf("\nList of length 2\n");
  shuffle(libraryHead, 2);
  printf("\nList of length 3\n");
  shuffle(libraryHead, 3);
  printf("\nList of length 4\n");
  shuffle(libraryHead, 4);
  printf("\nList of length 5\n");
  shuffle(libraryHead, 5);
  printf("\nList of length 6\n");
  shuffle(libraryHead, 6);
  printf("\nList of length 7\n");
  shuffle(libraryHead, 7);
  printf("________________________________________________\n");

  printf("\nDeleting Heat Waves by Glass Animals\n");
  printf("\nOriginal song library\n");
  printLibrary(libraryHead);
  printf("\nDeleting Heat Waves by Glass Animals\n");
  delete (libraryHead, "Heat Waves", "Glass Animals");
  printLibrary(libraryHead);
  printf("\nDeleting The Other Side of Paradise by Glass Animals\n");
  delete (libraryHead, "The Other Side of Paradise", "Glass Animals");
  printLibrary(libraryHead);
  printf("\nDeleting Take a Slice by Glass Animals\n");
  delete (libraryHead, "Take a Slice", "Glass Animals");
  printLibrary(libraryHead);
  printf("________________________________________________\n");

  printf("\nTesting Free Library\n");
  libraryHead = clear_library(libraryHead);
  printLibrary(libraryHead);
  clear_library(libraryHead);
  printf("________________________________________________\n");
  return 0;
}
