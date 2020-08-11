//declare functions here

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct Card{
    //value of each card
    int rank;
    int suit;
    //This will let us know who to assign the card to
    string holder;
}Card;

typedef struct Hand{
    //Array of cards that can be in a hand
    Card *cards;
    int n_cards;
}Hand;

typedef struct Player{
    //Assigns a hand to a player
    Hand hand;
    //name of the player
    string name;
}Player;

typedef struct Deck{
    //For the amount of cards in the deck
    Card cards[52];
    int num_cards = 52;
    //To get the top card of the deck
    int top_card = 0;
}Deck;

void populateDeck(Deck*)
void shuffleDeck(Deck*);
int set_rank(int);
int set_suit(int);

#endif
