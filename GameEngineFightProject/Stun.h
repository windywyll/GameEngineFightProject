/**
 * Project Untitled
 */


#ifndef _STUN_H
#define _STUN_H

#include "PlayerState.h"


class Stun: public PlayerState {
	float timeStuned;
	STATE useAction(Action* act, Player* p = nullptr);
	STATE isInState();
};

#endif //_STUN_H