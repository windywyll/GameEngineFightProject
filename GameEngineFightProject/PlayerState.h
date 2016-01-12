/**
 * Project Untitled
 */
#include "ENUMSTATE.h"
#include "Action.h"
#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H



class PlayerState {
public: 
	
	virtual STATE useAction(Action* act, Player * p = nullptr) = 0;
	virtual STATE isInState() = 0;
};

#endif //_PLAYERSTATE_H