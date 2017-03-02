// TextAdventure.cpp : Defines the entry point for the console application.
/*Game Design Document:
Concept: Text Adventure game with random stats, health, and at least one ending.
Rules: After certain checkpoints, or rooms, the player is tested based on a stat, losing health if they fail, at zero health they die.
Requirements: keyboard and string inputs.
*/

//Includes
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "FTextAdventureGame.h"

//Using Spaces
using namespace std;

void printIntro();
void playGame();
const int totalNumberOfStats = 6;
int assignedPlayerStats[totalNumberOfStats];
bool askToPlayAgain();
string playerName = "";




int main()
{
	bool bPlayAgain = false;
	do {
		printIntro();
		playGame();
		askToPlayAgain();
	} while (bPlayAgain);

	return 0;
}


//The entry point for the application. Use this to welcome the player.
void printIntro()
{
	cout << "\nHello and welcome to another Text Adventure!\n";
	cout << "Are you ready for another exciting story?\n";
	return;
}

void playGame()
{
	// 
	cout << "\nWhat can we call you? What is your name young one?\n";
		getline(cin, playerName);
	cout << "\nYour name is " << playerName << "?\n";
	cout << "That is a good strong name. Are you very strong?\n\n";
	
	
	srand(time(0));
	for (int x = 0; x <= (totalNumberOfStats - 1); x++) { assignedPlayerStats[x] = 3 + (rand() % 7); }

	
	cout << "STR: " << assignedPlayerStats[0] << "     INT: " << assignedPlayerStats[3] << endl;
	cout << "DEX: " << assignedPlayerStats[1] << "     WIS: " << assignedPlayerStats[4] << endl;
	cout << "CON: " << assignedPlayerStats[2] << "     CHA: " << assignedPlayerStats[5] << endl;

	if (assignedPlayerStats[0] > totalNumberOfStats) {
		cout << "Wow you are strong!\n";
		if (assignedPlayerStats[0] > (totalNumberOfStats + 2)) {
			cout << "The strongest I've ever seen!\n";
		}
	}
	else {
		cout << "Only a " << assignedPlayerStats[0] << ". That is okay, STR isn't always what is best.\n";
	}


	// present a challenge to the player


}

bool askToPlayAgain()
{
	cout << "Do you want to play another game with a new randomized character? (y/n) \n";
	string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] =='y' || Response[0] == 'Y');
}
