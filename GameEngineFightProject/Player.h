#ifndef _PLAYER_H
#define _PLAYER_H

#include "Vector3.h"

#include <map>
#include "Idle.h"
#include "Moving.h"
#include "Stun.h"
#include "Block.h"
#include "AttackState.h"
#include "BlockState.h"
#include "Death.h"
#include "Attack.h"
#include "PlayerState.h"
#include "CrouchState.h"
#include "Action.h"
#include "Crouch.h"
#include "Jump.h"
#include "Move.h"
#include "MoveLeft.h"
#include "ActionNext.h"

class Player {
public: 
	Player(int health, std::string pName);
	//Player(int health, std::string pName, std::vector<Action*> actList);
	~Player();

	void clearCurrentCombo();

	void Initial();	// reset le player à l'état initial
	
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
	void InputHandler(std::string in);
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
	int maxlifePoints;
	std::map<int, Action*> currentCombo;
	std::map<int, ActionNext*> comboList;
	std::map<char, Action*> actionList;
	float distanceBetweenPlayer;
	
};

#endif //_PLAYER_H