#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "directory.h"

void directoryInfo(char *path) {
  struct stat *statBuff = calloc(1, sizeof(struct stat));
  char directories[1000] = "";
  char files[1000] = "";
  int totalBytes = 0;

  DIR *directory = opendir(path);
  if (directory == NULL) {
    printf("%s\n", strerror(errno));
    closedir(directory);
    exit(0);
  }
  struct dirent *entry = readdir(directory);
  while (entry) {
    if (opendir(entry->d_name) == NULL) {
      strcat(files, "\t");
      strcat(files, entry->d_name);
      strcat(files, "\n");
      stat(entry->d_name, statBuff);
      totalBytes += statBuff->st_size;
    }
    else {
      strcat(directories, "\t");
      strcat(directories, entry->d_name);
      strcat(directories, "\n");
    }
    entry = readdir(directory);
  }
  printf("Statistics for directory: %s\n", path);
  printf("Total Directory Size: %d Bytes\n", totalBytes);
  printf("Directories:\n%s\n", directories);
  printf("Files:\n%s", files);
  free(statBuff);
  closedir(directory);
}
