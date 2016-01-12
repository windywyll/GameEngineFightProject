#ifndef CROUCHSTATE
#define	CROUCHSTATE

#include "PlayerState.h"
class CrouchState :
	public PlayerState
{
public:
	CrouchState();
	~CrouchState();
	void changeState(STATE pState);
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};
#endif

