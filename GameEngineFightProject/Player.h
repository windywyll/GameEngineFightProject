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
#include "Action.h"
#ifndef _PLAYER_H
#define _PLAYER_H

class Player {
public: 
	Player(int health);
	Player(int health, std::vector<Action*> actList);

	Vector3 position;
	PlayerState* currentState;
	int  lifePoints;
	std::vector<Action*> actionList;
	
	void registerObserver();
	void unregisterObserver();
	void notifyObserver();
	PlayerState* getCurrentState();
	void setState(std::string state);
	void applyDamage(int dmg);
	int getLife();
	void healing(int point);
	void useAction(Action* act);
	void movePosition(Vector3 pos);
};

#endif //_PLAYER_H