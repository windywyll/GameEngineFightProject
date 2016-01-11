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
	virtual STATE execute(Player* p = nullptr)=0;
};

#endif //_ACTIONFINAL_H