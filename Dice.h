#pragma once
// Including all the necessary header files and links
#include <time.h> 
#include <stdlib.h> 
#include <iostream>
#include "Player.h"

using namespace std;

// This is the Dice Class
class Dice { 
	//This is the privet portion of the class that can only be accessed by the class itself.
private:          
	//These are variables and arrays
	int allPlayersDice[7][5]{ { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0 } }; //= { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0 } }
	int thePlayrs = 0;
	int allDice = 0;
	
//This is the public portion of the class that can be accessed from outside of the class.
public: 
	//This is the Dice constructor that required the number of dice.
	Dice(int allDice)
	{
		allDice = allDice;
	}	

	//This is the meted that rolls the dice.
	int* roll(int seed) { 
		//local variables
		int test;
		int lower_range = 1, upper_range = 6;
		int playerDice[5];
				
		//This helps generate random numbers.
		srand(time(0)+ seed); 

		/* I used the curent time to helt the randome number generat a randome number but when I did just that 
		each player would just get 5 of the same number or all players would have all the same numbers. 
		I realized that because the function was being called so quickly the time was the same for each
		run. So I added a variable seed to time and had it incrumented at the end of each run to change the seed 
		for the randome number generater and it worked perfectly.*/

		//This is the random number generator.
		//FOR as long as x is less than 5, increment x 
		for (int i = 0; i < 5; i++) {
			do {
				int mod = (upper_range - lower_range + 1) + lower_range;
				int num = (rand() % mod);
				test = num;
			} while (test == 0);
			//Assines the random number to one of the player's dice.
			playerDice[i] = test; 	
			
		}	
		thePlayrs++;
		return playerDice;
	}
};



