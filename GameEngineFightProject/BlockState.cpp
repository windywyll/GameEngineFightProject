#include "BlockState.h"



BlockState::BlockState()
{
}


BlockState::~BlockState()
{
}

void BlockState::changeState()
{
}

STATE BlockState::useAction(Action * act, Player * p)
{
	return BLOCK;
}
