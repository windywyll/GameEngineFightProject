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
	
	Action* getActionInList(Action* act);
	Action* getActionInListByName(STATE act);
	Action* getActionInListByID(int ID);
	bool useAction(Action * act);

	ActionNext(std::string pName);

	ActionNext(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	void pushBackAction(Action* act);
	virtual STATE execute(Player* p = nullptr);
};

#endif //_ACTIONNEXT_H