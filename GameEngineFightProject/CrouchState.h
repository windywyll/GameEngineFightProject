#ifndef CROUCHSTATE
#define	CROUCHSTATE

#include "PlayerState.h"
class CrouchState :
	public PlayerState
{
public:
	CrouchState(float time = -1);
	~CrouchState();
	float duration;
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};
#endif

