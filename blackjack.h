#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMOFCARDS 52


struct card {
  int value;
  char* suit;
}

struct Deck{
  card *crd;
  struct Deck *next;
}
