#pragma once
#include "ActionFinal.h"
class Crouch :
	public ActionFinal
{
public:
	Crouch();
	~Crouch();
	void execute(Player* p);
};

