/*********************************************
Welcome to our program: Blackjack Simulator
You will play against the computer for as many rounds as you would like
Your "chips" will indicate how well you are doing. 
You begin with 1000 chips. 
If you run out of chips before ending the program, you will go bankrupt.
Enjoy!

Coded by Carlos Manuel Beleno Santos, Akshat Lunia, Samantha Rodarte and Hamza Shahzor Swati
CS 261 FINAL
*********************************************/

#include "blackjack.h"
#include <stdio.h>

int main(){
    int again = 1;
    int chips = 1000;
    Deck *deck;
    deck = deckInit(deck);
    deck = populateDeck(deck);
    deck = shuffleDeck(deck);
    //shuffling twice here
    deck = shuffleDeck(deck);
    printf("deck card at top is %d\n", deck->top_card.rank);
    Game *game;
    game = gameInit(game);
    game = createPlayers(game, 1);
    while(again == 1){
        deck = shuffleDeck(deck);
        if(chips < 0){
            printf("You have gone bankrupt!");
            again = 0;
        }
        else{
        printf("Would you like to play again? (Enter 1 for yes, 0 for no): ");
        scanf("%d", &again); 
        }
    }
    deleteDeck(deck);
    deletePlayers(game);
    deleteGame(game);
    return 0;
}
