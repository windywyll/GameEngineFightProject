#pragma once
#include "PlayerState.h"
class AttackState :
	public PlayerState
{
public:
	AttackState();
	~AttackState();
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};

