#pragma once
#include "ActionFinal.h"

class Jump :
	public ActionFinal
{
public:
	Jump(std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	~Jump();

	void execute(Player* p);
};

