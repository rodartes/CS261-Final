#include "./blackjack.h"

//declare structs here

//define functions here

//This will set all the values in the deck in acending order
void populateDeck(Deck *deck){
    int i=0;
    for(int suit=1; suit<5; suit++){
        for(int rank=1; rank<14; rank++){
            deck->cards[i].rank = rank;
            deck->cards[i].suit = suit;
            i++;
        }
    }
    deck->num_cards = NUMOFCARDS;
}

void shuffleDeck(Deck *deck){
    Card temp;
    srand(time(NULL));
    //loops for number of cards and swaps them with temp where
    // temp holds a random card
    for(int i=0; i<deck->num_cards; i++){
        int rand_num = rand()%NUMOFCARDS;
        temp = deck->cards[rand_num];
        deck->cards[rand_num] = deck->cards[i];
        deck->cards[i] = temp;
    }
    deck->top_card_num=0;
    deck->top_card=deck->cards[deck->top_card_num];
}

void createPlayers(Game* game, int num_players){
    game->num_players = num_players;
    game->players = (Player*)malloc(sizeof(Player) * game->num_players);
}

void dealCards(Game* game, Deck *deck){
    for (int i=0; i<game->num_players; i++){
        for(int j=0; j<2; j++){
            game->players[i].hand.cards[j] = deck->top_card;
            deck->top_card_num++;
            deck->top_card = deck->cards[deck->top_card_num];
        }
    }
}
