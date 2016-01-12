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




STATE Idle::useAction(Action * act, Player * p)
{
	return act->execute(p);
}

STATE Idle::isInState()
{
	return IDLE;
}
