#pragma once
#include "ActionFinal.h"
class Attack :
	public ActionFinal
{
public:
	Attack(int dmg);
	~Attack();
	int damage;
	void execute();
};

