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
};

#endif //_MOVING_H