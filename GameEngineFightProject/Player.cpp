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

void Player::setState(PlayerState* state)
{
	//currentState->changeState(state);
}

/**
 * @param dmg
 */
void Player::applyDamage(int dmg) {
	dmg = abs(dmg);
	if (dmg >= lifePoints)
	{
		lifePoints = 0;
		currentState->changeState(DEATH);
		//Death
	}
	else
	{
		// stuned
		setState(new Stun());
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

void Player::useAction(Action* act)
{
	for each (Action* var in actionList)
	{
		if (var == act)
		{
			var->execute();
		}
	}
}
