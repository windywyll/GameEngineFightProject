#include "Attack.h"
#include <math.h>


Attack::Attack(int dmg)
{
	damage = dmg;
}


Attack::~Attack()
{
}

void Attack::execute()
{
	float distance;
	
	// get distance between player
	bool isSuccessful = (rand() % 100 + 1) > distance;

	if (isSuccessful); // apply action


}
