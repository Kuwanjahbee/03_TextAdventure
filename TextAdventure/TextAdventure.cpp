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
int currentRoomDifficulty=0;


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
	cout << "(After a Paragraph, press Enter to Continue)";
	cin.ignore();


	cout << "     You sit patiently in the cockpit of your private vessel," << endl; 
	cout << "entering in to the Jerusalem Sector. Spending the last six days" << endl; 
	cout << "in subspace, cut off from communication with the rest of the galaxy" << endl; 
	cout << "tends to take a toll on some of the less strong willed individuals.'"<< endl;
	cin.ignore();
	
	
	cout << "     Staring off into the endless black you collect your wits." << endl; 
	cout << "Pushing on the throttle of your starship and adjusting your pitch" << endl; 
	cout << "you make for the Astrellas. The captial ship of Jerusalems' " << endl;
	cout << "'Bounty Hunting Initiative'. Always some business totake care of." << endl;
	cin.ignore();

	cout << "     You begin to near one of the only ships of it's kind. A" <<endl;
	cout << "dimplomatic ship of destruction that employs dogs of no nation to do" << endl;
	cout << "it's dirty work for them. The cool gray hull and bright logo of" << endl;
	cout << "Jerusalem should put one at ease, but not you.\n" << endl;
	cin.ignore();

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
	cin.ignore();

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
	cin.ignore();

	// present a challenge to the player
	cout << "    'Alright, " << playerName << ". Lately we've been having trouble with the"<<endl;
	cout << "auto-docking procedure. Unfortunately you are going to have to bring her" << endl;
	cout << "in manually. I can't remember if you have been doing this for a while (WIS)" << endl;
	cout << "or if you are just naturally a smart guy(INT), but go ahead and start the " << endl;
	cout << "docking process.' " << endl << endl;
	cin.ignore();
	if (assignedPlayerStats[3] >= 4 || assignedPlayerStats[4] >=5) //TODO, make richer return value "roomDifficultyCheck"
	{
		cout << "      You reach for the console and touch a button that ends the" << endl;
		cout << "transmission. You've been doing this longer than this greenhorn has" << endl;
		cout << "been alive. Shifting orientation of your small personal vessel with" << endl;
		cout << "practiced perfection, like a ballerina in zero G, your ship spins," << endl;
		cout << "and rolls nearer to the cruiser. You come in faster than you should, " << endl;
		cout << "pump the breaks and gently nudge against the side of the Astrellas." << endl << endl;
		
	}
	else {
		cout << "      You reach for the console and touch a button that ends the" << endl;
		cout << "transmission. You've been doing this longer than this greenhorn has" << endl;
		cout << "been alive. Shifting orientation of your small personal vessel with" << endl;
		cout << "less care than one should. You come in just a touch faster than you" << endl;
		cout << "anticipate you will. Your personal ship bumps the cruiser with a " << endl;
		cout << "strong force. A book stored in a container above your head falls on" << endl;
		cout << "your head, causing a small gash off the side of your forehead." << endl;
		playersRemainingHitPoints--;
		cout << "(A single point of damage has been done to your health, but the story continues.)" <<endl <<endl;
	};
	cin.ignore();
	cout << "     The dock process initiatied, you go over your mission. You need "<<endl;
	cout << "to turn in your bounty and pay a visit to Yahui Mega, the head of the" << endl;
	cout << "Bounty Hunting Initative. Turning in your bounty, 'Osiris Mazhour' means" << endl;
	cout << "a meeting with your Handler though. Your Handler, 'Anastasia Polaris'" << endl;
	cout << "can be quite a treat, but that's only if it isn't a trick.\n" << endl;
	cin.ignore();
	cout << "Where do you want to go? (Type the number)" << endl;
	cout << "(1) Pay a visit to Yahui Mega." << endl;
	cout << "(2) Go see Anastasia Polaris." << endl;
	cout << "(3) Go to the dojo." << endl;
	int STAGE2OPTION;
	cin >> STAGE2OPTION;

	
	switch (STAGE2OPTION) {
	case 1: cout <<"1";
		break;
	case 2: cout <<"2";
		break;
	default: cout << "3 default";
		break;

	}
}

bool askToPlayAgain()
{
	cout << "Do you want to play another game with a new randomized character? (y/n) \n";
	string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] =='y' || Response[0] == 'Y');
}



