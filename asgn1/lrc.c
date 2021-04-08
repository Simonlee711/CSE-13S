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
int winner = 0;					//winner is not declared - SOURCE: Small Group Tutoring

//dice enumeration used in roll function
typedef enum faciem { PASS, LEFT, RIGHT, CENTER } faces;
faces die[] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS };

int main(){
  
  //ask for seed to be randomized
  int seed;
  printf("Randome Seed: ");
  scanf("%u", &seed);
  srandom(seed);
  
  //ask for players
  printf("Number of players: ")
  scanf("%u", &players)
  if (players < 1 || players > 14){		//if not in range 2<i<14. end program		
    return 0
  }
  else(){
     //print  

  //assign money
  for(i = 0; i < players; i++){			//assigning money to amount of players 
    money[i] = 3;				// iterating i=players amount of times
    }	
 
  //actual game portion
  while(winner != 1){				//while loop to simulate game
    int track_money = money[pos];
    if(track_money >= 3){				//if money is >= 3 roll 3 times
	money[i] = roll(3);					//function roll is called 3 times
      }
      //move index to the right once
      if( ){				//if one player remains declare winner
	  game_winner = players[pos]; 		//winner is player[i]
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

void roll_dice(int num_rolls){
  for (i = 0; i < num_rolls; i++){
   roll = die[random() % 6];
   if(roll == 0){ //pass left because enum index 0 is Left
     players[i] = 
   }
   if(roll == 1){ //pass right because enum index 1 is right
   }
   if(roll == 2){ //put in center because enum index 2 is center
   }
   else(){ //return back to function
   }
  return //money
  }
  

}

