#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	run = true;
	modeSelected = ModeRange::None;

	inputHandler = InputManager::getInstance();

	listPlayer = vector<Player*>();
	listPlayer.push_back(new Player(200));
	listPlayer.push_back(new Player(200));

	listGameMode = vector<GameMode*>();
	listGameMode.push_back(new Adventure());
	listGameMode.push_back(new Tournament());
	listGameMode.push_back(new QuickMatch());
}


GameManager::~GameManager()
{
	while (listPlayer.size() > 0)
	{
		delete listPlayer.back();
		listPlayer.pop_back();
	}

	while (listGameMode.size() > 0)
	{
		delete listGameMode.back();
		listGameMode.pop_back();
	}
}

void GameManager::notify()
{

}

void GameManager::startGame()
{
	while (run == true)
	{
		while (modeSelected == ModeRange::None)
		{
			gameModeChoice();
		}

		while (modeSelected == ModeRange::Aventure)
		{
			adventureSelected();
		}

		while (modeSelected == ModeRange::Tournoi)
		{
			tournamentSelected();
		}

		while (modeSelected == ModeRange::partieRapide)
		{
			quickMatchSelected();
		}
	}
}

void GameManager::gameModeChoice()
{
	cout << endl << "Choose your Game mode:" << endl << endl;
	for (unsigned int i = 0; i < listGameMode.size(); ++i)
	{
		cout << "- " << (i+1) << " : " << listGameMode[i]->getName() << endl;
	}

	cout << "- 9 : Exit Game" << endl;

	cout << endl;

	switch (atoi(inputHandler->handleInput().c_str()) - 1)
	{
		case ModeRange::Aventure:
			modeSelected = ModeRange::Aventure;
			break;
		case ModeRange::Tournoi:
			modeSelected = ModeRange::Tournoi;
			break;
		case ModeRange::partieRapide:
			modeSelected = ModeRange::partieRapide;
			break;
		case ModeRange::Exit:
			modeSelected = ModeRange::Exit;
			run = false;
			break;
		default:
			cout << endl << "error bad selection" << endl << endl;
			break;
	}
}

void GameManager::adventureSelected()
{
	listGameMode[modeSelected]->selectMode();
	modeSelected = ModeRange::None;
}

void GameManager::tournamentSelected()
{
	listGameMode[modeSelected]->selectMode();
	modeSelected = ModeRange::None;
}

void GameManager::quickMatchSelected()
{
	listGameMode[modeSelected]->selectMode();
	arenaChoice();
}

void GameManager::arenaChoice()
{
	bool arenaChoice = false;
	while (!arenaChoice)
	{
		((QuickMatch*)listGameMode[modeSelected])->displayArena();
		arenaChoice = ((QuickMatch*)listGameMode[modeSelected])->selectArena(atoi(inputHandler->handleInput().c_str()) - 1);
	}

	if (((QuickMatch*)listGameMode[modeSelected])->getSelectedArena() == 8)
	{
		((QuickMatch*)listGameMode[modeSelected])->reset();
		modeSelected = ModeRange::None;
	}
	else
	{
		optionChoice();
	}
}

void GameManager::optionChoice()
{
	bool optionsConfirmed = false;
	while (!optionsConfirmed)
	{
		((QuickMatch*)listGameMode[modeSelected])->displayOptions();
		((QuickMatch*)listGameMode[modeSelected])->selectOptions(atoi(inputHandler->handleInput().c_str()) - 1);

		if (((QuickMatch*)listGameMode[modeSelected])->getOptionConfirmed() || ((QuickMatch*)listGameMode[modeSelected])->getOptionsCancel())
		{
			optionsConfirmed = true;
		}
		else
		{
			cout << endl << "Enter Your Value: " << endl;
			((QuickMatch*)listGameMode[modeSelected])->setSelectedOption(((QuickMatch*)listGameMode[modeSelected])->getOptionSelected(), atoi(inputHandler->handleInput().c_str()));
		}
	}

	if (((QuickMatch*)listGameMode[modeSelected])->getOptionsCancel())
	{
		((QuickMatch*)listGameMode[modeSelected])->resetOptions();
		arenaChoice();
	}

	if(((QuickMatch*)listGameMode[modeSelected])->getOptionConfirmed())
	{
		cout << endl << "The Match Begins" << endl << endl;
		modeSelected = ModeRange::None;
		run = false;
		system("PAUSE");
	}
}