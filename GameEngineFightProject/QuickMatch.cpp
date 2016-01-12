#include "QuickMatch.h"

using namespace std;

QuickMatch::QuickMatch()
{
	name = "Quick Match";

	arenaSelected = arenaRange::none;

	listArena = vector<Scene*>();

	listArena.push_back(new Scene("Quarry"));
	listArena.push_back(new Scene("Wasteland"));
}


QuickMatch::~QuickMatch()
{
	while (listArena.size() > 0)
	{
		delete listArena.back();
		listArena.pop_back();
	}
}

void QuickMatch::reset()
{
	arenaSelected = arenaRange::none;
}

void QuickMatch::resetOptions()
{
	listArena[arenaSelected]->reset();
}

void QuickMatch::resetMatch()
{
	listArena[arenaSelected]->resetMatch();
}

void QuickMatch::selectMode()
{
	cout << endl << "Choose your Arena" << endl << endl;
}

int QuickMatch::getSelectedArena()
{
	return arenaSelected;
}

int QuickMatch::getOptionSelected()
{
	return listArena[arenaSelected]->getOptionSelected();
}

bool QuickMatch::getOptionConfirmed()
{
	return listArena[arenaSelected]->getOptionConfirmed();
}

bool QuickMatch::getOptionsCancel()
{
	return listArena[arenaSelected]->getOptionCancel();
}

bool QuickMatch::selectArena(int selectNum)
{
	bool goodSelection = true;

	switch (selectNum)
	{
		case arenaRange::quarry:
			arenaSelected = arenaRange::quarry;
			break;
		case arenaRange::wasteland:
			arenaSelected = arenaRange::wasteland;
			break;
		case arenaRange::exit:
			arenaSelected = arenaRange::exit;
			break;
		default:
			goodSelection = false;
			cout << endl << "error bad selection" << endl << endl;
			break;
	}

	return goodSelection;
}

void QuickMatch::selectOptions(int selectNum)
{
	return listArena[arenaSelected]->selectOptions(selectNum);
}

void QuickMatch::setSelectedOption(int option, int value)
{
	listArena[arenaSelected]->setSelectedOption(option, value);
}

void QuickMatch::displayArena()
{
	for (unsigned int i = 0; i < listArena.size(); ++i)
	{
		cout << "- " << (i + 1) << " : " << listArena[i]->getName() << endl;
	}

	cout << "- 9 : Return to Game Mode Section" << endl;

	cout << endl;
}

void QuickMatch::displayOptions()
{
	listArena[arenaSelected]->displayOption();
}

void QuickMatch::launchNewRound()
{
	listArena[arenaSelected]->launchNewRound();
}

void QuickMatch::secondPass()
{
	listArena[arenaSelected]->secondPass();
}

void QuickMatch::registerObserver(ObserverDefeat* obs)
{
	listArena[arenaSelected]->registerObserver(obs);
}

void QuickMatch::unregisterObserver(ObserverDefeat* obs)
{
	listArena[arenaSelected]->unregisterObserver(obs);
}

int QuickMatch::getNumberRoundToWin()
{
	return listArena[arenaSelected]->getNumberRoundToWin();
}