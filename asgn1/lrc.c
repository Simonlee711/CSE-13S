//////////////////////////////////////
// Assignment 1: Left Right Center  //
// Author: Simon Lee		    //
// Class & Term: CSE 13s Spring 2021//
//////////////////////////////////////
#include <stdio.h>
#include "philos.h"

int main(){

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
