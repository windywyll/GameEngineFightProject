/**
 * Project Untitled
 */


#ifndef _DEATH_H
#define _DEATH_H

#include "PlayerState.h"


class Death: public PlayerState {
public:
	Death();

	void changeState(STATE p);
	STATE useAction(Action * act, Player * p);
};

#endif //_DEATH_H