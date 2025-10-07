/* Rebecca St.Clair
IT-312-H6065 Software Devel w/C++.Net 23EW6
08/13/2023 */

/*
This is the main file that contains the start of the program. This is the game liars dice which is a game where you try to 
guess how many dice have been rolled to a number. The next player can choose to accept the bid and take their turn or 
challenge it and see what was rolled. This program prompts the user for how many players there will be and how many 
rounds will be played. Once all the rounds have been played the scores will be displayed to see who is the ultimate winner.
*/


// Including all the necessary header files and links
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h> 
#include <stdlib.h> 
#include "Dice.h"
#include "Player.h"
#include "LDGameLoop.h"

using namespace std;

//Here is the declaration for the functions that are not included in a class.
void printRules();
int inputBlock(int lower_range, int upper_range, string outOfRangMessege);

//This is the main portion of the program
int main()
{
	//The variables for main
	int numberOfPlayers; 
	
	//Print out a welcome statement.
	cout << "Welcome to Liar's Dice!\n\n";

	//This is a call to the function down below that prints the rules.
	printRules(); 

		/* This is a loop that will request the number of players and continue to repeat till the user enters a number 
				that is within specified parameters. This loop also calls the function that checks for error handling in the 
				event the user enters something that is not an integer.  */
	do { 
		cout << "\nHow many will be playing?:\n";  
		numberOfPlayers = inputBlock(2, 6, "You need at least 2 players for this game; please try again:");
	} while (numberOfPlayers < 2 or numberOfPlayers > 6);

	//This is the call to the constructor of the Game class to build a game object.
	Game game = Game(numberOfPlayers);          
	
	/*This is the call to a method of the Game class that will prompt the user to enter each player's name and sore 
		each one in an object built from the player class.*/
	game.getPlayerName();     
	
	//This is the call to a method of the Game class that will start the main portion of the game.
	game.startGame();                          

	//This is the end of the program.
	return 0;                                  
}

//This is the function that prints the rules.
void printRules() {                                     
	//Here are the necessary local variables.
	string fileLine;
	
	//This opens the file where the rules are stoed.                                   
	ifstream file("Liar'sDice.txt");                   
	cout << "The rules are as follows: \n\n";
	
	//This cheks if the file is open.
	if (file.is_open())                                
	{
		//This loop will continue until there are no more lines left of the file to be read.
		while (getline(file, fileLine))                
		{
			//This will print each line of the file.
			cout << fileLine << ' ' << endl;           
		} 
		//This will close the file.                                             
		file.close();                                  
	}
	//If the file could not be opened or found then this will display an error message.
	else                                               
	{
		cout << endl << "Cannot open file\n\n";        
	}                                                 
}