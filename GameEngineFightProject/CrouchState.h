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
	STATE isInState();
	void useAction();
};
#endif

