#pragma once

/*The game logic, no direct code or user interaction.*/
#include <string>

enum EnextMoveStatus
{
	OK,
	Invalid_Status,
};

class FTextGame
{
private:
	int playersCurrentHealth = 5;

public:
	int GetPlayersCurrentHealth();


};