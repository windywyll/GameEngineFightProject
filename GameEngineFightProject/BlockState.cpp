#include "BlockState.h"
#include "Player.h"


BlockState::BlockState(float timer)
{
	duration = timer;
}


BlockState::~BlockState()
{
}

STATE BlockState::useAction(Action * act, Player * p)
{
	bool Stroke = rand() * 100 + 1 >= 99;
	if (Stroke) p->applyDamage(p->getLife());

	return BLOCK;
}

STATE BlockState::isInState()
{
	return BLOCK;
}
