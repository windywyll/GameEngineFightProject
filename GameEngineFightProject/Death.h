/**
 * Project Untitled
 */


#ifndef _DEATH_H
#define _DEATH_H

#include "PlayerState.h"


class Death: public PlayerState {
public:
	Death();

	void changeState(PLAYERSTATE p);
};

#endif //_DEATH_H