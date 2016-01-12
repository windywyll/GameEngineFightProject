#include "Move.h"
#include "Player.h"


Move::Move(std::string pName,
	float loadingTime,
	float moveDuration,
	float Recovery,
	float stunTime) : ActionFinal(pName, loadingTime, moveDuration, Recovery, stunTime)
{
}



Move::~Move()
{
}

STATE Move::execute(Player * p)
{
	if (p != nullptr)
	p->movePosition(Vector3(p->force ,0,0));
	return MOVING;
}