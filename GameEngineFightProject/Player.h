/**
 * Project Untitled
 */
#include "Vector3.h"
#include <vector>
#include "Idle.h"
#include "Moving.h"
#include "Stun.h"
#include "Death.h"
#include "PlayerState.h"
#include "CrouchState.h"
#include "Action.h"
#ifndef _PLAYER_H
#define _PLAYER_H

class Player {
public: 
	Player(int health, std::string pName);
	Player(int health, std::string pName, std::vector<Action*> actList);
	~Player();
	std::string name;
	Vector3 position;
	PlayerState* currentState;
	int  lifePoints;
	std::vector<Action*> actionList;
	float distanceBetweenPlayer;
	
	float getDistanceBetweenPlayer();
	void setDistanceBetweenPlayer(float dist);
	void registerObserver();
	void unregisterObserver();
	void notifyObserver();
	PlayerState* getCurrentState();
	void setState(STATE state);
	void applyDamage(int dmg);
	int getLife();
	void healing(int point);
	void useAction(Action* act);
	void movePosition(Vector3 pos);
};

#endif //_PLAYER_H