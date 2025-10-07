#pragma once

// Including all the necessary header files and links
#include "LDGameLoop.h"
#include "Player.h"
#include "Dice.h"

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//Here is the declaration for the functions that are not included in a class.
int inputBlock(int lower_range, int upper_range, string outOfRangMessege);

//This method gets the player's names and assigns each to a Player object. 
void Game::getPlayerName()    
{
	//local variables
	string name;
	/*This will loop the same number of times and the number of players entered and take input for a name and assign each to the next 
		Player object in the player array.*/
	for (int x = 0; x < allPlayers; x++) {                    
		cout << "Enter player " << x + 1 << "'s name\n";      
		cin >> name;                                          
		players[x].SetName(name);
	}                                                         
}
//This method starts the bulk of the game.
void Game::startGame() 
{
	/* This loop will continue to run until the user entered the number of rounds they wish to play. 
		This loop also calls the function that checks for error handling in the event the user enters something that is not an integer.
		*/
	do {
		cout << "How many rounds do you wish to play?\n";
		roundsToPlay = inputBlock(1, 10, "Your entry is either too high or too low. Pleas chose a number of rounds between 1 and 10.");
	} while (roundsToPlay < 1 or roundsToPlay > 10);

	//This loop until all rounds have been played.
	while (round <= roundsToPlay) {                    
		assignDice();                                  
		playEachRound();                               		
	} 

	//This will display how many points each player has.                                             
	cout << "\n\nAll rounds are now finished, Time to see what everyone got\n";
	for (int x = 0; x < allPlayers; x++) {
		cout << players[x].GetName() << " has a score of " << players[x].getScore() << endl;
	}
}

//This method calls to the roll method in the Dice class. 
void Game::assignDice() 
{
	//local variables
	Dice dice(5);
	int seed = 0;

	//This loops though the Player object Array rolling dice for each player.
	for (int x = 0; x < allPlayers; x++) {     
		
		//This calls the rool method from the dice object and sends the results to the SetDice method.        
		players[x].SetDice(dice.roll(seed));   
		seed++;
	}                                                  
}

//This method controls the functions around each round.
void Game::playEachRound() { 
	//These variables need to be reset after each round. 
	currentPlayer = 0;
	sideOfDice = 0;
	diceBet = 0;
	laps = 0;
	winner = false;

	//This loop will continue giving each player a turn until a winner for this round it found.
	while (winner == false) {
		for (int x = 0; x < allPlayers; x++) {  
			
			//This calls the eachPlayerGame method to give each player a turn.           
			eachPlayerGame(x);                            
			if (winner == true) {
				break;
			}
		}
	} 
	//Declaring the rounds willer
	cout << "Looks like this round goes to " << players[whoWins].GetName() << "!\n";
	
	//This is the call to increase the score of the winning player.
	players[whoWins].setScore(1); 

	whoWins = allPlayers + 1;
	round++;

	/*This will loop until the player is ready to continue so that they can see the results of who one before starting the next round. */
	do
	{
		cout << "Are you ready for " << round << "?" << endl;
		cin >> option;
		if (option == "yes" or option == "YES" or option == "Yes") {}
		else {
			option = "";
		}
	} while (option == "");


}

//This method controls each player’s turn within each round.
bool Game::eachPlayerGame(int x)
{
	/*This refreshes the display so old information is removed. I did this so that when a new 
		players turn starts they cant cheat by looking up to see that last players dice.*/
	system("cls");

	// Here is a brief recap of the rolls. This will remain at the top for each players turn.
	cout << "\n ~ One player makes a bid for what side of the dice is showing and how many.";
	cout << "\n ~ The next player can accept it or call them a liar.";
	cout << "\n ~ If the bid is accepted the round continues and the next player makes a bid.";
	cout << "\n ~ Once a liar is called all dice are revealed and a winner is nammed.\n\n";
	string ready;

	cout << "~ ~ ~ ~ ~ ~ ~ Round " << round << " ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	//This sets currentPlayer to the number that was sent by this methods call.
	currentPlayer = x;    

	//This if statement will set what the last player is based on what the current player is.
	if (currentPlayer == 0) {
		lastPlayer = allPlayers - 1;
	}
	else {
		lastPlayer = currentPlayer - 1;
	}

	//PRINT message telling user it is the next player's turn
	cout << "It is now " << players[currentPlayer].GetName() << "'s turn." << endl;
	do {
		cout << "Are you ready?" << endl;
		cin >> ready;
	} while (ready != "yes" and ready != "Yes" and ready != "YES");
	cout << endl;
	
	//This is a call to the showDice method from the player clase. 
	players[currentPlayer].showDice();          
	cout << endl;

	//This first checks if this is the first turn of the round and if it is not then it calls to the betAcceptOfCall methed
	if (laps != 0) {
		betAcceptOrCall();
		if (winner == true) {
			return true;
		}
	}

	//This is the call to the makeBet method.
	makeBet();                      
	laps++;

	return false;
}

