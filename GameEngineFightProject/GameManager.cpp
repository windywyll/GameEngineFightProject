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
	cout << "Choose your Game mode:" << endl << endl;
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
	while (1)
	{

	}
}