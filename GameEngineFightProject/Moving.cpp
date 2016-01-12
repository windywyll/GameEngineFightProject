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

void Moving::changeState()
{

}

STATE Moving::useAction(Action* act, Player* p)
{
	
	return act->execute(p);;
}
