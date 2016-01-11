#ifndef TOURNAMENT
#define TOURNAMENT

#include "GameMode.h"

class Tournament : public GameMode
{
	public:
		Tournament();
		~Tournament();
		void selectMode();
};
#endif