/**
 * Project Untitled
 */
#include "Vector3.h"
#include <vector>
#include "Action.h"
#include "Idle.h"
#include "Moving.h"
#include "Stun.h"
#include "Death.h"
#include "PlayerState.h"
#ifndef _PLAYER_H
#define _PLAYER_H

class Player {
public: 
	Player(int heal);
	Player(int heal, std::vector<Action*> actList);

	Vector3 position;
	PlayerState* currentState;
	int  lifePoints;
	std::vector<Action*> actionList;
	
	void registerObserver();
	void unregisterObserver();
	void notifyObserver();
	PlayerState* getCurrentState();
	void setState(PlayerState* state);
	void applyDamage(int dmg);
	int getLife();
	void healing(int point);
	void useAction(Action* act);
};

#endif //_PLAYER_H