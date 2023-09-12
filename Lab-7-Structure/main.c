#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main() {

  struct cards *deck1 = createHeaps(4);

  printf("Testing array of 4 cards:\n");
  for (int i = 0; i < 4; i++) {
    struct cards *card = createCard();
    deck1[i] = *card;
    print(card);
  }
  printf("NULL\n");

  printf("\nTesting free list\n");
  struct cards *firstIdx = &deck1[0];
  firstIdx = free_list(firstIdx);
  print_list(firstIdx);

  printf("\nTesting print list\n");
  struct cards *firstCard = createCard();
  struct cards *secondCard = createCard();
  struct cards *thirdCard = createCard();
  struct cards *fourthCard = createCard();
  struct cards *head = firstCard;
  firstCard->nextCard = secondCard;
  secondCard->nextCard = thirdCard;
  thirdCard->nextCard = fourthCard;
  print_list(head);

  printf("\nTesting insert front\n");
  printf("Adding card number 7\n");
  head = insert_front(head, 7);
  print_list(head);
  printf("Adding card number 7\n");
  head = insert_front(head, 12);
  print_list(head);
  printf("Adding card number 7\n");
  head = insert_front(head, 17);
  print_list(head);

  printf("\nTesting remove node\n");
  printf("Removing card number 17\n");
  head = remove_node(head, 17);
  print_list(head);
  printf("Removing card number 7\n");
  head = remove_node(head, 7);
  print_list(head);
  printf("Removing card number 38\n");
  head = remove_node(head, 38);
  print_list(head);

  printf("\nTesting free list\n");
  head = free_list(head);
  print_list(head);
  return 0;
}
