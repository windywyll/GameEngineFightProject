/**
 * Project Untitled
 */


#include "Stun.h"

/**
 * Stun implementation
 */



Stun::Stun(float time)
{
	duration = time;
}

STATE Stun::useAction(Action * act, Player * p)
{
	return STUN;
}

STATE Stun::isInState()
{
	return STUN;
}
