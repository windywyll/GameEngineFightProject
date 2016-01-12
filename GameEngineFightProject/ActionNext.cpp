/**
 * Project Untitled
 */


#include "ActionNext.h"


Action * ActionNext::getActionInList(Action * act)
{
	for each (Action* var in nextAction)
	{
		if (var == act)
		{
			return var;
		}
	}
	return nullptr;
}

Action * ActionNext::getActionInListByName(STATE act)
{
	for each (Action* var in nextAction)
	{
		if (var->execute() == act)
		{
			return var;
		}
	}

	return nullptr;
}

bool ActionNext::useAction(Action * act)
{
	bool found = false;
	 for each (Action* var in nextAction)
	 {
		 if (var == act)
		 {
			 found = true;
			 var->execute();
		 }
	 }
	 return found;
}

ActionNext::ActionNext(std::string pName) :Action(pName)
{

}

 ActionNext::ActionNext(std::string pName, float loadingTime, float moveDuration, float Recovery, float stunTime) :Action(pName, loadingTime, moveDuration, Recovery, stunTime)
 {

 }

 
