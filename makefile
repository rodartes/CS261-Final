CC=gcc
CFLAGS=-Wall -std=c99

all: prog

prog: blackjack.o main.o
	gcc -g -Wall -std=c99 -o prog blackjack2.o main.o
blackjack2.o: blackjack2.c blackjack2.h
	gcc -g -Wall -std=c99 -c blackjack2.c
main.o: main.c blackjack2.h
	gcc -g -Wall -std=c99 -c main.c

clean:
	-rm *.o

cleanall: clean
	-rm prog
