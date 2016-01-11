/**
 * Project Untitled
 */


#ifndef _MOVING_H
#define _MOVING_H

#include "PlayerState.h"


class Moving: public PlayerState {
public:
	Moving();
	void changeState();
	STATE useAction(Action * act, Player * p);
	
};

#endif //_MOVING_H