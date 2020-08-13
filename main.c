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
  int playerBank = 1000;
  Deck *deck;
  deck = deckInit(deck);
  deck = populateDeck(deck);
  deck = shuffleDeck(deck);
  deck = shuffleDeck(deck);
  Game *game;
  game = gameInit(game);

  while(again == 1){
    system("clear");
    deck = shuffleDeck(deck);
    game = dealCards(game, deck);
    show_rules();
    printf("\n\n");
    int playerbet = bet(playerBank);
    int userpoints = 0;
    int dealerpoints = 0;

    printf("PLAYER 1 TURN: \n");
    displaytwocards(game->players.hand.cards[0].rank, game->players.hand.cards[1].rank, game->players.hand.cards[0].suit, game->players.hand.cards[1].suit);
    userpoints = calculatepoints(game->players.hand.cards[0].rank) + calculatepoints(game->players.hand.cards[1].rank);
    printf("You have %d points in total. \n", userpoints);

    printf("DEALER TURN: \n");
    displayonecard(game->dealer.hand.cards[0].rank, game->dealer.hand.cards[1].suit);
        
    int i = hitstand();
    if (i == 1){
      printf("Your third card is: \n");
      addCardPlayer(game,deck);
      displayonecard(game->players.hand.cards[2].rank, game->players.hand.cards[2].suit);
      userpoints = userpoints + calculatepoints(game->players.hand.cards[2].rank);
      printf("You currently have %d points. \n", userpoints);
      int check = checkpoints(userpoints);
      if(check==1)
        check = 2;
      playerBank = outcome(check, 50, playerBank, playerbet);
      int k = hitstand();
        if (k == 1){
          printf("Your fourth card is :\n");
          addCardPlayer(game, deck);
          displayonecard(game->players.hand.cards[3].rank, game->players.hand.cards[3].suit);
          userpoints = userpoints + calculatepoints(game->players.hand.cards[3].rank);
          printf("You currently have %d points \n", userpoints);
          int check = checkpoints(userpoints);
          if(check==1)
            check = 2;
          playerBank = outcome(check, 0, playerBank, playerbet);
        }
        else{
          printf("Dealer's second card is: \n");
          displayonecard(game->dealer.hand.cards[1].rank, game->dealer.hand.cards[1].suit);
          dealerpoints = calculatepoints(game->dealer.hand.cards[0].rank) + calculatepoints(game->dealer.hand.cards[1].rank);
          printf("The dealer has %d points. \n", dealerpoints);
          int vspoints = dealervsuser(userpoints, dealerpoints);
          if (vspoints == 1){
            addCardDealer(game, deck);
            printf("Dealer's third card is : ");
            displayonecard(game->dealer.hand.cards[2].rank, game->dealer.hand.cards[2].suit);
            dealerpoints = dealerpoints + calculatepoints(game->dealer.hand.cards[2].rank);
            int check = checkpoints(dealerpoints);
            vspoints = dealervsuser(userpoints, dealerpoints);
            playerBank = outcome(check, vspoints, playerBank, playerbet);
          }
          else{
          int check = checkpoints(dealerpoints);
          playerBank = outcome(check, vspoints, playerBank, playerbet);
          }
        }
      }
      else{
          printf("Dealer's second card is: \n");
          displayonecard(game->dealer.hand.cards[1].rank, game->dealer.hand.cards[1].suit);
          dealerpoints = calculatepoints(game->dealer.hand.cards[0].rank) + calculatepoints(game->dealer.hand.cards[1].rank);
          printf("The dealer has %d points. \n", dealerpoints);
          int vspoints = dealervsuser(userpoints, dealerpoints);
          if (vspoints == 1){
            addCardDealer(game, deck);
            printf("Dealer's third card is : ");
            displayonecard(game->dealer.hand.cards[2].rank, game->dealer.hand.cards[2].suit);
            dealerpoints = dealerpoints + calculatepoints(game->dealer.hand.cards[2].rank);
            int check = checkpoints(dealerpoints);
            vspoints = dealervsuser(userpoints, dealerpoints);
            playerBank = outcome(check, vspoints, playerBank, playerbet);
          }
      }
    if(playerBank < 0){
      printf("You have gone bankrupt! Program will now terminate.");
      again = 0;
    }
    else{
      again = playagain();
      deck->top_card_num = 0;
      deck->top_card = deck->cards[deck->top_card_num];
    }
  }
  return 0;
}
