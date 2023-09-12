#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "helpers.h"
#include "musicPlayer.h"
#include "linkedList.h"
#include "musicLibrary.h"
#include "arrowSelection.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define KEY 89098734

static void sighandler(int signalNum)
{
  if (signalNum == SIGINT)
  {

    // access shared memory
    int *data;
    int shmid;
    shmid = shmget(KEY, sizeof(int), 0);
    data = shmat(shmid, 0, 0);

    if (*data == 0)
    {
      // Song not playing
      // Thank the user and exit the program
      printf("\nThank you for using Lesserafim's music player\n");
      printf("We hope you had a good experience!\n");
      // reset ncurses window
      system("clear");
      endwin();
      exit(0);
    }
    else
    {
      // Song is playing
      // data contains the pid of the process playing the song
      int musicPid = *data;
      *data = 1; // set *data to one to show that song exited due to a SIGINT
      kill(musicPid, SIGTERM);
    }
  }
}

int main()
{

  signal(SIGINT, sighandler);

  struct song *list = NULL; // init linkedList
  struct song **library = createLibrary();

  printf("POPULATING LIBRARY WITH SONGS\n\n");
  list = insertOrder(list, "No Celestial", "LE SSERAFIM", "music/NoCelestialByLeSserafim.wav");
  list = insertOrder(list, "The Hydra", "LE SSERAFIM", "music/TheHydraByLeSserafim.wav");
  list = insertOrder(list, "Sour Grapes", "LE SSERAFIM", "music/SourGrapesByLeSserafim.wav");
  list = insertOrder(list, "Impurities", "LE SSERAFIM", "music/ImpuritiesByLeSserafim.wav");
  list = insertOrder(list, "Way Back Home", "SHAUN", "music/WayBackHomeByShaun.wav");
  list = insertOrder(list, "Hype Boy", "New Jeans", "music/HypeBoyByNewJeans.wav");
  list = insertOrder(list, "After Like", "IVE", "music/AfterLikeByIve.wav");
  list = insertOrder(list, "Raise y_our glass", "HUH YUNJIN", "music/RaiseY_ourGlassByHuhYunjin.wav");
  list = insertOrder(list, "Any song", "Zico", "music/AnySongByZico.wav");
  list = insertOrder(list, "Whistle", "BLACKPINK", "music/WhistleByBlackpink.wav");

  while (list)
  {
    library = addSong(library, list);
    list = list->next;
  }

  // clear screen
  system("clear");
  printf("\n===========================================\n");
  int figlet = fork();
  if (figlet == 0)
  {
    // multi line ascii art that says music library
    // exec figlet for ascii art
    char *args[] = {"figlet", "Music Library", NULL};
    execvp(args[0], args);
  }
  printf("Welcome to the music library by David Chen, Nakib Abedin, and Jefford Shau\n");
  printf("Press the enter key to continue \n");

  char enter[100];
  char **songData;
  fgets(enter, 100, stdin);
  struct song *song = NULL;

  while (1)
  {

    if (strcmp(enter, "\n") == 0)
    {
      songData = parse(musicLibSelection(library), "-");
      song = songSearch(library, songData[0], songData[1]);
    }
    else
    {
      printf("Press the enter key to continue \n");
      fgets(enter, 100, stdin);
      continue;
    }

    printf("===========================================\n");
    printf("Now playing %s by %s\n", song->name, song->artist);

    play(song);

    printf("Press the enter key to play another song. Press x to exit program\n");
    char exitBuff[100];

    while (1)
    {
      fgets(exitBuff, 100, stdin);
      if (strcmp(exitBuff, "\n") == 0)
      {
        break;
      }
      else if (strcmp(exitBuff, "x\n") == 0 || strcmp(exitBuff, "X\n") == 0)
      {
        exit(0);
      }
      else
      {
        printf("Invalid input.\n");
      }
    }
  }

  return 0;
}
