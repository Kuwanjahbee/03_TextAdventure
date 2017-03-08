#pragma once

#include "stdafx.h"
#include "FTextAdventureGame.h"
using namespace std;

FPlayerData::FPlayerData() { Reset();} //constructor takes only one paremeter, the reset method!

int FPlayerData::GetPlayersCurrentHealth() const {return playersCurrentHealth;}

void FPlayerData::Reset()
{
	const int MAXIMUM_HEALTH = 5;
	playersCurrentHealth = MAXIMUM_HEALTH;
	return;
}
