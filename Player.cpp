#pragma once
// Including all the necessary header files and links
#include <iostream>
#include <string>
using namespace std;

#include "Player.h"

//This will change the player’s name.
void Player::SetName(string name)    
{
	p_name = name;                   
}

//This will return the player's name.
const string Player::GetName()       
{
	return p_name;                   
}

//This will increase the player's score.
void Player::setScore(int score)     
{
	p_score = p_score + score;       
}

//This will return the player's score.
const int Player::getScore()         
{
	return p_score;
}

//This will save the player's dice.
void Player::SetDice(int dice[5])   
{
	for (int i = 0; i < 5; i++) {
		eachDice[i] = dice[i];
	}	
}

//This will return the player's dice one at a time.
int Player::GetDice(int x)            
{
	return eachDice[x];
}

//This will return the player's dice. 
void Player::showDice()              
{
	for (int x = 0; x < 5; x++) {               
		cout << eachDice[x] << " ";         
	}                                            
}

