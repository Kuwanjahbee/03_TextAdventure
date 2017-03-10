#pragma once

/*The game logic, no direct code or user interaction.*/
#include <string>

enum EnextMoveStatus
{
	OK,
	Invalid_Status,
};

class FTextPlayerLogic
{
	FTextPlayerLogic(); //Constructor defined in source with :: operator

public:
	int getPlayersCurrentHealth() const;

	
	void Reset();

private:
	int playersCurrentHealth;




};