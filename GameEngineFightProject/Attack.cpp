#include "Attack.h"
#include <math.h>
#include "Player.h"

Attack::Attack(int dmg, 
	std::string pName,
	float loadingTime,
	float moveDuration,
	float Recovery,
	float stunTime): ActionFinal(pName, loadingTime, moveDuration, Recovery, stunTime)
{
	damage = dmg;
}


Attack::~Attack()
{
}

STATE Attack::execute(Player* p)
{
	float distance = p->getDistanceBetweenPlayer();

	bool isSuccessful = (rand() % 100 + 1) > distance;

	//if (isSuccessful); // notify apply attack dmg

	return ATTACK;
}
