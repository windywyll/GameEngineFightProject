/**
 * Project Untitled
 */


#include "Idle.h"
/**
 * Idle implementation
 */

Idle::Idle()
{
	duration = -1;
}




STATE Idle::useAction(Action * act, Player * p)
{
	return act->execute(p);
}

STATE Idle::isInState()
{
	return IDLE;
}
