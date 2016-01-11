#pragma once
#include "PlayerState.h"
class CrouchState :
	public PlayerState
{
public:
	CrouchState();
	~CrouchState();
	void changeState(PLAYERSTATE pState);
};

