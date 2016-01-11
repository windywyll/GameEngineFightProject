/**
 * Project Untitled
 */

#include <math.h>
#include "Player.h"
#include <Windows.h>
/**
 * Player implementation
 */


Player::Player(int health, std::string pName)
{
	name = pName;
	lifePoints = health;
	currentState = new Idle();
	
}

Player::Player(int health, std::string pName, std::vector<Action*> actList)
{
	lifePoints = health;
	name = pName;
	actionList = actList;
	currentState->changeState(IDLE);
}

Player::~Player()
{
	delete currentState;
}

float Player::getDistanceBetweenPlayer()
{
	return distanceBetweenPlayer;
}

void Player::setDistanceBetweenPlayer(float dist)
{
	distanceBetweenPlayer = dist;
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

void Player::setState(STATE st)
{
	currentState->changeState(st);
}


void Player::applyDamage(int dmg) {
	dmg = abs(dmg);
	bool dodge = (currentState->isInState() == CROUCH);
	if (dodge && (rand() % 100 + 1 > 60)) dmg = 0;
	
	if (dmg >= lifePoints)
	{
		lifePoints = 0;
		currentState->changeState(DEATH);
		//Death
	}
	else if(dmg > 0)
	{
		// stuned
		currentState->changeState(STUN);
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
	currentState->changeState(currentState->useAction(act, this));
}

/*void Player::handleState(STATE st)
{
	currentState->changeState(st);
	switch (st)
	{
	case IDLE:
		break;
	case DEATH:Death();
		break;
	case STUN:;
		break;
	case MOVING:;
		break;
	case CROUCH:;
		break;
	case JUMP:Jump();
		break;
	case ATTACK:Attack();
		break;
	default:;
	};
}*/


void Player::movePosition(Vector3 pos)
{
	position += pos;
}
