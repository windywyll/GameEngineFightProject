#include "Crouch.h"



Crouch::Crouch()
{
}


Crouch::~Crouch()
{
}

void Crouch::execute(Player* p)
{
	p->setState(CROUCH);
}
