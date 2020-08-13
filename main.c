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
    // deck = deckInit(deck);
    // /* for(int i=0; i<NUMOFCARDS; i++){
    //     printf("card is %d\n", deck->cards[i].rank);
    // }*/
    // deck = populateDeck(deck);
    // // for(int i=0; i<NUMOFCARDS; i++){
    // //     printf("card is %d, suit is %d\n", deck->cards[i].rank, deck->cards[i].suit);
    // // }
    // deck = shuffleDeck(deck);
    // /* for(int i=0; i<NUMOFCARDS; i++){
    //     printf("card is %d\n", deck->cards[i].rank);
    // } */
    // //shuffling twice here
    // deck = shuffleDeck(deck);
    while(chips != 0 || again != 0){
    deck = setup_deck(deck);
    // printf("deck card at top is %d\n", deck->top_card.rank);
    Game *game = setup_game(game);
    chips = gamesetup(game, deck, chips);
    int x;
    int check = 0;
      if (chips != 0){
    while (check == 0){
      printf("\nPress 1 to continue with your current chips or press 2 to quit\n");
      scanf("%d", &x);
      if (x == 1){
        again = 1;
        check = 1;
      }
      else if (x == 2){
        again = 0;
        check =1;
      }
      else {
        check = 0;
        printf("Wrong input, please type in the the correct choice. \n");
      }
    }
  }
  int check2 = 0;
  if (chips == 0){
    while (check2 == 0){
      printf("It seems like you ran out of chips, Press 1 to play again or press 2 to quit :");
      scanf("%d", &x);
      if (x == 1){
        chips = 1000;
        again = 1;
        check2 =1;
      }
      else if (x == 2){
        chips = 0;
        again = 0;
        check2= 1;
      }
      else {
        check2 = 0;
        printf("Wrong input, please type in the the correct choice. \n");
      }
    }
  }

}
    //game = createPlayers(game, 1);
    // while(again == 1){
    //   system("clear");
    //     int playerBank = 1000;
    //     //creates 1 player to start the game with
    //     //game = createPlayers(game, 1);
    //     deck = shuffleDeck(deck);
    //     // printf("dealing cards\n");
    //     game = dealCards(game, deck);
    //     // printf("dealCards() is done\n");
    //     show_rules();
    //     printf("\n\n");
    //     int playerbet = bet(playerBank);
    //     // int playercardcount = 0;
    //     // printf("Player 1's cards are %d and %d\n", game->players.hand.cards[0].rank, game->players.hand.cards[1].rank);
    //     int userpoints =0;
    //     int dealerpoints = 0;
    //     printf("Player 1's card are : \n");
    //     displaytwocards(game->players.hand.cards[0].rank, game->players.hand.cards[1].rank, game->players.hand.cards[0].suit, game->players.hand.cards[1].suit);
    //     userpoints = calculatepoints(game->players.hand.cards[0].rank) + calculatepoints(game->players.hand.cards[1].rank);
    //     printf("You have %d points in total.\n", userpoints);
    //     printf("Dealer's first card is: \n");
    //     displayonecard(game->dealer.hand.cards[0].rank, game->dealer.hand.cards[1].suit);
    //     int i = hitstand();
    //     if (i == 1){
    //       printf("User's third card is :\n");
    //       addCardPlayer(game,deck);
    //       displayonecard(game->players.hand.cards[2].rank, game->players.hand.cards[2].suit);
    //       userpoints = userpoints + calculatepoints(game->players.hand.cards[2].rank);
    //       printf("Current points for user %d\n", userpoints);
    //       int check = checkpoints(userpoints);
    //       if (check == 1){
    //         printf("You went above 21, you are busted\n");
    //         playerBank = playerBank - playerbet;
    //         again = 0;
    //         break;
    //       }
    //       int k = hitstand();
    //       if (k == 1){
    //         printf("User's fourth card is :\n");
    //         addCardPlayer(game, deck);
    //         displayonecard(game->players.hand.cards[3].rank, game->players.hand.cards[3].suit);
    //         userpoints = userpoints + calculatepoints(game->players.hand.cards[3].rank);
    //         printf("Current points for user %d\n", userpoints);
    //         check = checkpoints(userpoints);
    //         if (check == 1){
    //           printf("You went above 21, you are busted\n");
    //           playerBank = playerBank - playerbet * 2;
    //           printf("Your new balance is %d chips.", playerBank);
    //           printf("Would you like to play again? (Enter 1 for yes, 0 for no): ");
    //           scanf("%d", &again);
    //           while(again > 1 || again < 0){
    //             printf("Invalid input. Would you like to play again? (Enter 1 for yes, 0 for no): ");
    //             scanf("%d", &again);
    //           }
    //           break;
    //         }
    //       }
    //
    //     }
    //     if (i == 2){
    //       printf("Dealer's second card is : ");
    //       displayonecard(game->dealer.hand.cards[1].rank, game->dealer.hand.cards[1].suit);
    //       dealerpoints = calculatepoints(game->dealer.hand.cards[0].rank) + calculatepoints(game->dealer.hand.cards[1].rank);
    //       printf("Dealer points %d\n", dealerpoints);
    //       int vspoints = dealervsuser(userpoints, dealerpoints);
    //       if (vspoints == 1){
    //         addCardDealer(game, deck);
    //         printf("Dealer's third card is : ");
    //         displayonecard(game->dealer.hand.cards[2].rank, game->dealer.hand.cards[2].suit);
    //         dealerpoints = dealerpoints + calculatepoints(game->dealer.hand.cards[2].rank);
    //         int check = checkpoints(dealerpoints);
    //         if (check == 1){
    //           printf("Dealer went above 21, you Won\n");
    //           playerBank = playerBank + playerbet * 2;
    //           printf("Your new balance is %d chips.", playerBank);
    //           printf("Would you like to play again? (Enter 1 for yes, 0 for no): ");
    //           scanf("%d", &again);
    //           while(again > 1 || again < 0){
    //             printf("Invalid input. Would you like to play again? (Enter 1 for yes, 0 for no): ");
    //             scanf("%d", &again);
    //           }
    //           break;
    //         }
    //         vspoints = dealervsuser(userpoints, dealerpoints);
    //         if (vspoints == 0){
    //           printf("Dealer won!\n");
    //           playerBank = playerBank + playerbet * 2;
    //           printf("Your new balance is %d chips.", playerBank);
    //         }
    //         else if(vspoints == 1){
    //           printf("You win! \n");
    //           playerBank = playerBank - playerbet * 2;
    //           printf("Your new balance is %d chips.", playerBank);
    //         }
    //         else
    //         {
    //           printf("Draw. \n");
    //           playerBank = playerBank + playerbet;
    //         }
    //
    //       }
    //     }
    //     if(chips < 0){
    //         printf("You have gone bankrupt!");
    //         again = 0;
    //         //keep in mind this will go right to delete, which is what
    //         //it should do. This will end the program though.
    //     }
    //     else{
    //         printf("Would you like to play again? (Enter 1 for yes, 0 for no): ");
    //         scanf("%d", &again);
    //         while(again > 1 || again < 0){
    //             printf("Invalid input. Would you like to play again? (Enter 1 for yes, 0 for no): ");
    //             scanf("%d", &again);
    //          }
    //     deck->top_card_num = 0;
    //     deck->top_card = deck->cards[deck->top_card_num];
    //     //deletePlayers(game);
    //     }
    // }
    /*
    *
    *
    * To add a new card to a player, pass the game object, deck
    * object, and the number 1 because we will only have
    * one player in our game
    *
    *
    *
    */
    // printf("deleting deck\n");
    // deleteDeck(deck);
    // printf("deleting players\n");
    // //deletePlayers(game);
    // printf("deleting game\n");
    // deleteGame(game);
    return 0;
}
