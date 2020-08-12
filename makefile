CC=gcc
CFLAGS=-Wall -std=c99

all: prog

prog: blackjack2.o game.o main.o
	gcc -g -Wall -std=c99 -o prog blackjack2.o game.o main.o
	
game.o: game.c blackjack.h
	gcc -g -Wall -std=c99 -c game.c

blackjack2.o: blackjack2.c blackjack.h
	gcc -g -Wall -std=c99 -c blackjack2.c

main.o: main.c blackjack.h
	gcc -g -Wall -std=c99 -c main.c

clean:
	-rm *.o

cleanall: clean
	-rm prog
