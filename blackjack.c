#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blackjack.h"

//Global variable setup for 52 cards

struct cards {
  int value;
  char* suit;
};

struct Deck{
  struct cards card[52];
};

struct BlackJack{
  int total;
  struct cards card;
};

void setup_cards(struct Deck* dealerdeck, char* suits[4]);
void print_cards(struct Deck* dealerdeck);
struct Deck* createDeck();
void shufflecards(struct Deck* dealerdeck);
void swap(struct cards *a, struct cards *b);

void setup_cards(struct Deck* dealerdeck, char* suits[4]){
  int i = 0;
  int counter = 0;
  for (i= 0; i<4; i++){
    int j = 0;
    for (j =1; j<=13; j++){
      dealerdeck->card[counter].suit = suits[i];
      dealerdeck->card[counter].value = j;
      counter++;
    }
  }
}

void print_cards(struct Deck* dealerdeck){
  int i = 0;
  for (i = 0; i<NUMOFCARDS; i++){
    printf("CARD SUIT %s VALUE %d\n", dealerdeck->card[i].suit, dealerdeck->card[i].value);
  }
}

struct Deck* createDeck(){
  struct Deck *dealerdeck = (struct Deck *)malloc(sizeof(struct Deck));
  return dealerdeck;
}

void shufflecards(struct Deck* dealerdeck){
  int i = 0;
  for (i=0; i<NUMOFCARDS; i++){
    int j = 0;
    j = rand() % (53);
    swap(&dealerdeck->card[i], &dealerdeck->card[j]);
  }
}

void swap(struct cards *a, struct cards *b){
  struct cards *tempcard;
  tempcard = b;
  *b=*a;
  *a = *tempcard;
}

int main(){
  struct Deck *dealerdeck;
  dealerdeck=createDeck();
  char* suits[4];
  suits[0] = "HEARTS";
  suits[1] = "SPADES";
  suits[2] = "CLUBS";
  suits[3] = "DIAMOND";
  setup_cards(dealerdeck, suits);
  shufflecards(dealerdeck);
  print_cards(dealerdeck);
  return 0;
}
