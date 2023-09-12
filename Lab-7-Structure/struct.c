#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

// Debug
// void print(struct cards *card) {
//   printf("[Card Num: %d, Card: %s, Suit: %s, this: %p, next: %p] -> \n", card->cardNum, card->num, card->suits, card, card->nextCard);
// }

void print(struct cards *card) {
  printf("[Card Num: %d, Card: %s, Suit: %s] -> ", card->cardNum, card->num, card->suits);
}

// multiple cards
struct cards *createHeaps(int size) {
  struct cards *storage = malloc(size * sizeof(struct cards));
  return storage;
}

// create one card and fill it with random values
struct cards *createCard() {
  struct cards *card = malloc(sizeof(struct cards));
  CardNum(1, 52, card);
  Num(0, 13, card->num);
  Suit(0, 3, card->suits);
  return card;
}

// random card numbers in the deck
void CardNum(int low, int high, struct cards *card) {
  int randNum = (rand() % (high - low + 1)) + low - 1;
  card->cardNum = randNum;
}

// random card number
void Num(int low, int high, char *ptr) {
  char randNumArray[14][7] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queens", "King", "Ace"};
  int randNum = (rand() % (high - low + 1)) + low;
  strcpy(ptr, randNumArray[randNum]);
}

// random suit
void Suit(int low, int high, char *ptr) {
  char randSuitsArray[4][9] = {"Diamonds", "Clubs", "Hearts", "Spades"};
  int randNum = (rand() % (high - low + 1)) + low ;
  strcpy(ptr, randSuitsArray[randNum]);
}

// print list
void print_list(struct cards *card) {
  // printf("Card Num: %d", card -> cardNum);
  while (card) {
    // printf("Card Num: %d", card -> cardNum);
    print(card);
    card = card->nextCard;
  }
  printf("NULL\n");
}

// insert card at the front
struct cards *insert_front(struct cards *card, int num) {
  struct cards *newCardMem = malloc(sizeof(struct cards));
  struct cards newCard;
  newCardMem[0] = newCard;
  newCardMem->cardNum = num;
  newCardMem->nextCard = card;
  Num(0, 13, newCardMem->num);
  Suit(0, 3, newCardMem->suits);
  return newCardMem;
}

// remove card with specific card number
struct cards *remove_node(struct cards* front, int num) {
  struct cards *head = front;
  struct cards *temp;
  // target card is first card
  if (front->cardNum == num) {
    temp = front;
    front = front->nextCard;
    free(temp);
    return front;
  }

  // target card is not first
  struct cards *trail = front;
  front = front->nextCard;
  while (front) {
    if (front->cardNum == num) {
      trail->nextCard = front->nextCard;
      free(front);
      return head;
    }
    trail = front;
    front = front->nextCard;
  }
  return head;
}

// free whole list
struct cards *free_list(struct cards *head) {
  struct cards *front = head;
  struct cards *temp;
  while (head) {
    temp = head;
    head = head->nextCard;
    free(temp);
    temp = NULL;
  }
  return head;
}
