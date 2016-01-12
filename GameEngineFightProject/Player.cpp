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
	float a = 0;
	
	
	actionList.insert(std::pair<char, Attack*>('a', new Attack(50, "coup de pied", a, a, a, 30)));
	actionList.insert(std::pair<char, Block*>('e',new Block("block", a, a, a, a)));
	actionList.insert(std::pair<char, Crouch*>('s', new Crouch("Crouch", a, a, a, a)));
	actionList.insert(std::pair<char, Jump*>('z', new Jump("Jump", a, a, a, a)));
	actionList.insert(std::pair<char, Move*>('d', new Move("Move Right", a, a, a, a)));
	actionList.insert(std::pair<char, MoveLeft*>('q', new MoveLeft("block", a, a, a, a)));
}

/*Player::Player(int health, std::string pName, std::vector<Action*> actList)
{
	force = 5;
	lifePoints = health;
	name = pName;
	actionList = actList;
	currentState = new Idle();
}*/

Player::~Player()
{
	for (std::map<char, Action*>::iterator it = actionList.begin(); it != actionList.end(); ++it)
	{
		delete it->second;
	}
	actionList.clear();
	delete currentState;
	delete &actionList;
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

void Player::InputHandler(std::string in)
{
	if(actionList[in.front] != nullptr)
	useAction(actionList[in.front]);
}

void Player::UpdatePlayer()
{
	switch (currentState->isInState())
	{
	case IDLE:
		break;
	case DEATH:
		break;
	case STUN:
		if (currentState->duration <= 0){
			setState();
		}else{
			currentState->duration--;
		}break;
	case MOVING:
		break;
	case CROUCH:
		if (currentState->duration <= 0){
			setState();
		}else{
			currentState->duration--;
		}break;
	case JUMP:
		break;
	case ATTACK:
		break;
	case BLOCK:
		break;
	default:
		break;
	}
}

PlayerState* Player::getCurrentState()
{
	return currentState;
}

void Player::setState(STATE st, float duration)
{
	delete currentState;
	switch (st)
	{
	case IDLE:currentState = new Idle();
		break;
	case DEATH:currentState = new Death();
		break;
	case STUN:currentState = new Stun(duration);
		break;
	case MOVING:currentState = new Moving();
		break;
	case CROUCH:currentState = new CrouchState(duration);
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


void Player::applyDamage(int dmg, float timeStun) {
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
		setState(STUN, timeStun);
		lifePoints -= dmg;
	}	
}

int Player::getLife()
{
	return lifePoints;
}

Vector3 Player::getPosition()
{
	return position;
}

int Player::getForce()
{
	return force;
}

std::string Player::getName()
{
	return name;
}

STATE Player::getState()
{

	return currentState->isInState();
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
