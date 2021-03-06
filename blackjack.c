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

int bet(int chips){
    int x;
    printf("How much would you like to bet? Your currently have %d chips \n", chips);
    scanf("%d", &x);
    if(x > chips){
        printf("Invalid amount!");
        int invalid = 1;
        while(invalid == 1){
          printf("How many chips would you like to bet? ");
          scanf("%d", &x);
          if(x <= chips)
                invalid = 0;
        }
    }
    else if (x == chips){
        int con = 0;
        printf("These are all your chips! Are you sure? (Enter 0 to continue or any other number to change the amount)");
        scanf("%d", &con);
        if(con != 0){
            int invalid = 1;
            while(invalid == 1){
                printf("How many chips would you like to bet? ");
                scanf("%d", &x);
                if(x < chips)
                    invalid = 0;
            }
        }

    }
    return x;
}

int hitstand(){
  int check = 0;
  while (check == 0){
    printf("Would you like to Hit or Stand? \n");
    printf("Press H for HIT and press S for Stand\n");
    char ch1;
    scanf(" %c", &ch1);
    if (ch1 == 'H'){
      check = 1;
      return 1;
    }
    else if (ch1 == 'S'){
      check = 1;
      return 2;
    }
    else {
      check = 0;
      printf("Wrong input, please type in the the correct choice. \n");
    }
  }
  return 2;
}

int calculatepoints(int cardval){
  if (cardval == 11 || cardval == 12 || cardval == 13){
    return 10;
  }
  else if (cardval == 1 ){
    int invalid;
    printf("It seems like you have an Ace, would you like it to count as the value 1 or 11? \n");
    int x = 0;
    scanf("%d", &x);
    if (x == 1 || x == 11){
      return x;
    }
    else{
      invalid = 1;
      while(invalid == 1){
          printf("Invalid input. It seems like you have an Ace, would you like it to count as the value 1 or 11? \n");
          scanf("%d", &x);
          if (x == 1 || x == 11){
            invalid = 0;
            return x;
          }
      }
    }
  }
  return cardval;
}

int checkpoints(int points){
  if (points > 21){
    return 1;
  }
  else {
    return 0;
  }
}

int dealervsuser(int userpoints, int dealerpoints){
  if (userpoints > dealerpoints){
    return 1;
  }
  else if (userpoints < dealerpoints){
    return 0;
  }
  else{
    return 3;
  }
}


Deck* setup_deck(Deck *deck){
  // Deck *deck;
  deck = deckInit(deck);
  deck = populateDeck(deck);
  deck = shuffleDeck(deck);
  deck = shuffleDeck(deck);
  return deck;
}

Game* setup_game(Game* game){
  // Game *game;
  game = gameInit(game);
  return game;
}


int gamesetup(Game* game, Deck* deck, int playerBank){
  // int again = 1;
  int userpoints =0;
  int dealerpoints = 0;
  int playerbet = bet(playerBank);
  system("clear");
  deck = shuffleDeck(deck);
  game = dealCards(game, deck);
  show_rules();
  printf("\n\n");
  printf("Player 1's card are : \n");
  displaytwocards(game->players.hand.cards[0].rank, game->players.hand.cards[1].rank, game->players.hand.cards[0].suit, game->players.hand.cards[1].suit);
  userpoints = calculatepoints(game->players.hand.cards[0].rank) + calculatepoints(game->players.hand.cards[1].rank);
  printf("You have %d points in total.\n", userpoints);
  printf("Dealer's first card is: \n");
  displayonecard(game->dealer.hand.cards[0].rank, game->dealer.hand.cards[1].suit);
  int i = hitstand();
  if (i == 1){
    printf("User's third card is :\n");
    addCardPlayer(game,deck);
    displayonecard(game->players.hand.cards[2].rank, game->players.hand.cards[2].suit);
    userpoints = userpoints + calculatepoints(game->players.hand.cards[2].rank);
    printf("Current points for user %d\n", userpoints);
    int check = checkpoints(userpoints);
    if (check == 1){
      printf("You went above 21, you are busted\n");
      playerBank = playerBank - playerbet;
      printf("Your new balance is %d chips.", playerBank);
      return playerBank;
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
        playerBank = playerBank - playerbet * 2;
        printf("Your new balance is %d chips.", playerBank);
        return playerBank;
      }
    }
    if (k == 2){
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
        printf("Dealer points %d\n", dealerpoints);
        int check = checkpoints(dealerpoints);
        if (check == 1){
          printf("Dealer went above 21, you Won\n");
          printf("Dealer points %d\n", dealerpoints);
          playerBank = playerBank + playerbet * 2;
          printf("Your new balance is %d chips.", playerBank);
          return playerBank;
        }
        vspoints = dealervsuser(userpoints, dealerpoints);
        if (vspoints == 0){

          printf("Dealer won!\n");
          printf("Dealer points %d\n", dealerpoints);
          playerBank = playerBank - playerbet;
          printf("Your new balance is %d chips.", playerBank);
          return playerBank;
        }
        else if(vspoints == 1){
          printf("Dealer points %d\n", dealerpoints);
          printf("You win! \n");
          playerBank = playerBank + playerbet * 2;
          printf("Your new balance is %d chips.", playerBank);
          return playerBank;
        }
        else
        {
          printf("Draw. \n");
          playerBank = playerBank + playerbet;
          printf("Your new balance is %d chips.", playerBank);
          return playerBank;
        }

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
      int check = checkpoints(dealerpoints);
      if (check == 1){
        printf("Dealer went above 21, you Won\n");
        playerBank = playerBank + playerbet * 2;
        return playerBank;
        printf("Your new balance is %d chips.", playerBank);
      }
      vspoints = dealervsuser(userpoints, dealerpoints);
      if (vspoints == 0){
        printf("Dealer won!\n");
        playerBank = playerBank - playerbet;
        printf("Your new balance is %d chips.", playerBank);
      }
      else if(vspoints == 1){
        printf("You win! \n");
        playerBank = playerBank + playerbet * 2;
        printf("Your new balance is %d chips.", playerBank);
        return playerBank;
      }
      else
      {
        printf("Draw. \n");
        playerBank = playerBank + playerbet;
        return playerBank;
      }

    }
  }
}
