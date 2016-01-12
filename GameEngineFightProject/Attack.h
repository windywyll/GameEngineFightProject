#pragma once
#include "ActionFinal.h"
class Attack :
	public ActionFinal
{
public:
	Attack(int dmg, std::string pName,
		float loadingTime,
		float moveDuration,
		float Recovery,
		float stunTime);
	~Attack();
	STATE execute(Player * p);
	int damage;
};