//This method controls the betting system.
void Game::makeBet()
{

	/*This loop asked for the witch side of the dice the player is making their bet about.
		This loop also calls the function that checks for error handling in the event the user enters something that is not an integer.*/
	do {
		//PRINT messages telling the player to make a bid of sideOfDice and numberOfDice 
		cout << "Please make a bid on what side of the dice is showing.\n";
		sideOfDice = inputBlock(1, 6, "These are 6 sided dice, the number must be between 1 and 6");
	} while (sideOfDice < 1 or sideOfDice > 6);

	/*This loop asked for how many of those diced there are in all the player's dice.
		This loop also calls the function that checks for error handling in the event the user enters something that is not an integer.*/
	do {
		cout << "\nHow many do you think are sowing side " << sideOfDice << endl;
		numberOfDice = inputBlock(diceBet, allPlayers * 5, "That is an invalid bet.");

		//This if statment checks if the number of dice is higher then the previous bid.
		if (numberOfDice < diceBet) {
			cout << numberOfDice << " is less than the previous bet. Your bet must be " << numberOfDice + 1 << " or higher.";
		}
		else if (numberOfDice > allPlayers * 5) {
			cout << allPlayers * 5 << " is the number of all dice for all players. Your bet can not be higher than that.";
		}
	} while (numberOfDice < diceBet or numberOfDice > allPlayers * 5);              

	//One the bid is finished the number of dice is saved in diceBid for the next player’s turn.
	diceBet = numberOfDice;
}

//This method controls the acceptance or rejection of the previous bid.
void Game::betAcceptOrCall() 
{
	int countDice = 0;

	//This loop checks wether the player will except the previous players bid or call it.
	do {
		cout << "The current bid is " << numberOfDice << " dice showing side " << sideOfDice << endl;
		
		//PRINT message to get player input on whether to accept the current bid or call the bid a lie using values 1 or 2
		cout << "Will you accept the current bid or call " << players[lastPlayer].GetName() << " a lie?\n";
		cin >> option; 
		
		//If the player accepts the bid this will state that then the loop will end.
		if (option == "yes" or option == "YES" or option == "Yes") {      
			cout << players[lastPlayer].GetName() << "'s bit was accepted.\n"; 
		}
		
		//If the player dose not accepts the bid then the Winner method will be called and this round will end.
		else if (option == "no" or option == "NO" or option == "no") {
			cout << "A lier has been called" << endl; 
			cout << "Time to see who is right" << endl;
			
			//This loop will run though each player then though each dice displaying it and recoring all that watch the bid.
			for (int x = 0; x < allPlayers; x++) {
				for (int i = 0; i < 5; i++) {
					if (players[x].GetDice(i) == sideOfDice) {
						countDice++;
					}
					cout << players[x].GetDice(i) << " ";         
				}
				cout << endl;
			}
			//This is the call to the Winner method and it is sent the count of how many dice matched the bid
			whoWins = Winner(countDice); 
		}
		else {
			option = "";
		}
	} while (option == "");
}

//This is the call to the Winner method and it is sent the count of how many dice matched the bid
int Game::Winner(int countDice)
{
	//This if statment checks if the number of nice is higher then the bid about.
	//If it is then the last player wins the round.
	if (countDice > diceBet) { 
		cout << "The prediction is less then what was there, " << players[lastPlayer].GetName() << " did not lie!" << endl;
		winner = true;      
		
		//Last player declared winner 
		return lastPlayer; 
	}
	//If it is not then the curent player wins the round.
	else { 
		cout << "The prediction of " << players[lastPlayer].GetName() << " was wrong, they did lie!" << endl;                                                          //SET winner to 1
		winner = true;
		
		//curent player declared winner
		return currentPlayer; 
	}

	return 0;
}

//This is a fuction to test if the user input is corect
int inputBlock(int lower_range, int upper_range, string outOfRangMessege) {

	/* As I was testing the program I was running into errors when i acsudently put the wrong input type for an input witch would case the 
	hole program to stop. To solve that I added a try catch black but then it created an infunent loob. I then had to reserch what was casing 
	that and found out it has to do with the input buffer so I added a clear to the input. Once that was finished I decided I didnt want to 
	repet that coad more then nesasary so I created this function for the task. Then I was faced with the problem of testing for peramiters 
	and how to handle explaining to the user what was entered wrong. I realised I could send three values to the function, One each for the 
	uper and lower ranges of the paramiters and another for the mesege based on the specific input being requested. Now the same code can be
	used to test input in moltipole locations. */

	int testInput = 0;

	try {
		cin >> testInput;
		
		//This will catch a type mismatch like trying to put a string in to an int
		if (cin.fail()) 
		{
			//This twors the error to the catch block
			throw runtime_error("Input is not an integer\n"); 
		}

		// This will test if the input is within nesasary paramiters
		else if (testInput < lower_range or testInput > upper_range) { 
			cout << outOfRangMessege << endl;
		}
	}
	//This catches the mismatch type error so the program dose not have to crash.
	catch (const runtime_error& e) { 

		//This nect part prevents an infunet loop.
		//clear bad input flag 
		cin.clear(); 
		//discard input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		cout << "Input is not an integer; Please try again:\n";
	}
	
	//Once user input is deamed to be coreact it is returned to where the function was called.
	return testInput; 
}

