#pragma once
#include "ActionFinal.h"
class Block :
	public ActionFinal
{
public:
	Block(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	~Block();

	STATE execute(Player* p);
};

