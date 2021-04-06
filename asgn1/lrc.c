//////////////////////////////////////
// Assignment 1: Left Right Center  //
// Author: Simon Lee		    //
// Class & Term: CSE 13s Spring 2021//
//////////////////////////////////////
#include <stdio.h>
#include "philos.h"
#include <stdint.h>

//Global Variables to have:
int pos = 0;					//position equals 0
int players = 1;				//minimum players = 1
int money[14] ;					//money can be assigned up to 14 players - SOURCE: Small Group Tutoring
int center_pot = 0;				//center pot has no money to begin
int winner = 0;					//winner is not declared

int main(){
  
  //ask for seed to be randomized
  int seed;
  printf("random seed here: ");
  scanf("%d", &seed);
  srand(seed);
  
  //ask for players
  printf("How many players? ")
  scanf("%d", players)
  if (players < 2 || players > 14){		//if not in range 2<i<14. end program		
    return 0
  }
  else(){
 
  //assign money
  for(i = 0; i < players; i++){			//assigning money to amount of players 
    money[i] = 3;				// iterating i=players amount of times
    }	
 
  //actual game portion
  while(winner = 1){				//while loop to simulate game
    int temp = money[pos];
    if(money >= 3){				//if money is >= 3 roll 3 times
      for(i = 0; i < 3; i++){			//for loop iterates 3 times
	roll();					//function roll is called 3 times
      }
      //move index to the right once
      if(/*if only one player has atleast 1$*/){				//if one player remains declare winner
	  game_winner = players[i]; 		//winner is player[i]
	  printf("winner is", game_winner); 	//print winner
          winner += 1;				//prompt condition to exit while loop
      }
      else(){					//else statement returns to beginning of while loop
	  continue;				
      }
      }
    }
    else(){					//last statement represents a skip in turn
      //move player index one to the right 
      continue

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

void roll_dice(int pos, int players){
  int random = 0;

}


