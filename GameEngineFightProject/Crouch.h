#pragma once
#include "ActionFinal.h"
class Crouch :
	public ActionFinal
{
public:
	Crouch(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	~Crouch();
	STATE execute(Player* p);
};

