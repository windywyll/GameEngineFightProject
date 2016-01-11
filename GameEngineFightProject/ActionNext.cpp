/**
 * Project Untitled
 */


#include "ActionNext.h"

/**
 * ActionNext implementation
 */



	 Action * ActionNext::getAction(Action * act)
 {
	 for each (Action* var in nextAction)
	 {
		 if (var == act)
		 {
			 var->execute();
		 }
	 }

	 return nullptr;
 }

 ActionNext::ActionNext(std::string pName, float loadingTime, float moveDuration, float Recovery, float stunTime) :Action(pName, loadingTime, moveDuration, Recovery, stunTime)
 {

 }

 
