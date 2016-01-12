#include "Block.h"
#include "Player.h"


Block::Block(std::string pName,
	float loadingTime,
	float moveDuration,
	float Recovery,
	float stunTime): ActionFinal(pName,loadingTime,moveDuration, Recovery,stunTime)
{
}


/*Block::Block(std::string pName, float loadingTime, float moveDuration, float Recovery, float stunTime): ActionFinal(pName, loadingTime, moveDuration, Recovery, stunTime)
{
}*/

Block::~Block()
{
}

STATE Block::execute(Player * p)
{
	return BLOCK;
}
