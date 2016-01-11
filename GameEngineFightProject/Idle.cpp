/**
 * Project Untitled
 */


#include "Idle.h"
/**
 * Idle implementation
 */

Idle::Idle()
{
}


void Idle::changeState(STATE pState)
{
}

STATE Idle::useAction(Action * act, Player * p)
{
	return act->execute(p);;
}

STATE Idle::isInState()
{
	return IDLE;
}
