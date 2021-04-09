//////////////////////////////////////
// Assignment 1: Left Right Center  //
// Author: Simon Lee		    //
// Class & Term: CSE 13s Spring 2021//
//////////////////////////////////////
#include <stdio.h>
#include "philos.h"
#include <stdint.h>
#include <stdlib.h>

//dice enumeration used in roll function
typedef enum faciem { PASS, LEFT, RIGHT, CENTER } faces;
faces die[] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS };

int main(void){
  int players;
  int seed = 0; 
  //int money_pot = 0;
  //int winner = 0;

  //enter random seed
  printf("Random Seed: ");
  int valid_seed = scanf("%u", &seed);
  if((valid_seed < 0 || seed < 1)){
    fprintf(stderr, "Invalid seed\n");
    return 1;
  }
  srandom(seed);


  //# of players user input
  printf("Enter Players: ");
  int valid_players = scanf("%u", &players);
  if(valid_players < 0 || players > 14 || players < 2){
    fprintf(stderr, "Invalid number of players\n");
    return 1;
  }

  //assign money
  int money[14];
  for(int i = 0; i < players; i++){
    money[i] = 3;
  }
  
  //actual game 
  int players_in = players;
  int pos = 0;
  int dice_roll = 0;
  while(players_in > 1){
    printf("%s", philosophers[pos]);
    printf(" rolls...");
    if (money[pos] > 3){
      dice_roll = 3;
    }else{
      dice_roll = money[pos];
    }
    
    //dice enumeration used in roll function
    typedef enum faciem { PASS, LEFT, RIGHT, CENTER } faces;
    faces die[] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS };
    
    for(int i = 0; i < 1; i++){
       int face_die = die[random() % 6];
       printf("%d", face_die);
       switch(face_die){
	       case LEFT:
		       printf("rolled left");
		       break;
	       case RIGHT:
		       printf("rolled right");
	               break;
	       case CENTER:
                       printf("rolled center");
                       break;
	       case PASS:
		       printf("pass");
		       break;
    }
  }
}
}
/*
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

*/
