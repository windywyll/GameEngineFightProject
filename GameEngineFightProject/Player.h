#ifndef _PLAYER_H
#define _PLAYER_H

#include "Vector3.h"
#include <vector>
#include "Idle.h"
#include "Moving.h"
#include "Stun.h"
#include "AttackState.h"
#include "BlockState.h"
#include "Death.h"
#include "PlayerState.h"
#include "CrouchState.h"
#include "Action.h"

class Player {
public: 
	Player(int health, std::string pName);
	//Player(int health, std::string pName, std::vector<Action*> actList);
	~Player();
	
	void setDistanceBetweenPlayer(float dist);
	void applyDamage(int dmg, float timeStun = 0);
	void healing(int point);
	void movePosition(Vector3 pos);
	
	float getDistanceBetweenPlayer();
	STATE getState();
	PlayerState* getCurrentState();
	int getLife();
	Vector3 getPosition();
	int getForce();
	std::string getName();

	void registerObserver();
	void unregisterObserver();
	void notifyObserver();
	void UpdatePlayer();
	
	// public pour test seulement
	void useAction(Action* act); 
	void setState(STATE st= IDLE, float duration = -1);

private:
	std::string name;
	Vector3 position;
	PlayerState* currentState;
	int force;
	int  lifePoints;
	std::vector<Action*> actionList;
	float distanceBetweenPlayer;
	
};

#endif //_PLAYER_H