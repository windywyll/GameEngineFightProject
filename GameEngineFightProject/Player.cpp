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
	loadingTime = 0;
	moveDuration = 0;
	Recovery = 0;
	numPlayer = nPl;
	force = 5;
	name = pName;
	lifePoints = health;
	maxlifePoints = health;
	currentState = new Idle();
	
	
	ActionNext* act = new ActionNext("SUPER PUNCH !!!!");
	act->pushBackAction(attack);
	act->pushBackAction(attack);
	comboList.insert(std::pair<int, ActionNext*>(1, act));

	ActionNext* act2 = new ActionNext("Flying Punch");
	act2->pushBackAction(jump);
	act2->pushBackAction(attack);
	comboList.insert(std::pair<int, ActionNext*>(2, act2));

	ActionNext* act3 = new ActionNext("Sleeping KICKKKK");
	act3->pushBackAction(crouch);
	act3->pushBackAction(attack);
	comboList.insert(std::pair<int, ActionNext*>(3, act3));

	ActionNext* act4 = new ActionNext("WHAT THE FUCK ?");
	act4->pushBackAction(jump);
	act4->pushBackAction(crouch);
	act4->pushBackAction(moveLeft);
	act4->pushBackAction(attack);
	comboList.insert(std::pair<int, ActionNext*>(4, act4));

	ActionNext* act5 = new ActionNext("HYPER MEGA SUPERRRRR KICK");
	act5->pushBackAction(moveRight);
	act5->pushBackAction(jump);
	act5->pushBackAction(attack);
	comboList.insert(std::pair<int, ActionNext*>(5, act5));
	
	actionList.insert(std::pair<char, Attack*>('a', attack));
	actionList.insert(std::pair<char, Block*>('e', block));
	actionList.insert(std::pair<char, Crouch*>('s', crouch));
	actionList.insert(std::pair<char, Jump*>('z', jump));
	actionList.insert(std::pair<char, Move*>('d', moveRight));
	actionList.insert(std::pair<char, MoveLeft*>('q', moveLeft));
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
	/*delete attack;
	delete jump;
	delete block;
	delete crouch;
	delete moveRight;
	delete moveLeft;*/
	
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
	for (std::map<char, Action*>::iterator it = actionList.begin(); it != actionList.end(); ++it)
	{
		if(it->first == in)
			useAction(it->second);
	}
	
}

void Player::UpdatePlayer()
{
	if (Recovery > 0) Recovery--;
	if (loadingTime > 0) loadingTime--;
	if (moveDuration > 0) moveDuration--;
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
		if (currentState->duration <= 0)isJumping(false);
		UpdateTimer();
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

void Player::isJumping(bool val)
{
	if (val)
	{
		movePosition(Vector3(0, force, 0));
	}
	else
	{
		movePosition(Vector3(0, -force, 0));
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
	if (currentState->isInState() == STUN || currentState->isInState() == DEATH || currentState->isInState() == BLOCK || loadingTime > 0)
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
	currentCombo.push_back(act);
	if (isInCombo() || Recovery == 0)
	{
		loadingTime = act->loadingTime;
		setState(currentState->useAction(act, this));
		moveDuration = act->moveDuration;
		Recovery = act->Recovery;
	}
	
}



bool Player::isInCombo()
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

ActionNext * Player::CheckCurrentCombo()
{
	for (std::map<int, ActionNext*>::iterator it = comboList.begin(); it != comboList.end(); ++it)
	{
		if (it->second->nextAction.size() != currentCombo.size())
			break;
		std::vector<Action*>::iterator iterator = currentCombo.begin();
		for (std::vector<Action*>::iterator it2 = it->second->nextAction.begin(); it2 != it->second->nextAction.end(); ++it2)
		{
			if (*iterator != *it2)
			{
				break;
			}

			if (it2 == (it->second->nextAction.end() - 1))
			{

				return it->second;
			}
			iterator++;
		}
	}
	
	return nullptr;
}

void Player::movePosition(Vector3 pos)
{
	position += pos;
}
