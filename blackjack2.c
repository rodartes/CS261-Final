#include "./blackjack.h"

//declare structs here

//define functions here

//This will set all the values in the deck in acending order

// 1 = HEARTS
// 2 = SPADES
// 3 = CLUBS
// 4 = Diamond

Deck* deckInit(Deck *deck){
    deck = (Deck*)malloc(sizeof(struct Deck));
    if(deck==NULL){
        printf("Error allocating memory\n");
    }
    return deck;
}

Deck* populateDeck(Deck *deck){
    int i=0;
    for(int suit=1; suit<5; suit++){
        for(int rank=1; rank<14; rank++){
            deck->cards[i].rank = rank;
            deck->cards[i].suit = suit;
            i++;
        }
    }
    deck->num_cards = NUMOFCARDS;
    return deck;
}

Deck* shuffleDeck(Deck *deck){
    Card temp;
    time_t t;
    srand((unsigned) time(&t));
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
    return deck;
}

Game* gameInit(Game* game){
    game = (Game*)malloc(sizeof(struct Game));
    if(game == NULL){
        printf("Error allocating memory for game..\n");
    }
    game->players.hand.n_cards = 0;
    game->dealer.hand.n_cards = 0;
    return game;
}
/* Game* createPlayers(Game* game, int num_players){
    game->num_players = num_players;
    game->players = (Player*)malloc(sizeof(Player) * game->num_players);
    return game;
} */

Game* dealCards(Game* game, Deck *deck){
    game->dealer.hand.n_cards = 0;
    game->players.hand.n_cards = 0;
    for(int j=0; j<2; j++){
        game->players.hand.cards[j] = deck->top_card;
        game->players.hand.n_cards++;
        deck->top_card_num++;
        deck->top_card = deck->cards[deck->top_card_num];
    }
    for(int j=0; j<2; j++){
        game->dealer.hand.cards[j] = deck->top_card;
        game->dealer.hand.n_cards++;
        deck->top_card_num++;
        deck->top_card = deck->cards[deck->top_card_num];
    }
    return game;
}

void dealusersingle(Game* game, Deck *deck){
  game->players.hand.cards[game->players.hand.n_cards] = deck->top_card;
  game->players.hand.n_cards++;
  deck->top_card_num++;
  deck->top_card = deck->cards[deck->top_card_num];
}

void dealersinglecard(Game* game, Deck *deck){
  game->dealer.hand.cards[game->dealer.hand.n_cards] = deck->top_card;
  game->dealer.hand.n_cards++;
  deck->top_card_num++;
  deck->top_card = deck->cards[deck->top_card_num];
}

void deleteDeck(Deck* deck){
    free(deck);
    deck = 0;
}

/* void deletePlayers(Game* game){
    free(game->players);
    game->players = 0;
} */

void deleteGame(Game* game){
    free(game);
    game = 0;
}

Game* addCardPlayer(Game* game, Deck* deck/*,  int player */){
    game->players.hand.cards[game->players.hand.n_cards] = deck->top_card;
    game->players.hand.n_cards++;
    deck->top_card_num++;
    deck->top_card = deck->cards[deck->top_card_num];
    return game;
}

Game* addCardDealer(Game* game, Deck* deck){
    game->dealer.hand.cards[game->dealer.hand.n_cards] = deck->top_card;
    game->dealer.hand.n_cards++;
    deck->top_card_num++;
    deck->top_card = deck->cards[deck->top_card_num];
    return game;
}

void displaytwocards(int rankone, int ranktwo, int suitone, int suittwo){
  char* suits[4];
  suits[0] = "HEARTS";
  suits[1] = "SPADES";
  suits[2] = "CLUBS";
  suits[3] = "DIAMOND";
  if (suitone == 1){
    printf("First card is %d %s\n", rankone, suits[0]);
  }
  if (suitone == 2){
    printf("First card is %d %s\n", rankone, suits[1]);
  }
  if (suitone == 3){
    printf("First card is %d %s\n", rankone, suits[2]);
  }
  if (suitone == 4){
    printf("First card is %d %s\n", rankone, suits[3]);
  }
  if (suittwo == 1){
    printf("Second card is %d %s\n", ranktwo, suits[0]);
  }
  if (suittwo == 2){
    printf("Second card is %d %s\n", ranktwo, suits[1]);
  }
  if (suittwo == 3){
    printf("Second card is %d %s\n", ranktwo, suits[2]);
  }
  if (suittwo == 4){
    printf("Second card is %d %s\n", ranktwo, suits[3]);
  }

}
void displayonecard(int rankone, int suitone){
  char* suits[4];
  suits[0] = "HEARTS";
  suits[1] = "SPADES";
  suits[2] = "CLUBS";
  suits[3] = "DIAMOND";
  if (suitone == 1){
    printf("Card is %d %s\n", rankone, suits[0]);
  }
  if (suitone == 2){
    printf("Card is %d %s\n", rankone, suits[1]);
  }
  if (suitone == 3){
    printf("Card is %d %s\n", rankone, suits[2]);
  }
  if (suitone == 4){
    printf("Card is %d %s\n", rankone, suits[3]);
  }
}

