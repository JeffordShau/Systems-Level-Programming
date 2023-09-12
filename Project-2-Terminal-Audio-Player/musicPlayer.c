#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>
#include "linkedList.h"
#include "musicLibrary.h"
#include "arrowSelection.h"
#include "musicPlayer.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define KEY 89098734

int getSongDuration(char *path)
{
  Wav wav;
  RIFF_t riff;
  FMT_t fmt;
  Data_t data;
  // copy over the path to song file
  char cwd[1000];
  getcwd(cwd, sizeof(cwd));
  strcat(cwd, "/");
  strcat(cwd, path);

  // get metadata wav file and read into wavHeader struct
  FILE *fp = fopen(cwd, "rb");
  fread(&wav, 1, sizeof(wav), fp);

  riff = wav.riff;
  fmt = wav.fmt;
  data = wav.data;

  float duration = (float)riff.ChunkSize / (float)fmt.ByteRate;
  // formatting for display with 0 padding
  int minutes = (int)duration / 60;
  int seconds = (int)duration % 60;
  // printf("Duration \t%d:%02d\n", minutes, seconds);
  close(fp);
  return duration;
}

void play(struct song *input)
{
  // copy over the path to song file
  char path[1000];
  strcpy(path, input->path);
  int duration;
  duration = getSongDuration(path);
  int minutes = (int)duration / 60;
  int seconds = (int)duration % 60;
  // append path to cwd
  char cwd[1000];
  getcwd(cwd, sizeof(cwd));
  strcat(cwd, "/");
  strcat(cwd, path);

  // init shared memory (will be used in signal handling)
  int *data;
  int shmid;
  shmid = shmget(KEY, sizeof(int), IPC_CREAT | 0640);
  data = shmat(shmid, 0, 0);
  *data = 0;

  int pid = fork();

  if (pid == 0)
  {
    // have the value in the shared memory store the childPID while the music is running
    *data = getpid();

    // play the song
    execlp("paplay", "play", cwd, NULL);
  }
  // Wait for child to finish
  // while pid has not finished, show progress bar

  int pid1 = fork();
  if (pid1 == 0)
  {
    int i = 0;
    while (i < duration && *data != 0)
    {
      // clear color formatting
      printf("\033[0m");
      printf("\rDuration \t%d:%02d\t[", minutes, seconds);

      // // print solid progress bar with colors (red for unplayed, green for played)
      // for (int j = 0; j < i; j++)
      // {
      //   printf("\033[0;32m");
      //   printf("=");
      // }

      // print full width progress bar (unplayed is red, played is green)
      for (int j = 0; j < i; j++)
      {
        printf("\033[0;32m");
        printf("=");
      }
      for (int j = i; j < duration; j++)
      {
        printf("\033[0;31m");
        printf("=");
    }

      printf("\033[0m");
      printf("]  ");

      // print spinning cursor
      if (i % 4 == 0)
      {
        printf("/");
      }
      else if (i % 4 == 1)
      {
        printf("-");
      }
      else if (i % 4 == 2)
      {
        printf("\\");
      }
      else
      {
        printf("|");
      }

      fflush(stdout);
      sleep(1);
      i++;
      seconds--;
      if (seconds < 0)
      {
        seconds = 59;
        minutes--;
      }
    }
    exit(0);
  }
  waitpid(pid, NULL, 0);

  if (*data == 1)
  { // if song ended early via signal handler
    *data = 0;
    printf("\nYou stopped playing %s\n", input->name);
    return;
  }

  // Change the shared memory value to 0 to show that the song has stopped playing
  *data = 0;
  printf("\n%s finished playing.\n", input->name);
  // replace the next line in terminal with blank space
  printf("\r");

  return;
}
