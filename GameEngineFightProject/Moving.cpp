/**
 * Project Untitled
 */


#include "Moving.h"
/**
 * Moving implementation
 */

Moving::Moving()
{
}

STATE Moving::useAction(Action* act, Player* p)
{
	
	return act->execute(p);;
}

STATE Moving::isInState()
{
	return MOVING;
}
