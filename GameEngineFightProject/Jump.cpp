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
	p->movePosition(Vector3(0,5,0));
	
	return MOVING;
}
