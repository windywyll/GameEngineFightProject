#include "Jump.h"
#include <Windows.h>
#include "Player.h"

Jump::Jump(std::string pName,
	float loadingTime,
	float moveDuration,
	float Recovery,
	float stunTime):ActionFinal(pName,loadingTime,moveDuration,Recovery,stunTime)
{
}


Jump::~Jump()
{
}

STATE Jump::execute(Player* p)
{
	if (p != nullptr)
	{
		p->Recovery = Recovery;
		p->isJumping(true);
	}
	
	
	return JUMP;
}
