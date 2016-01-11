/**
 * Project Untitled
 */


#ifndef _STUN_H
#define _STUN_H

#include "PlayerState.h"


class Stun: public PlayerState {
	float timeStuned;
	void changeState();
};

#endif //_STUN_H