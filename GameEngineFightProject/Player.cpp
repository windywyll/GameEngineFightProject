/**
 * Project Untitled
 */

#include <math.h>
#include "Player.h"

/**
 * Player implementation
 */


Player::Player(int heal)
{
	lifePoints = heal;
}

Player::Player(int heal, std::vector<Action*> actList)
{
	lifePoints = heal;
	actionList = actList;
	currentState = new Idle();
}

PlayerState* Player::getCurrentState()
{
	return currentState;
}

void Player::setState(PlayerState* state)
{
	currentState = state;
}

/**
 * @param dmg
 */
void Player::applyDamage(int dmg) {
	dmg = abs(dmg);
	if (dmg >= lifePoints)
	{
		lifePoints = 0;
		setState(new Death());
		//Death
	}
	else
	{
		lifePoints -= dmg;
	}
}

int Player::getLife()
{
	return lifePoints;
}

/**
 * @param point
 */
void Player::healing(int point) {
	// inutile : pas dans le sujet
}

void Player::attack(Action* act)
{
	for each (Action* var in actionList)
	{
		if (var == act)
		{
			var->execute();
		}
	}
}
