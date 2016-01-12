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
	p1Death = false;
	p2Death = false;

	modeSelected = ModeRange::None;

	inputHandler = InputManager::getInstance();

	listPlayer = vector<Player*>();
	listPlayer.push_back(new Player(200, "william", 1));
	listPlayer.push_back(new Player(200, "jordan", 2));

	unsigned int i = 0;

	while (i < listPlayer.size())
	{
		listPlayer[i]->registerObserver(this);
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
		listPlayer.back()->unregisterObserver(this);
		delete listPlayer.back();
		listPlayer.pop_back();
	}

	while (listGameMode.size() > 0)
	{
		delete listGameMode.back();
		listGameMode.pop_back();
	}
}

void GameManager::sendDamage(int nPlayer, int dmg, float stunTime)
{
	if(nPlayer == 1)
		listPlayer[1]->applyDamage(dmg, stunTime);

	if(nPlayer == 2)
		listPlayer[0]->applyDamage(dmg, stunTime);
}

void GameManager::notify(Message msg)
{
	switch (msg.getMsg())
	{
		case typeMSG::endTimer:
			cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
			if (listPlayer[0]->getLife() > listPlayer[1]->getLife())
			{
				++numVictoryP1;
				cout << listPlayer[0]->getName() << " Wins!" << endl;
			}

			if (listPlayer[0]->getLife() < listPlayer[1]->getLife())
			{
				++numVictoryP2;
				cout << listPlayer[1]->getName() << " Wins!" << endl;
			}

			if (listPlayer[0]->getLife() == listPlayer[1]->getLife())
			{
				++numVictoryP1;
				++numVictoryP2;
				cout << "DRAW" << endl;
			}

			cout << "--------------------------------------------------------------------------------" << endl << endl;

			break;
		case typeMSG::death:
			if (msg.getSource() == typeSource::p1)
				p1Death = true;

			if (msg.getSource() == typeSource::p2)
				p2Death = true;
			break;
		default:
			break;
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

		while (modeSelected == ModeRange::Help)
		{
			helpSelected();
		}

		while (modeSelected == ModeRange::partieRapide)
		{
			quickMatchSelected();
		}
	}
}

void GameManager::gameModeChoice()
{
	system("cls");

	cout << endl << "Choose your Game mode:" << endl << endl;
	for (unsigned int i = 0; i < listGameMode.size(); ++i)
	{
		cout << "- " << (i+1) << " : " << listGameMode[i]->getName() << endl;
	}

	cout << "- 8 : How To Play" << endl;
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
		case ModeRange::Help:
			modeSelected = ModeRange::Help;
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

void GameManager::helpSelected()
{
	system("cls");

	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << " HOW TO PLAY" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Left   : Q" << endl;
	cout << "Right  : D" << endl;
	cout << "Jump   : Z" << endl;
	cout << "Crouch : S" << endl;
	cout << "Block  : E" << endl;
	cout << "Attack : A" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "The keys are the same for both players." << endl;
	cout << "You block during a certain time and can't make another input during that time." << endl;
	cout << "While blocking, you have a slight chance to die." << endl;
	cout << listPlayer[0]->getName() << " is Player 1." << endl;
	cout << listPlayer[1]->getName() << " is Player 2." << endl;
	cout << endl << endl;

	modeSelected = ModeRange::None;

	system("pause");
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
	unsigned int i = 0;
	int frame = 0;
	int frameConfirmDeath = 0;
	int frameConfirmationDelay = 5;
	numVictoryP1 = 0;
	numVictoryP2 = 0;

	while (fightRun)
	{
		if (roundEnded)
		{
			frame = 0;
			frameConfirmDeath = 0;

			p1Death = false;
			p2Death = false;

			((QuickMatch*)listGameMode[modeSelected])->launchNewRound();
			((QuickMatch*)listGameMode[modeSelected])->registerObserver(this);
			roundEnded = false;
		}

		//Combat
		while (i < listPlayer.size())
		{
			if (listPlayer[i]->canTakeInput())
			{
				cout << endl;
				cout << listPlayer[i]->getName() << " - " << listPlayer[i]->getLife() << "HP - enter an action : ";
				listPlayer[i]->InputHandler(inputHandler->handleInputChar());
			}

			listPlayer[i]->UpdatePlayer();

			i++;
		}

		i = 0;

		++frame;

		if (frame > 30)
		{
			((QuickMatch*)listGameMode[modeSelected])->secondPass();
		}

		if (p1Death)
		{
			if (p2Death)
			{
				checkEndRound();
			}
			else
			{
				if (frameConfirmDeath < frameConfirmationDelay)
				{
					++frameConfirmDeath;
				}
				else
				{
					checkEndRound();
				}
			}
		}
		else
		{
			if (p2Death)
			{
				if (frameConfirmDeath < frameConfirmationDelay)
				{
					++frameConfirmDeath;
				}
				else
				{
					checkEndRound();
				}
			}
		}
	}

	endMatch();
}

void GameManager::checkEndRound()
{
	roundEnded = true;

	if (p1Death)
	{
		if (p2Death)
		{
			++numVictoryP1;
			++numVictoryP2;
			cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
			cout << "DOUBLE KO!" << endl;
			cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
		}
		else
		{
			++numVictoryP2;
			cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
			cout << listPlayer[1]->getName() << " Wins!" << endl;
			cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
		}
	}
	else
	{
		if (p2Death)
		{
			++numVictoryP1;
			cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
			cout << listPlayer[0]->getName() << " Wins!" << endl;
			cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
		}
	}

	if (roundEnded)
	{
		unsigned int i = 0;
		while (i < listPlayer.size())
		{
			listPlayer[i]->Initial();
			++i;
		}

		int winnningRounds = ((QuickMatch*)listGameMode[modeSelected])->getNumberRoundToWin();

		if (numVictoryP1 == winnningRounds && numVictoryP1 != numVictoryP2)
		{
			fightRun = false;
			cout << endl << endl << "Match Ended" << endl;
			cout << listPlayer[0]->getName() << " Wins!" << endl << endl;
		}

		if (numVictoryP2 == winnningRounds && numVictoryP2 != numVictoryP1)
		{
			fightRun = false;
			cout << endl << endl << "Match Ended" << endl;
			cout << listPlayer[1]->getName() << " Wins!" << endl << endl;
		}

		if (numVictoryP1 == winnningRounds && numVictoryP2 == winnningRounds)
		{
			fightRun = false;
			cout << endl << endl << "Match Ended" << endl;
			cout << "DRAW" << endl << endl;
		}
	}
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