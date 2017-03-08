#pragma once

/*The game logic, no direct code or user interaction.*/
#include <string>

enum EnextMoveStatus
{
	OK,
	Invalid_Status,
};

class FPlayerData
{
	FPlayerData(); //Constructor defined in source with :: operator

public:
	int GetPlayersCurrentHealth() const;
	
	void Reset();

private:
	int playersCurrentHealth;




};