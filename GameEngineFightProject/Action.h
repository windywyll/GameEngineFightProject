/**
 * Project Untitled
 */

#include <string>
#ifndef _ACTION_H
#define _ACTION_H
class Player;


class Action{
public: 
	
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
	
	virtual void execute(Player* p = nullptr) = 0;
};

#endif //_ACTION_H