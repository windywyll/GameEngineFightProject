#include "CrouchState.h"



CrouchState::CrouchState()
{
}


CrouchState::~CrouchState()
{
}

STATE CrouchState::useAction(Action * act, Player * p)
{
	return act->execute(p);
}

STATE CrouchState::isInState()
{
	return CROUCH;
}