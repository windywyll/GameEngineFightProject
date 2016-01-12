#include "Round.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

RoundMatch::RoundMatch() : RoundMatch(99)
{}

RoundMatch::RoundMatch(int tLimit)
{
	timeLimit = tLimit;
}

RoundMatch::~RoundMatch()
{
}

void RoundMatch::secondPass()
{

	cout << endl << endl;
	cout << "---" << endl;
	cout << timeLimit << endl;
	cout << "---" << endl;
	cout << endl << endl;

	--timeLimit;
	if (timeLimit <= 0)
	{
		notifyObserver(Message(typeMSG::endTimer, typeSource::Round));
	}
}

void RoundMatch::notifyObserver(Message msg)
{
	unsigned int i = 0;
	while (i < listObserver.size())
	{
		listObserver[i]->notify(msg);
		i++;
	}
}

void RoundMatch::registerObserver(ObserverDefeat* obs)
{
	listObserver.push_back(obs);
}

void RoundMatch::unregisterObserver(ObserverDefeat* obs)
{
	listObserver.erase(remove(listObserver.begin(), listObserver.end(), obs), listObserver.end());
}