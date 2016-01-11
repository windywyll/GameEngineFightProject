/**
 * Project Untitled
 */

#include <math.h>
#include "Player.h"

/**
 * Player implementation
 */


Player::Player(int health)
{
	lifePoints = health;
}

Player::Player(int health, std::vector<Action*> actList)
{
	lifePoints = health;
	actionList = actList;
	currentState->changeState(IDLE);
}

void Player::registerObserver()
{
}

void Player::unregisterObserver()
{
}

void Player::notifyObserver()
{
}

PlayerState* Player::getCurrentState()
{
	return currentState;
}

void Player::setState(std::string)
{
	//currentState->changeState(state);
}


void Player::applyDamage(int dmg) {
	dmg = abs(dmg);
	bool dodge = currentState;
	if (dodge)
	{
		if (dmg >= lifePoints)
		{
			lifePoints = 0;
			currentState->changeState(DEATH);
			//Death
		}
		else
		{
			// stuned
			currentState->changeState(STUN);
			lifePoints -= dmg;
		}
	}
	
}

int Player::getLife()
{
	return lifePoints;
}


void Player::healing(int point) {
	// inutile : pas dans le sujet
}

void Player::useAction(Action* act)
{
	for each (Action* var in actionList)
	{
		if (var == act)
		{
			var->execute(this);
		}
	}
}

void Player::movePosition(Vector3 pos)
{
	position += pos;
}
