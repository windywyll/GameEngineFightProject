/**
 * Project Untitled
 */


#ifndef _ACTIONFINAL_H
#define _ACTIONFINAL_H

#include "Action.h"


class ActionFinal: public Action {
public:

	ActionFinal(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	virtual void execute(Player* p)=0;
};

#endif //_ACTIONFINAL_H