void show_rules(){
  printf("The goal of blackjack is to beat the dealer's hand without going over 21\n");
  printf("1 Value represents Aces, which are worth 1 or 11, whichever makes a better card\n");
  printf("11 Represents Jack, 12 Represents Queen and 13 represents King\n");
  printf("Each player starts with two cards, one of the dealer's cards is hidden until the end.\n");
  printf("If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.\n");
  printf("Blackjack usually means you win 1.5 the amount of your bet. Depends on the casino.\n");
  printf("You cannot play on two aces after they are split.\n");
  printf("To Hit press H to ask for another card and to Stand press S to hold your chips and end your turn\n");
  printf("You will start with 1000 chips and can play until you have zero chips or press q to end\n");
}

int bet(int chips){
    int x;
    printf("How much would you like to bet? You currently have %d\n chips.", chips);
    scanf("%d", &x);
    if(x > chips){
        printf("Invalid amount!");
        int invalid = 1;
        while(invalid == 1){
          printf("How much would you like to bet?");
          scanf("%d", &x);
          if(x <= chips)
                invalid = 0;
        }
        int i = hitstand();
        if (i == 1){
          printf("User's third card is :\n");
          addCardPlayer(game,deck);
          displayonecard(game->players.hand.cards[2].rank, game->players.hand.cards[2].suit);
          userpoints = userpoints + calculatepoints(game->players.hand.cards[2].rank);
          printf("Current points for user %d\n", userpoints);
          check = checkpoints(userpoints);
          if (check == 1){
            printf("You went above 21, you are busted\n");
            playerBank = playerBank - playerbet;
            again = 0;
            break;
          }
          int k = hitstand();
          if (k == 1){
            printf("User's fourth card is :\n");
            addCardPlayer(game, deck);
            displayonecard(game->players.hand.cards[3].rank, game->players.hand.cards[3].suit);
            userpoints = userpoints + calculatepoints(game->players.hand.cards[3].rank);
            printf("Current points for user %d\n", userpoints);
            check = checkpoints(userpoints);
            if (check == 1){
              printf("You went above 21, you are busted\n");
              playerBank = playerBank - playerbet;
              again = 0;
              break;
            }
          }
        }
        if (i == 2){
          printf("Dealer's second card is : ");
          displayonecard(game->dealer.hand.cards[1].rank, game->dealer.hand.cards[1].suit);
          dealerpoints = calculatepoints(game->dealer.hand.cards[0].rank) + calculatepoints(game->dealer.hand.cards[1].rank);
          printf("Dealer points %d\n", dealerpoints);
          int vspoints = dealervsuser(userpoints, dealerpoints);
          if (vspoints == 1){
            addCardDealer(game, deck);
            printf("Dealer's third card is : ");
            displayonecard(game->dealer.hand.cards[2].rank, game->dealer.hand.cards[2].suit);
            dealerpoints = dealerpoints + calculatepoints(game->dealer.hand.cards[2].rank);
            check = checkpoints(dealerpoints);
            if (check == 1){
              printf("Dealer went above 21, you Won\n");
              playerBank = playerBank + playerbet;
              
              again = 0;
              break;
            }
            vspoints = dealervsuser(userpoints, dealerpoints);
            if (vspoints == 0){
              printf("Dealer won\n");

            }
          }
        }
        if(chips < 0){
            printf("You have gone bankrupt!");
            again = 0;
            //keep in mind this will go right to delete, which is what
            //it should do. This will end the program though.
        }
        else{
        printf("Would you like to play again? (Enter 1 for yes, 0 for no): ");
        scanf("%d", &again);
        deck->top_card_num = 0;
        deck->top_card = deck->cards[deck->top_card_num];
        //deletePlayers(game);
        }
    }
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
