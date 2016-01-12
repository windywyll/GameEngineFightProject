/**
 * Project Untitled
 */


#ifndef _MOVING_H
#define _MOVING_H

#include "PlayerState.h"


class Moving: public PlayerState {
public:
	Moving();
	float duration;
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};

#endif //_MOVING_H