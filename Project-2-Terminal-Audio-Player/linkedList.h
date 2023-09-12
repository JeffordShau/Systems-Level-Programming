#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct song
{
    char name[100];
    char artist[100];
    struct song *next;
    char path[500];
};
struct song *createSong(char *name, char *artist, char* path);
void printSong(struct song *node);
struct song *insertFront(struct song *linkedList, char *name, char *artist, char* path);
struct song *insertOrder(struct song *linkedList, char *name, char *artist, char* path);
void printList(struct song *linkedList);
struct song *findNode(struct song *linkedList, char *name, char *artist);
struct song *findSong(struct song *linkedList, char *artist);
struct song *returnRandomPointer(struct song *linkedList);
struct song *removeSong(struct song *linkedList, char *name, char *artist);
struct song *freeList(struct song *linkedList);
char *lowercaseString(char *string);
struct song *compareSongs(struct song *a, struct song *b);
struct song *fullSearch(struct song *linkedList, char *name, char *artist);
struct song *artistSearch(struct song *linkedList, char *artist);
struct song *randomSong(struct song *linkedList);
#endif
