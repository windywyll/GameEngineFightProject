#pragma once
#include "PlayerState.h"
class BlockState :
	public PlayerState
{
public:
	BlockState();
	~BlockState();

	void changeState();
	STATE useAction(Action * act, Player * p);
};

