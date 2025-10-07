#pragma once
// Including all the necessary header files and links
#include "Player.h"
#include "Dice.h"

//This is the body of the Game Class
class Game 
{
	//This is the privet portion of the class that can only be accessed by the class itself.
private:
	//These are variables and arrays
	int currentPlayer;
	int lastPlayer;
	int allPlayers = 0; 
	int round = 1;
	int roundsToPlay = 0;
	int laps;
	int starter = 0;
	string option;                  
	bool winner = false;              
	int whoWins = allPlayers + 1;
	int numberOfDice = 5;        
	int sideOfDice;              
	int diceBet;                 
	
	// This is an array that holds the opjects built from the Player class.
	/* At first I was having dificoltes creating unike object names for each player class while still having any flexibility 
	for how many players would be playing. I realised that using a class Array to build the player objects was the best way 
	to go as it helped me to latter run though each player in the array*/
	Player players[7] = {
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
	};
	
//This is the public portion of the class that can be accessed from outside of the class. 
public:
	
	//This is the Player constructor that required the number of Players.
	Game(int numberOfPlayers) { 
		allPlayers = numberOfPlayers;

	}	
	//These are the declarations for the classes methods witch are defined in the GameLoop.cpp file.
	void getPlayerName();        //This method gets the player's names and assigns each to a Player object. 
	void assignDice();           //This method calls to the roll method in the Dice class.
	void startGame();            //This method starts the bulk of the game.
	void playEachRound();        //This method controls the functions around each round.
	bool eachPlayerGame(int x);  //This method controls each players turn within each round.
	void makeBet();              //This method controls the betting system.
	void betAcceptOrCall();		 //This method controls the accepting or rejecting of the previous bid.
	int Winner(int countDice);   //This method checks who won once a bid has been rejected. 	
};