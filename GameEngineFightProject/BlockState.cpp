#include "BlockState.h"
#include "Player.h"


BlockState::BlockState()
{
}


BlockState::~BlockState()
{
}

STATE BlockState::useAction(Action * act, Player * p)
{
	bool Stroke = rand() * 100 + 1 >= 99;
	if (Stroke) p->applyDamage(p->lifePoints);

	return BLOCK;
}

STATE BlockState::isInState()
{
	return BLOCK;
}
