#ifndef ROUND
#define ROUND

#include <vector>

#include "ObserverDefeat.h"

class RoundMatch
{
	public:
		RoundMatch();
		RoundMatch(int tLimit);
		~RoundMatch();
		void secondPass();
		void registerObserver(ObserverDefeat* obs);
		void unregisterObserver(ObserverDefeat* obs);
		void notifyObserver(Message msg);

	private:
		int timeLimit;
		std::vector<ObserverDefeat*> listObserver;
};
#endif
