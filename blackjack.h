//declare functions here

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUMOFCARDS 52

typedef struct Card{
    //value of each card
    int rank;
    int suit;
}Card;

typedef struct Hand{
    //Array of cards that can be in a hand
    Card cards[50];
    //number of cards in player's hand
    int n_cards;
}Hand;

typedef struct Player{
    //Assigns a hand to a player
    Hand hand;
    //name of the player
    char name[256];
}Player;

typedef struct Deck{
    //For the amount of cards in the deck
    Card cards[NUMOFCARDS];
    int num_cards;// = NUMOFCARDS;
    //To get the top card of the deck
    int top_card_num;
    Card top_card;
}Deck;

typedef struct Game{
    Player players;
    Player dealer;
    int num_players;
}Game;

Deck* deckInit(Deck*);
Deck* populateDeck(Deck*);
Deck* shuffleDeck(Deck*);
Game* gameInit(Game*);
//Game* createPlayers(Game*, int);
Game* dealCards(Game*, Deck*);
void deleteDeck(Deck*);
void deleteGame(Game*);
//void deletePlayers(Game*);
void addCardPlayer(Game*, Deck* /* , int */);
void addCardDealer(Game*, Deck*);
void displaytwocards(int rankone, int ranktwo, int suitone, int suittwo);
void displayonecard(int rankone, int suitone);
void show_rules();
int bet(int chips);
int hitstand();
// void addCardPlayer(Game* game, Deck *deck);
// void dealersinglecard(Game* game, Deck *deck);
int calculatepoints(int cardval);
int checkpoints(int points);
int dealervsuser(int userpoints, int dealerpoints);
#endif
