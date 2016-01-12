#include "MoveLeft.h"
#include "Player.h"


MoveLeft::MoveLeft(std::string pName, float loadingTime, float moveDuration, float Recovery, float stunTime) : ActionFinal(pName, loadingTime, moveDuration, Recovery, stunTime)
{
}

MoveLeft::~MoveLeft()
{
}

STATE MoveLeft::execute(Player * p)
{
	if(p != nullptr)
	p->movePosition(Vector3(-1*p->force, 0, 0));
	return MOVING;
}
