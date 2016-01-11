#include "Crouch.h"



Crouch::Crouch(std::string pName,
	float loadingTime,
	float moveDuration,
	float Recovery,
	float stunTime): ActionFinal(pName, loadingTime, moveDuration, Recovery, stunTime)
{

}


Crouch::~Crouch()
{
}

STATE Crouch::execute(Player* p)
{
	
	return CROUCH;
}
