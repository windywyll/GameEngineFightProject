#include "AttackState.h"



AttackState::AttackState()
{
	duration = -1;
}


AttackState::~AttackState()
{
}

STATE AttackState::useAction(Action * act, Player * p)
{
	

	return BLOCK;
}

STATE AttackState::isInState()
{
	return ATTACK;
}
