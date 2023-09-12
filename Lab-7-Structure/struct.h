#ifndef STRUCT_H
#define STRUCT_H
struct cards { char num[7]; char suits[9]; int cardNum; struct cards *nextCard; };
void print(struct cards* card);
struct cards *createHeaps(int size);
struct cards *createCard();
void CardNum(int low, int high, struct cards *card); 
void Num(int low, int high, char *ptr);
void Suit(int low, int high, char *ptr);
void print_list(struct cards *card);
struct cards *insert_front(struct cards *card, int num);
struct cards *free_list(struct cards *head);
struct cards *remove_node(struct cards* front, int num);
#endif
