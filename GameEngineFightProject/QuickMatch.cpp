#include "QuickMatch.h"

using namespace std;

QuickMatch::QuickMatch()
{
	name = " Quick Match";

	arenaSelected = arenaRange::none;

	listArena = vector<Scene*>();

	listArena.push_back(new Scene("Quarry"));
	listArena.push_back(new Scene("Wasteland"));
}


QuickMatch::~QuickMatch()
{
}

void QuickMatch::reset()
{
	arenaSelected = arenaRange::none;
}

void QuickMatch::selectMode()
{
	cout << endl << "Choose your Arena" << endl << endl;
}

int QuickMatch::getSelectedArena()
{
	return arenaSelected;
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

void QuickMatch::displayArena()
{
	for (unsigned int i = 0; i < listArena.size(); ++i)
	{
		cout << "- " << (i + 1) << " : " << listArena[i]->getName() << endl;
	}

	cout << "- 9 : Exit Quick Match Mode" << endl;

	cout << endl;
}