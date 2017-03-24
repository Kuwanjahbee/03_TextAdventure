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
	cout << "'Bounty Hunting Initiative'. Always some business to take care of." << endl;
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
		cin.ignore();

		cout << "     The Astrellas Commons is filled with two groups, bounty hunters" << endl;
		cout << "and their wranglers, or politicians to Jerusalem waiting on bounties " << endl;
		cout << "to be filled. Anastasia fits in both of those categories and is spotted" << endl;
		cout << "by a martini glass that seems surgically attached to her hand. Even in" << endl;
		cout << "a crowd of humans, bat-like aliens, and robots, a woman like this is" << endl;
		cout << "still the main event." << endl;
		cin.ignore();

		cout << "    '" << playerName << "! There you are my darling. I was wondering" << endl;
		cout << "when you would do me the pleasure of your presence. Come, have a whiskey.'" << endl;
		cout << "She beckons you to sit down with her." << endl;
		cout << "(Press the number of your choice)" << endl;
		cout << "(1) Sit with Anastasia" << endl;
		cout << "(2) Ignore her offer" << endl;

		/*Alright so for some reason, I still can't get this temporary bonus part sorted out
		I created a variable to check for sitting position, which should really just be a bool,
		and then I created a pointer to see what content the player filled the variable with. and
		I'm not sure why it isn't populating correctly. See down below.*/
		int DOYOUSIT;
		cin >> DOYOUSIT;
		int *TempSitBonus = &DOYOUSIT;
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
		if (*TempSitBonus == 1) {
			TempSitBonus = (&assignedPlayerStats[5] + 1);
		}

		//For some reason, it only takes the top option, never the esle.
		if (*TempSitBonus || assignedPlayerStats[5] >= 8) {
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
		cin.ignore();

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

		cout << "     On the way towards the dojo, you pass a group; a soldier, a bat like" << endl;
		cout << "alien, a service droid. They seem shocked at your appearance, but do not " << endl;
		cout << "make any attempts to stop you. You make your way for the dojo where there" << endl;
		cout << "two older men enjoying a game of tactics, similar to chess. One of them " << endl;
		cout << "exclaims in victory as you approach." << endl;
		cin.ignore();
		
		cout << "     'You are up young one. Think you can beat an old spacer like me?' the" << endl;
		cout << "winner asks you. His clothes are slightly tattered and beaten. It would be" << endl;
		cout << "most likely that he was mistaken for a bounty, and is buying time until he" << endl;
		cout << "can get off the Astrellas." << endl;
		cout << "(Play the Old mans game? Type the number)" << endl;
		cout << "(1) Yes" << endl;
		cout << "(2) No" << endl;
		int DOYOUPLAY;
		cin >> DOYOUPLAY;
		switch (DOYOUPLAY) {
		case 1:
			cout << "    'I think I could spare time for a game old man,' you say taking a " << endl;
			cout << "seat across from the man. The game, an alien copy of 'Checkers' that one" << endl;
			cout << "would read about in history data slabs seems relatively simple. The old" << endl;
			cout << "doesn't explain the rules." << endl;
			cin.ignore();
			cin.ignore();
			if (assignedPlayerStats[4] >= 8) {
				cout << "     'You're quicker than you look,' says the old man after a period" << endl;
				cout << "of silence. 'I didn't expect to lose. That's alright. Always the " << endl;
				cout << "battle, never the war. Well, it has been pleasant " << playerName << ".'" << endl;
				cin.ignore();
				cout << "    'Wait! I didn't tell you my name,' you begin to yell at the small" << endl;
				cout << "feeble man as he stands up." << endl;
				cin.ignore();
				cout << "     '" << playerName << ", we met many years ago.' The mans body begins" << endl;
				cout << "to lose opacity, fades, and disappears right before your eyes with out" << endl;
				cout << "anything but a small sigh from the air. The checkers remain untouched." << endl;
				cin.ignore();
			}
			else {
				cout << "    'Another loss for you "<< playerName<< ". How many more failures do '" << endl;
				cout << "you plan on putting yourself through?' You look at the old man and his " << endl;
				cout << "toothy grin is not comforting in the least, and you don't know what he " << endl;
				cout << "means by many failures. A cold sense of emptiness fills you as the old" << endl;
				cout << "man whispers, 'Goodbye.' Without a second thought, the illusion is gone" << endl;
				cout << "in front of you, the soldier, robot, and bat alien from the hall are all" << endl;
				cout << "that remain. The soldier has just beaten you in checkers." << endl;
				playersRemainingHitPoints--;
				cin.ignore();
			}
			break;
		default:
			cout << "    'Sorry, I think I have somewhere to be,' you reply to the old man, turning" << endl;
			cout << "your back to the game." << endl;
			cin.ignore();
			cout << "    'Run away then!'" << endl;
			if (assignedPlayerStats[5] >=8){
				cout << "    The old man doesn't phase you, and you continue on your way back to" << endl;
				cout << "where you came from. Anastasia or Yahui Mega require your attention." << endl;
				cin.ignore();
			}
			else {
				cout << "    The old man gets under your skin and fills you with an uncomfortable" << endl;
				cout << "sensation, like ice cold water racing through your veins. A familiar emptiness." << endl;
				playersRemainingHitPoints--;
				cin.ignore();
			
			}
			break;
		}



		///Here is level 2 stage option 3 end
		break;
		
		//the brace below is the end of stage two. Start stage 3 after the brace.
	}

	/*This is the start of stage 3!
	*****************************
	*****************************/
	cout << "     No sooner than do you get a step outside the door, before your" << endl;
	cout << "mind fills with an uncomfortable, familiar voice. '" << playerName << ",'" << endl;
	cout << "it says to you, filling your senses, but much like a whisper spoken through" << endl;
	cout << "a microphone. You had hoped to never feel this presence within you ever again" << endl;
	cout << "but when Michael wants something, he can find a way to get to it." << endl;
	cin.ignore();

	cout << "     'Michael, I thought you were done with me in this timeline. Aren't all" << endl;
	cout << "your wheels already in motion? Aren't you 'free'?' you half sneer, half yell" << endl;
	cout << "to the entity inside your mind." << endl;
	cin.ignore();
	cout << "     'I am, but the more open doors, the more beams, the more beams, than the" << endl;
	cout << "stronger I become. I may even gather enough beams to collect what of me remains" << endl;
	cout << "before the Scream." << endl;
	cin.ignore();
	cout << "     'Good to see some things are still out of your limits.' you aimlessly" << endl;
	cout << "walk the hallway of the Astrellas with no clear path. 'And your pawn now?" << endl;
	cout << "surely after all our time, you'd have no more use for me.'" << endl;
	cin.ignore();
	cout << "     The chasm in your mind seems to take ages to reply." << endl;
	cin.ignore();
	cout << "    'Use? Yes I think I can, but for now, I need you to stand back. Oh," << endl;
	cout << "and take him with you.' Yahui Mega, politician in charge of the Astrellas" << endl;
	cout << "and the Bounty Hunting Initiative rounds a corner ahead of you. His right" << endl;
	cout << "hand clutching his temple, in his left a lazer rifle. He turns and begins" << endl;
	cout << "to raise the barrel at you. The hum doesn't sound like a lazer rifle." << endl;
	cout << "Something is wrong. It's not a rifle." << endl;
	cin.ignore();
	cout << "(How do you react? Type the number)" << endl;
	cout << "(1)Fire back with lazer pistol." << endl;
	cout << "(2)React with monoblade." << endl;
	cout << "(3)Try to turn and run." << endl;
	cout << "(4)Try to talk it out." << endl;

	int stage3case;
	cin >> stage3case;
	switch (stage3case) {
	case 1:
		if (assignedPlayerStats[1] >= 7) {
			cout << "     You draw and fire on Yahui without a second thought. Practiced" << endl;
			cout << "places the lazer right into his chest, an inch to the left of his" << endl;
			cout << "spine. He falls forward as his body begins to give up on him." << endl;
		}
		else {
			cout << "You draw and fire on Yahui, but the bullet gives off a sharp ZWOM" << endl;
			cout << "as it makes contact with the metal walls behind Yahui. The gun he" << endl;
			cout << "weilds is aimed at you." << endl;
			playersRemainingHitPoints--;

		}
		break;
	case 2:
		if (assignedPlayerStats[0] >= 7) {
			cout << "     In a flash, you dart up the hall, drawing your monoblade as you" << endl;
			cout << "sprint. Your monoblade runs Yahui through. He coughs sharply, spewing" << endl;
			cout << "a spray of blood as his body begins to collapse." << endl;
		}
		else {
			cout << "    You're rushing towards Yahui, but after a few paces down the hall," << endl;
			cout << "you realize that Yahui is out of range of your step. The gun he weilds" << endl;
			cout << "is leveled at you." << endl;
			playersRemainingHitPoints--;
		}
		break;
	case 3:
		if (assignedPlayerStats[4] >= 9) {
			cout << "    You turn and run. Leaving Yahui, Leaving Michael, getting away. At" << endl;
			cout << "this point you think running and never stopping is the only way to truly" << endl;
			cout << "get away; to be alone." << endl;
		}
		else
		{
			cout << "	You turn to run, but the process is already in motion. Yahui's gun is." << endl;
			cout << "leveled at you." << endl;
			playersRemainingHitPoints--;
		}
		break;
	default:
		if (assignedPlayerStats[5] >= 9) {
			cout << "	'Yahui!' you shout down the hall. 'Don't do this!' Yahui's face softens" << endl;
			cout << "for just a moment, a look of awareness begins to peak on his face, but is" << endl;
			cout << "quickly swept away by more dull confusion." << endl;
		}
		else {
			cout << "	'Yahui!' you shout down the hall. 'Don't do this!' Yahui's face gives" << endl;
			cout << "no indication of a changing temperment. His face remains a portrait of dull" << endl;
			cout << "confusion, as if his mind was asleep, but his body active." << endl;
			playersRemainingHitPoints--;
		}
		break;
	}
	///End of Stage 3

	///Start of stage 4
	cout << "    Yahui pulls the trigger on the rifle that isn't." << endl;
	cin.ignore();
	cout << "		A milk blue charge leaps from the barrel of his gun." << endl;
	cin.ignore();
	cout << "		The energy fills your vision, blinding you as you white out." << endl;
	playersRemainingHitPoints--;
	cin.ignore();
	cout << playersRemainingHitPoints << endl;
	cout << "     The sensation of floating is the first sense to come back. The same sensation" << endl;
	cout << "but this time you don't feel the bulky exosuit around you. You can't tell if your" << endl;
	cout << "eyes are open, filled with white. You can't determine if you can hear anything at" << endl;
	cout << "all, and the deprivation has caused all sense of time to disappear." << endl;
	cin.ignore();
	cout << "    Time. What kind of illusion is that. Michael is able to contact you in the 'Present'" << endl;
	cout << "navigate through your entire life story like it was a book, extract memories, thoughts," << endl;
	cout << "feelings.. plant seeds in your young mind and watch them flourish in your fifties. Had he" << endl;
	cout << "earned the title of God he sought after? Maybe still he had gaps in his power." << endl;
	cin.ignore();
	cout << "     It must have been more than twenty years ago, but just as well may have been fifty." << endl;
	cout << "You still remember the voice of Michael, burning like fire in your every neuron as he " << endl;
	cout << "demanded you not drink from the 'Fount of Inaquuo'. The nanite infused water from the " << endl;
	cout << "fountain provided a barrier in the mind from Michael continuing to use you, but it also" << endl;
	cout << "provided a side effect; you stop aging. Years mean less as they accumulate like sand." << endl;
	cin.ignore();
	cout << "    Your arm brushes against something, and vision bursts from your retinas. It is white." << endl;
	cout << "You are floating. Near your arm is the body of Yahui Mega. Dead? There is no blood, so " << endl;
	cout << "you lean in closer and hear air by his lips. 'Alive, or maybe we are dead,' you think to" << endl;
	cout << "yourself. 'This must be purgatory.'" << endl;
	cin.ignore();

	cout << "Thank you for playing the current Version of the Stars Without Number Text Adventure." << endl;
	cout << "I hope you enjoyed this small passion project enough to be curious about my future works!" << endl;

}

bool askToPlayAgain()
{
	cout << "Do you want to play another game with a new randomized character? (y/n) \n";
	string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] =='y' || Response[0] == 'Y');
}



