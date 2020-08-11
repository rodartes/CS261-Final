#include "stdio.h"
#include "blackjack.h"

//reads the first 2 cards to player
void first();
//check if card values equal 21
int bust();
//choose number of chips to bet
int bet();

int bet(int chips){
    int x;
    printf("How much would you like to bet?");
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
    }
    else if(x=chips){
        int con =  0;
        printf("These are all your chips! Are you sure? (Enter 0 to continue or any other number to change the amount)");
        if(con != 0){
            int invalid = 1;
            while(invalid == 1){
                printf("How much would you like to bet?");
                scanf("%d", &x);  
                if(x <= chips)
                    invalid = 0;
            }
        }

    }
    return x;
}

void first(){
    printf("Your cards are...");
    /*int b = bust();
    if(b == 0){
        int p;
        printf("Pull again? (1-yes, 0-no");
        scanf("%d", &p);
    }
    else{
        printf("Bust! Dealer wins!");
    }*/
}

int main(){
    return 0;
}