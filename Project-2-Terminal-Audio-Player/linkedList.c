#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedList.h"

struct song* createSong(char* name, char* artist, char* path)
{
    struct song* retVal = calloc(1 , sizeof(struct song));

    strcpy(retVal->name, name);
    strcpy(retVal->artist, artist);
    strcpy(retVal->path, path);

    return retVal;
}

void printSong(struct song* node)
{
  if (node == NULL){
    printf("NULL");
    return;
  }
  printf("{Artist: %s, Song: %s}", node->artist, node->name);
}

struct song* insertFront(struct song *linkedList, char *name, char *artist, char* path)
{
    //inserts new node at the front of the linkedList;
    struct song* retVal = createSong(name, artist, path);
    retVal->next = linkedList;
    return retVal;
}

char *lowercaseString(char *string){
  char *lowString = malloc(100 * sizeof(char));
  strcpy(lowString, string);
  for (int i = 0; lowString[i]; i++){
    lowString[i] = tolower(lowString[i]);
  }
  return lowString;
}

 //returns greater song
struct song* compareSongs(struct song* a, struct song* b){
  char *aArtist = lowercaseString(a->artist);
  char *bArtist = lowercaseString(b->artist);
  char *aName = lowercaseString(a->name);
  char *bName = lowercaseString(b->name);
  int artistComp = strcmp(aArtist, bArtist);
  if (artistComp < 0)return a;
  if (artistComp > 0)return b;
  int songComp = strcmp(aName, bName);
  if (songComp < 0)return a;
  else{
    return b;
  }
}

struct song* insertOrder(struct song *linkedList, char *name, char *artist, char* path){
  struct song *addedSong = createSong(name, artist, path);
  struct song *temp = linkedList;
  if (linkedList == NULL || compareSongs(addedSong, linkedList) == addedSong){
    return insertFront(linkedList,name, artist, path);
  }
  while (linkedList->next){
    if (compareSongs(linkedList->next, addedSong) == addedSong){
      addedSong->next = linkedList->next;
      linkedList->next = addedSong;
      return temp;
    }
    linkedList = linkedList->next;
  }
  linkedList->next = addedSong;
  addedSong->next = NULL;
  return temp;


}

struct song* fullSearch(struct song *linkedList, char *name, char *artist){
  char *listArtist;
  char *listName;
  char *searchArtist = lowercaseString(artist);
  char *searchSong = lowercaseString(name);
  while(linkedList){
    listArtist = lowercaseString(linkedList->artist);
    listName = lowercaseString(linkedList->name);
    if (strcmp(listArtist, searchArtist) == 0 && strcmp(listName, searchSong) == 0){
      return linkedList;
    }
    linkedList = linkedList->next;
  }
  return NULL;
}

struct song* artistSearch(struct song *linkedList, char *artist){
  char *listArtist;
  char *searchArtist = lowercaseString(artist);
  while(linkedList != NULL){
    listArtist = lowercaseString(linkedList->artist);
    if (strcmp(listArtist, searchArtist) == 0){
      return linkedList;
    }
    linkedList = linkedList->next;
  }
  return NULL;
}

struct song* randomSong(struct song* linkedList)
{
  int counter = 0;
  struct song* temp = linkedList;
  while(temp)
  {
    counter++;
    temp = temp->next;
  }
  temp = linkedList; //move temp pointer back to the front to use it again
  int index = rand()%counter;
  int tracker = 0;
  while(tracker < index)
  {
    tracker++;
    temp = temp->next;
  }
  return temp;

}

struct song* removeSong(struct song* linkedList, char* name, char* artist)
{
  struct song *temp = linkedList;
  if(strcmp(lowercaseString(temp->name), lowercaseString(name)) == 0 && strcmp(lowercaseString(temp->artist), lowercaseString(artist)) == 0){
    linkedList = linkedList->next;
    free(temp);
    return linkedList;
  }
  while(temp->next)
  {
    if(strcmp(lowercaseString(temp->next->name), lowercaseString(name)) == 0 && strcmp(lowercaseString(temp->next->artist), lowercaseString(artist)) == 0)
    {
      struct song *holder = temp->next;
      temp->next = temp->next->next;
      free(holder);
      return linkedList;
    }
    temp = temp->next;
  }
  return linkedList;
}

struct song* freeList(struct song* linkedList){
  struct song* temp = linkedList;
  while(1)
  {
    if(linkedList == NULL) return linkedList;
    else{
      temp = linkedList;
      linkedList = temp->next;
      free(temp);
    }
  }
  return NULL;
}

void printList(struct song* linkedList)
{
    while(linkedList)
    {
        printSong(linkedList);
        printf(" --> ");
        linkedList = linkedList->next;
    }
    printf("NULL\n");
}
