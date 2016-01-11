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
	currentState->changeState(PLAYER::IDLE);
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
	bool dodge = currentState == new CrouchState();
	if (dodge && (rand() % 100 + 1 > 60)) dmg = 0;
	
	if (dmg >= lifePoints)
	{
		lifePoints = 0;
		currentState->changeState(PLAYER::DEATH);
		//Death
	}
	else if(dmg > 0)
	{
		// stuned
		currentState->changeState(PLAYER::STUN);
		lifePoints -= dmg;
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
