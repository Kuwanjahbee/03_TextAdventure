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
//#include "FTextAdventureGame.h"

//Using Spaces
using namespace std;

void printIntro();
void playGame();
const int totalNumberOfStats = 6;
int assignedPlayerStats[totalNumberOfStats];
bool askToPlayAgain();
string playerName = "";


/*Going to create a class to handle the game logic here, as I'm having trouble getting it into another file.
Right Now i'm just trying to create a class that will handle player health, 
and possibly stats if I can get it into there.*/

class FTextPlayerLogic
{
public:
	int getPlayersCurrentHealth(){return playersCurrentHealth;}
	int getPlayersCurrentLevel() { return playersCurrentLevel; }

private:
	int playersCurrentHealth = 5;
	int playersCurrentLevel = 1;
};



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
	cout << "Are you ready for another exciting story?\n\n";


	cout << "     You sit patiently in the cockpit of your private vessel," << endl; 
	cout << "entering in to the Jerusalem Sector. Spending the last six days" << endl; 
	cout << "in subspace, cut off from communication with the rest of the galaxy" << endl; 
	cout << "tends to take a toll on some of the less strong willed individuals.'\n" << endl; 
	cout << "     Staring off into the endless black you collect your wits." << endl; 
	cout << "Pushing on the throttle of your starship and adjusting your pitch" << endl; 
	cout << "you make for the Astrellas. The captial ship of Jerusalems' " << endl;
	cout << "'Bounty Hunting Initiative'. Always some business totake care of.\n" << endl;

	cout << "     You begin to near one of the only ships of it's kind. A" <<endl;
	cout << "dimplomatic ship of destruction that employs dogs of no nation to do" << endl;
	cout << "it's dirty work for them. The cool gray hull and bright logo of" << endl;
	cout << "Jerusalem should put one at ease, but not you.\n" << endl;

	cout << "     'Starship Vega One Niner you are recognized, please forward your" << endl;
	cout << "name and current health status for our system,' comes a cheery" << endl;
	cout << "voice through the transmission." << endl << endl;
	return;
}

//The game method that runs in main
void playGame()
{
	//declaring a class to check the current health of the player
	FTextPlayerLogic FThePlayerCharacter;
	int playersRemainingHitPoints = FThePlayerCharacter.getPlayersCurrentHealth();

	// Creating name and stats.
	cout << "(Please enter a name for your character)"<< endl;
		getline(cin, playerName);

	cout << "     'Vega One Niner '" << playerName << "' confirmed, routing health" << endl;
	cout << "status to your current display. Please confirm?'" << endl<< endl;
	

	
	// This is the formula for randomly generating stats, and it scales up from a hardcoded numberofstats value
	srand(time(0));
	for (int x = 0; x <= (totalNumberOfStats - 1); x++) { assignedPlayerStats[x] = 3 + (rand() % 7); }

	
	cout << "STR: " << assignedPlayerStats[0] << "     INT: " << assignedPlayerStats[3] << endl;
	cout << "DEX: " << assignedPlayerStats[1] << "     WIS: " << assignedPlayerStats[4] << endl;
	cout << "CON: " << assignedPlayerStats[2] << "     CHA: " << assignedPlayerStats[5] << endl << endl;

	if (assignedPlayerStats[0] > totalNumberOfStats) {
		cout << "'Damn you must be in good shape!'\n";
		if (assignedPlayerStats[0] > (totalNumberOfStats + 2)) {
			cout << "'Especially if you won the last martial tournament!'\n";
		}
	}
	else {
		cout << "'Your vitals seem a little out of check, bringing up current health.'" << endl; 
	}
	cout << endl;
	cout << "'It says here that you have " << playersRemainingHitPoints <<" health."<< endl;
	cout << "That seems good enough to me. Go ahead and bring the ship in to dock.'" << endl << endl;

	// present a challenge to the player
	cout << "Alright " << playerName << ", I need you to pick up this box for me.\n";
	if (assignedPlayerStats[0] >= 3) //TODO, make richer return value "roomDifficultyCheck"
	{
		cout << "*You successfully lift the box!*\n";
	}
	else {
		cout << "*You strain and hurt yourself*\n";
		playersRemainingHitPoints--;
		cout << playersRemainingHitPoints <<endl <<endl;
	};

}

bool askToPlayAgain()
{
	cout << "Do you want to play another game with a new randomized character? (y/n) \n";
	string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] =='y' || Response[0] == 'Y');
}

