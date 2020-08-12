CC=gcc
CFLAGS=-Wall -std=c99

all: prog

prog: blackjack.o main.o
	gcc -g -Wall -std=c99 -o prog blackjack.o main.o
blackjack.o: blackjack.c blackjack.h
	gcc -g -Wall -std=c99 -c blackjack.c
main.o: main.c blackjack.h
	gcc -g -Wall -std=c99 -c main.c

clean:
	-rm *.o

cleanall: clean
	-rm prog
