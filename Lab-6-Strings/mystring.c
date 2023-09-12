#include <stddef.h> // for null return

int mystrlen( char *s) {
  int counter = 0;
  while (s[counter] != '\0') {
    counter += 1;
  }
  return counter;
}

char * mystrcpy( char *dest, char *source ) {
  int counter = 0;
  while (*source != '\0') {
    dest[counter] = *source;
    counter += 1;
    source += 1;
  }
  return dest;
}

char * mystrncat( char *dest, char *source, int n) {
  int destCounter = sizeof(*dest) - 1;
  for (int i = 0; i < n; i++) {
    dest[destCounter] = source[i];
    destCounter += 1;
  }
  return dest;
}

char * mystrchr( char *s, char c ) {
  while (*s != c && *s != '\0') {
    s += 1; // look at next value in string s
  }
  if (*s == c) {
    return s;
  }
  return NULL;
}

int mystrcmp( char *s1, char *s2 ) {
  while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
    s1 += 1;
    s2 += 1;
  }
  if (*s1 > *s2) {
    return 1;
  }
  else if (*s1 < *s2) {
    return -1;
  }
  else {
    return 0;
  }
}
