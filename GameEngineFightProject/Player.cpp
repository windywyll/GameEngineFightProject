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
	force = 5;
	name = pName;
	lifePoints = health;
	currentState = new Idle();
	
}

Player::Player(int health, std::string pName, std::vector<Action*> actList)
{
	force = 5;
	lifePoints = health;
	name = pName;
	actionList = actList;
	currentState = new Idle();
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

void Player::setState(STATE st = IDLE)
{
	switch (st)
	{
	case IDLE:currentState = new Idle();
		break;
	case DEATH:currentState = new Death();
		break;
	case STUN:currentState = new Stun();
		break;
	case MOVING:currentState = new Moving();
		break;
	case CROUCH:currentState = new CrouchState();
		break;
	case JUMP:currentState = new Moving();
		break;
	case ATTACK:currentState = new AttackState();
		break;
	case BLOCK:currentState = new BlockState();
		break;
	default:
		currentState = new Idle();
		break;
	}
}


void Player::applyDamage(int dmg) {
	dmg = abs(dmg);
	bool dodge = (currentState->isInState() == CROUCH);
	
	if (dodge && (rand() % 100 + 1 > 60)) dmg = 0;
	if (currentState->isInState() == BLOCK) dmg = 0;
	if (dmg >= lifePoints)
	{
		lifePoints = 0;
		setState(DEATH);
		//Death
	}
	else if(dmg > 0)
	{
		// stuned
		setState(STUN);
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
	setState(currentState->useAction(act, this));
}

void Player::movePosition(Vector3 pos)
{
	position += pos;
}
