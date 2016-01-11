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
	CROUCH,

};

class PlayerState {
public: 
	
	virtual void changeState(PLAYERSTATE pState)= 0;
};

#endif //_PLAYERSTATE_H