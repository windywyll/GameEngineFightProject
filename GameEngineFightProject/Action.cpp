/**
 * Project Untitled
*/
#include "Action.h"

/**
 * Action implementation
 */


Action::Action(std::string pName, float pLoadingTime, float pMoveDuration, float pRecovery, float pStunTime)
{
	name = pName;
	loadingTime = pLoadingTime;
	moveDuration = pMoveDuration;
	Recovery = pRecovery;
	stunTime = pStunTime;
}
