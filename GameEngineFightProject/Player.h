/**
 * Project Untitled
 */
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
	PlayerState* currentState;
	int  lifePoints;
	std::vector<Action*> actionList;
	
	PlayerState* getCurrentState();
	void setState(PlayerState* state);
	void applyDamage(int dmg);
	int getLife();
	void healing(int point);
	void attack(Action* act);
};

#endif //_PLAYER_H