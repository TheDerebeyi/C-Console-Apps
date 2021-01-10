//Created by Mert Kahraman.

//Use a struct to define a card as an enumerated member that is its suit value and a short that is its pips value.
//Write a function that randomly shuffles the deck.
//Then deal out 7 card hands and evaluate the probability that a hand has no pair, one pair, two pair, three of a kind, full house and 4 of a kind.  This is a Monte Carlo method to get an approximation to these probabilities.
//Use at least 1 million randomly generated hands.

#include <stdio.h>

#include <stdlib.h> //rand()

#include <time.h>

typedef struct card //clubs, diamonds, hearts, or spades. 1-13 1 is ace 13 is king.

{ int pips; char suit; } card;

void shuffle(card* ptr);

int main()

{

card deck[53]; //Index 53 is for shuffle. I used Index 53 as temp.

for (int i = 0; i < 52; i++) //Creates a deck with number order.

{
deck[i].pips = (i % 13) + 1; //0 modulo 13 and 13 modulo 13 is 0 so I added 1 to get 1 and 13.

deck[i].suit = (i < 13) ? 'c' : (i < 26) ? 'd' : (i < 39) ? 'h' : 's'; //0-12 c, 13-25 d, 26-38 h 39-51 s.

}

printf("Pip was %d and suit was %c\n", deck[30].pips, deck[30].suit); //To test. This part writes 31th card.

shuffle(deck); //Shuffles the deck.

printf("Pip is %d and suit is %c", deck[30].pips, deck[30].suit); //31th card from shuffled deck. }

void shuffle(card* ptr)

{ time_t t; srand((unsigned)time(&t));

int randomIndex[52], randomNum, randomNum2;

for (int i = 0; i < 52; i++) { randomIndex[i] = i; //randomIndex[] has its members as 0-51. Indexes of deck. If machine generates 13-45 then index 13 and 45 will be changed and randomIndex index 13 and 45 will be replaced with -1. }

for (int i = 0; i < 26; i++) {

do

{ randomNum = rand() % 52; //Until it finds 2 unused and different number, it will retry this action. randomNum2 = rand() % 52; }

while (randomIndex[randomNum] == -1 || randomIndex[randomNum2] == -1 || randomNum == randomNum2);

ptr[52] = ptr[randomNum2]; //Index 52 is used for some kind of cache here. Used ptr because I needed a "card" data type not an int.

ptr[randomNum2] = ptr[randomNum];

ptr[randomNum] = ptr[52];

randomIndex[randomNum] = -1; //Used numbers are replaced by -1. randomIndex[randomNum2] = -1;

}

}