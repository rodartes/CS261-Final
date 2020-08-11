 #include "blackjack.h"

//declare structs here

//define functions here

//This will set all the values in the deck in acending order
void populateDeck(Deck *deck){
    int i=0;
    for(int suit=1; suit<5; suit++){
        for(int rank=1; rank<14; rank++){
            deck->cards[i].rank = set_rank(rank);
            deck->cards[i].suit = set_suit(suit);
            i++;
        }
    }
}

void shuffleDeck(Deck *deck){
    Card temp;
    srand(time(NULL));
    //loops for number of cards and swaps them with temp where
    // temp holds a random card
    for(int i=0; i<deck->num_cards; i++){
        int rand_num = rand()%52;
        temp = deck->cards[rand_num];
        deck->cards[rand_num] = deck->cards[i];
        deck->cards[i] = temp;
    }
}

int set_rank(int rank){
    if(rank >= 1 && rank <= 10){
        return rank;
    }
    
}

int set_suit(int suit){

}
