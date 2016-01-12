#pragma once
#include "ActionFinal.h"
class MoveLeft :
	public ActionFinal
{
public:
	MoveLeft(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	~MoveLeft();

	STATE execute(Player * p);
};

