#include "Scene.h"

#include <iostream>
#include <stdio.h>

using namespace std;

Scene::Scene() : Scene("default")
{ }

Scene::Scene(string n)
{
	name = n;
	optionSelected = optionRange::none;

	listRound = vector<RoundMatch*>();

	numberRoundToWin = 2;
	limitTimeRound = 99;
}


Scene::~Scene()
{
	while (listRound.size() > 0)
	{
		delete listRound.back();
		listRound.pop_back();
	}
}

void Scene::reset()
{
	while (listRound.size() > 0)
	{
		delete listRound.back();
		listRound.pop_back();
	}

	listRound = vector<RoundMatch*>();
	numberRoundToWin = 2;
	limitTimeRound = 99;
}

void Scene::resetMatch()
{
	while (listRound.size() > 0)
	{
		delete listRound.back();
		listRound.pop_back();
	}

	listRound = vector<RoundMatch*>();
}

string Scene::getName()
{
	return name;
}

void Scene::displayOption()
{
	cout << endl << "Options : " << endl;
	cout << endl;
	cout << "- 1 : Time Limit : " << limitTimeRound << endl;
	cout << "- 2 : Number of Rounds to Win : " << numberRoundToWin << endl;
	cout << "- 3 : Confirm options" << endl;
	cout << "- 9 : Return to Arena Selection" << endl << endl;
}

int Scene::getOptionSelected()
{
	return optionSelected;
}

bool Scene::getOptionConfirmed()
{
	return optionSelected == optionRange::accept;
}

bool Scene::getOptionCancel()
{
	return optionSelected == optionRange::exit;
}

void Scene::setSelectedOption(int option, int value)
{
	if (value > 0)
	{
		switch (option)
		{
		case optionRange::timeLimit:
			optionSelected = optionRange::none;
			limitTimeRound = value;
			cout << "Time limit changed." << endl << endl;
			break;
		case optionRange::roundToWin:
			optionSelected = optionRange::none;
			numberRoundToWin = value;
			cout << "Number of round to win changed." << endl << endl;
			break;
		default:
			cout << "Welcome to the dark side, something went awfully wrong but at least we have cookies." << endl << endl;
			break;
		}
	}
	else
	{
		cout << "Bad value, please input a value above 0." << endl << endl;
	}
}

void Scene::selectOptions(int selectNum)
{
	switch (selectNum)
	{
	case optionRange::timeLimit:
		optionSelected = optionRange::timeLimit;
		break;
	case optionRange::roundToWin:
		optionSelected = optionRange::roundToWin;
		break;
	case optionRange::accept:
		optionSelected = optionRange::accept;
		break;
	case optionRange::exit:
		optionSelected = optionRange::exit;
		break;
	default:
		cout << endl << "error bad selection" << endl << endl;
		break;
	}
}

void Scene::launchNewRound()
{
	listRound.push_back(new RoundMatch(limitTimeRound));
}

void Scene::secondPass()
{
	listRound.back()->secondPass();
}

void Scene::registerObserver(ObserverDefeat* obs)
{
	listRound.back()->registerObserver(obs);
}

void Scene::unregisterObserver(ObserverDefeat* obs)
{
	listRound.back()->unregisterObserver(obs);
}

int Scene::getNumberRoundToWin()
{
	return numberRoundToWin;
}