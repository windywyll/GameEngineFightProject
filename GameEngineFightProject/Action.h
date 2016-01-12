/**
 * Project Untitled
 */

#include "ENUMSTATE.h"
#include <string>
#ifndef _ACTION_H
#define _ACTION_H
class Player;


class Action{
public: 
	
	Action(std::string pName);

	Action(std::string pName,
	float loadingTime,
	float moveDuration,
	float Recovery,
	float stunTime);

	std::string name;
	float loadingTime;
	float moveDuration;
	float Recovery;
	float stunTime;
	
	virtual STATE execute(Player* p = nullptr) = 0;
};

#endif //_ACTION_H