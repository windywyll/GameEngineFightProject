#ifndef _PLAYER_H
#define _PLAYER_H

#include "Vector3.h"

#include <vector>
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
#include "ObserverDefeat.h"
#include "Message.h"

static Attack* attack = new Attack(50, "punch", 0, 10, 50, 50);
static Jump* jump = new Jump("punch", 0, 50, 5, 0);
static Block* block = new Block("punch", 0, 50, 5, 0);
static Crouch* crouch = new Crouch("punch", 50, 0, 0, 0);
static Move* moveRight = new Move("punch", 0, 0, 0, 0);
static MoveLeft* moveLeft = new MoveLeft("punch", 0, 0, 0, 0);

class Player {
public: 
	Player(int health, std::string pName, int nPl);
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
	int getNumPlayer() { return numPlayer; };

	void registerObserver(ObserverDefeat* obs);
	void unregisterObserver(ObserverDefeat* obs);
	void notifyObserver(Message msg);
	void InputHandler(char in);
	void UpdatePlayer();
	void isJumping(bool val);
	void UpdateTimer();
	bool canTakeInput();
	
	// public pour test seulement
	void useAction(Action* act);
	bool isInCombo();
	ActionNext* CheckCurrentCombo();
	void setState(STATE st= IDLE, float duration = -1);

//private:
	float loadingTime;
	float moveDuration;
	float Recovery;
	std::string name;
	Vector3 position;
	PlayerState* currentState;
	int numPlayer;
	int force;
	int  lifePoints;
	int maxlifePoints;
	std::vector<ObserverDefeat*> listObserver;
	std::vector<Action*> currentCombo;
	std::map<int, ActionNext*> comboList;
	std::map<char, Action*> actionList;
	float distanceBetweenPlayer;
	
};

#endif //_PLAYER_H