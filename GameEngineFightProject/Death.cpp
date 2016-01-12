/**
 * Project Untitled
 */

#include "Idle.h"
#include "Death.h"
/**
 * Death implementation
 */

Death::Death()
{
	duration = -1;
}


STATE Death::useAction(Action * act, Player * p)
{

	return DEATH;
}

STATE Death::isInState()
{
	return DEATH;
}


