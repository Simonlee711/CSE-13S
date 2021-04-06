//////////////////////////////////////
// Assignment 1: Left Right Center  //
// Author: Simon Lee		    //
// Class & Term: CSE 13s Spring 2021//
//////////////////////////////////////
#include <stdio.h>
#include "philos.h"

//Global Variables to have:
int pos = 0;
int players = 1;
int money = 3;
int center_pot = 0;
int winner = 0;

int main(){
  //ask for seed to be randomized
  int seed;
  printf("random seed here: ");
  scanf("%d", &seed);
  srand(seed);
  printf(seed);
  
  //ask for players
  printf("How many players? ")
  scanf("%d", players)
  if (players < 1 || players > 14){
    return 0
  }
  else(){
  //assign money
  for(i = 0; i < players; i++){
    player[i] = money;
    }
    
  }
}
//SOURCE: Darell Long Assignment 1 document
//PARAMETERS:
//pos: The position of the current player
//players:  number of players in the game
static inline uint8_t left_person(uint8_t pos, uint8_t players) {
  return ((pos+players - 1) % players);	
}
//SOURCE: Darell Long Assignment 1 document
//PARAMETERS:
//pos: The position of the current player
//players:  number of players in the game

static inline uint8_t right_person(uint8_t pos, uint8_t players) {
  return ((pos + 1) % players); 
}

void roll_dice(){

}
