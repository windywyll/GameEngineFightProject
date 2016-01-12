#pragma once
#include "PlayerState.h"
class JumpState :
	public PlayerState
{
public:
	JumpState(float time = 50);
	~JumpState();
	float duration;
	STATE useAction(Action * act, Player * p);
	STATE isInState();
};

