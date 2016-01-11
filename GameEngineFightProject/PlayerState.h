/**
 * Project Untitled
 */


#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H

namespace PLAYER
{
	enum STATE
	{
		IDLE,
		DEATH,
		STUN,
		MOVING,
		CROUCH
	};
}

class PlayerState {
public: 
	
	virtual void changeState(PLAYER::STATE pState)= 0;
};

#endif //_PLAYERSTATE_H