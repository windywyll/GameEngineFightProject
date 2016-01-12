#include "JumpState.h"








JumpState::JumpState(float time)
{
	duration = time;
}

JumpState::~JumpState()
{
}

STATE JumpState::useAction(Action * act, Player * p)
{
	return act->execute(p);
}

STATE JumpState::isInState()
{
	return JUMP;
}
