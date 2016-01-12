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
	p->movePosition(Vector3(p->direction * 5,0,0));
	return MOVING;
}