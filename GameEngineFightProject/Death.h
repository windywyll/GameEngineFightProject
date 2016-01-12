/**
 * Project Untitled
 */


#ifndef _DEATH_H
#define _DEATH_H

#include "PlayerState.h"


class Death: public PlayerState {
public:
	Death();
	float duration;
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};

#endif //_DEATH_H