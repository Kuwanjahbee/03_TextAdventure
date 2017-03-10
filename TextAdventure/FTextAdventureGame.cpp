#pragma once

#include "stdafx.h"
#include "FTextAdventureGame.h"
using namespace std;

FTextPlayerLogic::FTextPlayerLogic() { Reset();} //constructor takes only one paremeter, the reset method!

int FTextPlayerLogic::getPlayersCurrentHealth() const {return playersCurrentHealth;}

void FTextPlayerLogic::Reset()
{
	const int MAXIMUM_HEALTH = 5;
	playersCurrentHealth = MAXIMUM_HEALTH;
	return;
}


