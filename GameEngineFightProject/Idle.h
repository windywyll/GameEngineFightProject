/**
 * Project Untitled
 */


#ifndef _IDLE_H
#define _IDLE_H

#include "PlayerState.h"


class Idle: public PlayerState {
public:
	Idle();

	void changeState();
};

#endif //_IDLE_H