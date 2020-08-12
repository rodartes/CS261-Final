#include "./blackjack.h"

//declare structs here

//define functions here

//This will set all the values in the deck in acending order

// 1 = HEARTS
// 2 = SPADES
//  3 = CLUBS
// 4 = Diamond

Deck* deckInit(Deck *deck){
    deck = (Deck*)malloc(sizeof(Deck*));
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
    game = (Game*)malloc(sizeof(Game));
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
    printf("Second card is %d %s\n", rankone, suits[0]);
  }
  if (suittwo == 2){
    printf("Second card is %d %s\n", rankone, suits[1]);
  }
  if (suittwo == 3){
    printf("Second card is %d %s\n", rankone, suits[2]);
  }
  if (suittwo == 4){
    printf("Second card is %d %s\n", rankone, suits[3]);
  }

}
void displayonecard(int rankone, int suitone){
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
