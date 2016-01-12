#include "AttackState.h"



AttackState::AttackState()
{
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
