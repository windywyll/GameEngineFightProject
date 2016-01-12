/**
 * Project Untitled
 */


#ifndef _IDLE_H
#define _IDLE_H

#include "PlayerState.h"


class Idle: public PlayerState {
public:
	Idle();
	float duration;
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};

#endif //_IDLE_H