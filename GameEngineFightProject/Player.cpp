/**
 * Project Untitled
 */

#include <math.h>
#include "Player.h"
#include <Windows.h>
#include <algorithm>
/**
 * Player implementation
 */


Player::Player(int health, std::string pName, int nPl)
{
	Recovery = 0;
	numPlayer = nPl;
	force = 5;
	name = pName;
	lifePoints = health;
	maxlifePoints = health;
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
	delete currentState;
	for (std::map<char, Action*>::iterator it = actionList.begin(); it != actionList.end(); ++it)
	{
		delete it->second;
	}
	for (std::map<int, ActionNext*>::iterator it = comboList.begin(); it != comboList.end(); ++it)
	{
		delete it->second;
	}
	
	comboList.clear();
	actionList.clear();
	clearCurrentCombo();
	
}

void Player::clearCurrentCombo()
{
	currentCombo.clear();
}

void Player::Initial()	// reset le player à l'état initial
{
	clearCurrentCombo();
	setState(IDLE);
	lifePoints = maxlifePoints;
}

float Player::getDistanceBetweenPlayer()
{
	return distanceBetweenPlayer;
}

void Player::setDistanceBetweenPlayer(float dist)
{
	distanceBetweenPlayer = dist;
}

void Player::notifyObserver(Message msg)
{
	unsigned int i = 0;
	while (i < listObserver.size())
	{
		listObserver[i]->notify(msg);
		i++;
	}
}

void Player::registerObserver(ObserverDefeat* obs)
{
	listObserver.push_back(obs);
}

void Player::unregisterObserver(ObserverDefeat* obs)
{
	listObserver.erase(remove(listObserver.begin(), listObserver.end(), obs), listObserver.end());
}

void Player::InputHandler(char in)
{
	useAction(actionList.find(in)->second);
}

void Player::UpdatePlayer()
{
	if (Recovery > 0) Recovery--;

	switch (currentState->isInState())
	{
	case IDLE:
		break;
	case DEATH:
		break;
	case STUN:
		UpdateTimer();
		break;
	case MOVING:
		break;
	case CROUCH:
		UpdateTimer();
		break;
	case JUMP:
		break;
	case ATTACK:
		break;
	case BLOCK:
		UpdateTimer();
		break;
	default:
		break;
	}
}

void Player::UpdateTimer()
{
	if (currentState->duration <= 0) {
		setState();
	}
	else {
		currentState->duration--;
	}
}

bool Player::canTakeInput()
{
	if (currentState->isInState() == STUN || currentState->isInState() == DEATH || currentState->isInState() == BLOCK)
		return false;
	return true;
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
	case BLOCK:currentState = new BlockState(duration);
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

		Message msg;

		if(numPlayer == 1)
			msg = Message(typeMSG::death, typeSource::p1);

		if(numPlayer == 2)
			msg = Message(typeMSG::death, typeSource::p2);

		notifyObserver(msg);
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
	currentCombo[currentCombo.size()] = act;
	if (CheckCombo() || Recovery == 0)
	{
		setState(currentState->useAction(act, this));
		Recovery = act->Recovery;
	}
	
}

bool Player::CheckCombo()
{
	
	bool inCombo = false;
	int cmpt = 0;

	for (std::map<int, ActionNext*>::iterator it = comboList.begin(); it != comboList.end(); ++it)
	{
		for (int i = 0; i < currentCombo.size(); i++)
		{
			if (it->second->getActionInListByID(i) != currentCombo.at(i))
			{
				cmpt++;
				break;
			}
		}
	}

	if (cmpt < comboList.size())
		inCombo = true;

	return inCombo;
}

void Player::movePosition(Vector3 pos)
{
	position += pos;
}
