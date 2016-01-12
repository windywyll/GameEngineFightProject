#include "GameManager.h"

#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

GameManager::GameManager()
{
	run = true;

	returnToArenaSelection = false;
	returnToOptionSelection = false;
	modeSelected = ModeRange::None;

	inputHandler = InputManager::getInstance();

	listPlayer = vector<Player*>();
	listPlayer.push_back(new Player(200, "william"));
	listPlayer.push_back(new Player(200, "jordan"));

	unsigned int i = 0;

	while (i < listPlayer.size())
	{
		listPlayer[i]->registerObserver();
		i++;
	}

	listGameMode = vector<GameMode*>();
	listGameMode.push_back(new Adventure());
	listGameMode.push_back(new Tournament());
	listGameMode.push_back(new QuickMatch());
}


GameManager::~GameManager()
{
	while (listPlayer.size() > 0)
	{
		listPlayer.back()->unregisterObserver();
		delete listPlayer.back();
		listPlayer.pop_back();
	}

	while (listGameMode.size() > 0)
	{
		delete listGameMode.back();
		listGameMode.pop_back();
	}
}

void GameManager::notify(Message msg)
{
	switch (msg.getMsg())
	{
		case typeMSG::endTimer:
		{
			cout << endl << endl << "----------------------------------------------------------------" << endl;
			if (listPlayer[0]->getLife() > listPlayer[1]->getLife())
			{
				++numVictoryP1;
				//cout << listPlayer[0]->getName() << " Wins!" << endl;
			}

			if (listPlayer[0]->getLife() < listPlayer[1]->getLife())
			{
				++numVictoryP2;
				//cout << listPlayer[0]->getName() << " Wins!" << endl;
			}

			if (listPlayer[0]->getLife() == listPlayer[1]->getLife())
			{
				++numVictoryP1;
				++numVictoryP2;
				cout << "DRAW" << endl;
			}

			cout << "----------------------------------------------------------------" << endl << endl;

			roundEnded = true;

			unsigned int i = 0;
			while (i < listPlayer.size())
			{
				//listPlayer[i]->reset();
				++i;
			}

				break;
		}
		case typeMSG::death:
			break;
		default:
			break;
	}

	if (roundEnded)
	{
		int winnningRounds = ((QuickMatch*)listGameMode[modeSelected])->getNumberRoundToWin();

		if (numVictoryP1 == winnningRounds && numVictoryP1 != numVictoryP2)
		{
			fightRun = false;
			cout << endl << endl << "Match Ended" << endl;
			//cout << listPlayer[0]->getName() << " Wins!" << endl << endl;
			cout << "p1 wins" << endl;
		}

		if (numVictoryP2 == winnningRounds && numVictoryP2 != numVictoryP1)
		{
			fightRun = false;
			cout << endl << endl << "Match Ended" << endl;
			//cout << listPlayer[0]->getName() << " Wins!" << endl << endl;
			cout << "p2 wins" << endl;
		}

		if (numVictoryP1 == winnningRounds && numVictoryP2 == winnningRounds)
		{
			fightRun = false;
			cout << endl << endl << "Match Ended" << endl;
			cout << "DRAW" << endl << endl;
		}
	}
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

	int selection = atoi(inputHandler->handleInput().c_str()) - 1;
	system("cls");

	switch (selection)
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

	while (returnToArenaSelection)
	{
		arenaChoice();
	}
}

void GameManager::arenaChoice()
{
	returnToArenaSelection = false;
	bool arenaChoice = false;
	while (!arenaChoice)
	{
		((QuickMatch*)listGameMode[modeSelected])->displayArena();

		int selection = atoi(inputHandler->handleInput().c_str()) - 1;
		system("cls");

		arenaChoice = ((QuickMatch*)listGameMode[modeSelected])->selectArena(selection);
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

	while (returnToOptionSelection)
	{
		optionChoice();
	}

}

void GameManager::optionChoice()
{
	returnToOptionSelection = false;
	bool optionsConfirmed = false;
	while (!optionsConfirmed)
	{
		((QuickMatch*)listGameMode[modeSelected])->displayOptions();

		int selection = atoi(inputHandler->handleInput().c_str()) - 1;
		system("cls");

		((QuickMatch*)listGameMode[modeSelected])->selectOptions(selection);

		if (((QuickMatch*)listGameMode[modeSelected])->getOptionConfirmed() || ((QuickMatch*)listGameMode[modeSelected])->getOptionsCancel())
		{
			optionsConfirmed = true;
		}
		else
		{
			cout << endl << "Enter Your Value: " << endl;

			int selectionValue = atoi(inputHandler->handleInput().c_str());
			system("cls");

			((QuickMatch*)listGameMode[modeSelected])->setSelectedOption(((QuickMatch*)listGameMode[modeSelected])->getOptionSelected(), selectionValue);
		}
	}

	if (((QuickMatch*)listGameMode[modeSelected])->getOptionsCancel())
	{
		((QuickMatch*)listGameMode[modeSelected])->resetOptions();
	}

	if(((QuickMatch*)listGameMode[modeSelected])->getOptionConfirmed())
	{
		fighting();
	}

	while (resetMatch)
	{
		numVictoryP1 = 0;
		numVictoryP2 = 0;

		((QuickMatch*)listGameMode[modeSelected])->resetMatch();

		fighting();
	}
}

void GameManager::fighting()
{
	resetMatch = false;

	cout << endl << "The Match Begins" << endl << endl;
	cout << "In ..." << endl;
	cout << "3" << endl;
	Sleep(1000);
	cout << "2" << endl;
	Sleep(1000);
	cout << "1" << endl;
	Sleep(1000);
	cout << "Fight!" << endl;
	Sleep(1000);

	system("cls");

	fightRun = true;
	roundEnded = true;
	int frame = 0;
	numVictoryP1 = 0;
	numVictoryP2 = 0;

	while (fightRun)
	{
		if (roundEnded)
		{
			((QuickMatch*)listGameMode[modeSelected])->launchNewRound();
			((QuickMatch*)listGameMode[modeSelected])->registerObserver(this);
			roundEnded = false;
		}

		

		++frame;
		if (frame > 30)
		{
			((QuickMatch*)listGameMode[modeSelected])->secondPass();
		}
	}

	endMatch();
}

void GameManager::endMatch()
{
	bool choiceEndMatch = false;

	while (!choiceEndMatch)
	{
		cout << endl << "- 1 : Retry" << endl;
		cout << "- 2 : Return to game mode selection" << endl;
		cout << "- 3 : Return to arena selection" << endl;
		cout << "- 4 : Return to option selection" << endl;
		cout << "- 9 : Exit Game" << endl;

		cout << endl;

		int selection = atoi(inputHandler->handleInput().c_str());
		system("cls");

		switch (selection)
		{
		case 1:
			choiceEndMatch = true;
			resetMatch = true;
			break;
		case 2:
			((QuickMatch*)listGameMode[modeSelected])->resetOptions();
			((QuickMatch*)listGameMode[modeSelected])->reset();
			modeSelected = ModeRange::None;
			choiceEndMatch = true;
			break;
		case 3:
			returnToOptionSelection = false;
			returnToArenaSelection = true;
			((QuickMatch*)listGameMode[modeSelected])->resetOptions();
			choiceEndMatch = true;
			break;
		case 4:
			returnToOptionSelection = true;
			choiceEndMatch = true;
			break;
		case 9:
			choiceEndMatch = true;
			modeSelected = ModeRange::None;
			run = false;
			break;
		default:
			cout << endl << "error bad selection" << endl << endl;
			break;
		}
	}
}