/**
 * Project Untitled
*/
#include "Action.h"
#include "Vector3.h"
#include "Player.h"
/**
 * Action implementation
 */

Action::Action(std::string pName)
{
	name = pName;
	loadingTime = 0;
	moveDuration = 1;
	Recovery = 0;
	stunTime = 0;
}

Action::Action(std::string pName, float pLoadingTime, float pMoveDuration, float pRecovery, float pStunTime)
{
	name = pName;
	loadingTime = pLoadingTime;
	moveDuration = pMoveDuration;
	Recovery = pRecovery;
	stunTime = pStunTime;
}
