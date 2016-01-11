/**
 * Project Untitled
 */


#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H


static enum PLAYERSTATE
{
	IDLE,
	DEATH,
	STUN,
	MOVING,
};

class PlayerState {
public: 
	
	virtual void changeState()= 0;
};

#endif //_PLAYERSTATE_H