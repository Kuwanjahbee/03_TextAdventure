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
		//askToPlayAgain();
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

	/*This is where Level 2 starts. 
	***********************
	***********************
	It's a switch statement*/

	cout << "Where do you want to go? (Type the number)" << endl;
	cout << "(1) Pay a visit to Yahui Mega." << endl;
	cout << "(2) Go see Anastasia Polaris." << endl;
	cout << "(3) Go to the dojo." << endl;
	int STAGE2OPTION;
	cin >> STAGE2OPTION;
	cout << endl;

	
	switch (STAGE2OPTION) {
		///Here is the level 2 stage option 1 start
		//case 1 uses DEX
	case 1: cout <<"     Yahui Mega it is. Pompous ass is probably sitting in his office" << endl;
		cout << "right now. You can picture his greasy black hair slicked back, sticking" << endl;
		cout << "together like tiny tentacles. You walk with a strong stride towards the" << endl;
		cout << "bridge of the ship.\n" << endl;
		cin.ignore();

		cout << "     You turn a corner and spot the door to Yahui Mega's office, just as" << endl;
		cout << "it comes to a close with a light hiss of air. You approach the door and" << endl;
		cout << "press the button on the console near it. The door opens and reveals an " << endl;
		cout << "empty office with the lights on. You take a step inside to look around.\n" << endl;
		cin.ignore();

		if(assignedPlayerStats[1] >=6)
		{
			cout << "    The glint of the blade catches your eyes, and your hands react (DEX) more" << endl;
			cout << "quicklythan the rest of your person. You catch Yahui Mega by the wrist," << endl;
			cout << "holding a knife. He looks panicked, terrified, and lost.\n" << endl;
		}else{
			cout << "    Your reaction (DEX) is just a hair too slow. You see the blade, but it " << endl;
			cout << "knicks you in the shoulder as you move away from it's path. Stepping" << endl;
			cout << "to the side, you come face to face with Yahui Mega. He looks confused" << endl;
			cout << "at your appearance.\n" << endl;
				playersRemainingHitPoints--;
		}
		cout << "     'Yahui, it's me, " << playerName << ", what's going on. Why did you" << endl;
		cout << "attack me?" << endl;
		cin.ignore();
		cout << "     'I... being followed.. Haven't slept two, three days, voices...' comes a" << endl;
		cout << "mumbled replied from Yahui." << endl;
		cin.ignore();
		cout << "     'Look, here is the data you wanted.' You hand over a data storage " << endl;
		cout << "container to Yahui. 'I trust you'll carry through with your end.' You" << endl;
		cout << "exit the office, leaving the broken man to snivel in piece.\n" << endl;
		cin.ignore();
		///Level 2 stage option 1 end
		break;

		///Here is the level 2 stage  option 2 start
	//case 2 uses CHA
		{case 2: cout << "     Anastasia. A job is a job, and you need to get paid. She's most" << endl;
		cout << "likely hanging around the bar. Like most wranglers, that's where she can" << endl;
		cout << "find her hunters, or find a stiff drink. You head toward the common area" << endl;
		cout << "of the Astrellas, hoping to find your handler, Anastasia, and get paid.\n" << endl;
		cin.ignore();

		cout << "     The commons of the Astrellas is filled with two groups, bounty hunters" << endl;
		cout << "and their wranglers, and politicians to Jerusalem waiting on bounties to be" << endl;
		cout << "filled. Anastasia fits in both of those categories and is easily spotted by" << endl;
		cout << "a martini glass that seems surgically attached to her hand. Even in a crowd" << endl;
		cout << "of humans, bat-like aliens, and robots, a woman like this is still the main" << endl;
		cout << "event." << endl;
		cin.ignore();

		cout << "    '" << playerName << "! There you are my darling. I was wondering when you" << endl;
		cout << "would do me the pleasure of your presence. Come, have a whiskey.' She beckons" << endl;
		cout << "you to sit down with her." << endl;
		cout << "(Press the number of your choice)" << endl;
		cout << "(1) Sit with Anastasia" << endl;
		cout << "(2) Ignore her offer" << endl;
		int DOYOUSIT;
		cin >> DOYOUSIT;
		int *sitptr = &DOYOUSIT;
		if (DOYOUSIT == 1) {
			cout << "     'Thank you Anastasia, a drink sounds lovely while we talk some business.'" << endl;
			cout << "You take a seat next to her and gulp down the whiskey with practiced ease." << endl;
			cin.ignore();
		}
		else {
			cout << "     'I hope you don't mind if I stand instead,' comes a quick reply from you." << endl;
			cout << "Anastasia gives you a feigned smile. 'No, of course not.'" << endl;
			cin.ignore();
		}
		cout << "     'Osiris Mazhour; wanted for Orchestrating Gang violence to spread dissent." << endl;
		cout << "Now, Anastasia, you and I both know that Jerusalem's planet Canaan, where Osiris" << endl;
		cout << "is from has no way to instigate dissent between Jerusalem government. What is he" << endl;
		cout << "really wanted for,' You end with a deadlock stare, trying to persuade (CHA) her " << endl;
		cout << "to tell you what she knows." << endl;
		// trying to apply a temporary + 1 bonus for sitting
		if (*sitptr == 1) {
			*sitptr = assignedPlayerStats[5] + 1;
		}
		if (*sitptr || assignedPlayerStats[5] >= 8) {
			cout << "     'Okay, " << playerName << ". I'll level with you. We think Osiris got a " << endl;
			cout << "hold of something that came from Petra. Petra ships ore to Canaan where it's " << endl;
			cout << "refactored. Osiris found something that belongs to my family. I'll credit you" << endl;
			cout << " Fifty Thousand credits from his bounty.'" << endl;
			cin.ignore();
			cout << "     'I thought there was more to it. A nobody from a ocean planet of half a" << endl;
			cout << "a million lives. I see you and yours are just as crooked as the next.' As you" << endl;
			cout << "say this, Anastasia's face takes on a look of horror. 'Don't play like you are" << endl;
			cout << "any less empty, just because you can fill your hole with a martini.'" << endl;
			cin.ignore();
		}
		else {
			cout << "     'Darling, " << playerName << ", honey. Don't bother yourself with the tasks" << endl;
			cout << "and affairs of the Handlers. It's poor sportsmanship. You just worry about how " << endl;
			cout << "to capture as many targets as you can, and climb the ranks to be the best. Leave" << endl;
			cout << "who we target, and how much I pay you, to me. You'll have your payment for Osiris," << endl;
			cout << "and another target shortly. Now let me enjoy myself.'" << endl;
			cin.ignore();
			playersRemainingHitPoints--;
		}


		cout << "    You exit the commons with the satisfaction of payment soon arriving." << endl;


		}

		///Here is the level2 stage option 2 end
		break;
	

		///Here is the level2 stage option 3 start
	//case 3 uses WIS
	default: cout << "     You zone out a little and feel a strange tug from within you." << endl;
		cout << "Your feet shuffle in an awkward cadence as you make your way through the" << endl;
		cout << "commons, towards the dojo area of the Astrellas. You put intent behind " << endl;
		cout << "your steps and plod down the hallway.\n" << endl;
		cin.ignore();

		cout << "" << endl;


		///Here is level 2 stage option 3 end
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



