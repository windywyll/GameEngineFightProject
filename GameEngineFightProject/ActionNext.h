/**
 * Project Untitled
 */


#ifndef _ACTIONNEXT_H
#define _ACTIONNEXT_H
#include <vector>
#include "Action.h"


class ActionNext: public Action {
public:
	std::vector<Action*> nextAction;
	
	Action* getAction(Action* act);

	ActionNext(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	virtual void execute(Player* p = nullptr)=0;
};

#endif //_ACTIONNEXT_H