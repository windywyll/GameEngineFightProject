#ifndef OBSERVERDEFEAT
#define OBSERVERDEFEAT

#include "Message.h"

class ObserverDefeat
{
	public:
		ObserverDefeat();
		~ObserverDefeat();
		virtual void notify(Message msg) = 0;
};
#endif
