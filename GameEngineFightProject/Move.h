#pragma once
#include "ActionFinal.h"
class Move :
	public ActionFinal
{
public:
	Move(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	~Move();
	STATE execute(Player * p);
};

