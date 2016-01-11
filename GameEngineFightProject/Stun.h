/**
 * Project Untitled
 */


#ifndef _STUN_H
#define _STUN_H

#include "PlayerState.h"


class Stun: public PlayerState {
	float timeStuned;
	void changeState();
	void useAction(Action* act);
};

#endif //_STUN_H