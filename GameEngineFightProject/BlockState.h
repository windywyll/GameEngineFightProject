#pragma once
#include "PlayerState.h"
class BlockState :
	public PlayerState
{
public:
	BlockState();
	~BlockState();

	float duration;
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};

