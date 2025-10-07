#pragma once
// Including all the necessary header files and links
using namespace std;
#include <string>

//This is the Player class
class Player                 
{
//This is the privet portion of the class that can only be accessed by the class itself.
private:                     
	//These are variables and arrays
	string p_name = "";       
	int p_score = 0;          
	int eachDice[5] = { 0, 0, 0, 0, 0 }; 

//This is the public portion of the class that can be accessed from outside of the class.
public:                      
	//This is the Player constructor
	Player()                
	{
	}
	//This is the Player constructor that required a string and assigned it to the name. 
	Player(string name)      
	{
		string p_name = name;
	}
	
	//These are the declarations for the classes methods witch are defined in the player.cpp file.
	void SetName(string name);     //This will change the player’s name.
	const string GetName();        //This will return the player's name.
	void setScore(int score);      //This will increase the player's score.
	const int getScore();          //This will return the player's score.
	void SetDice(int dice[5]);     //This will save the player's dice.
	int GetDice(int x);            //This will return the player's dice one at a time.
	void showDice();               //This will return the player's dice.
};
