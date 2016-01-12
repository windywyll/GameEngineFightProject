#ifndef GAMEMANAGER
#define GAMEMANAGER

#include <vector>
#include <string>

#include "ObserverDefeat.h"
#include "InputManager.h"
#include "GameMode.h"
#include "Adventure.h"
#include "QuickMatch.h"
#include "Tournament.h"
#include "Player.h"


class GameManager : public ObserverDefeat
{
	public:
		static GameManager* getInstance()
		{
			static GameManager instance;

			return &instance;
		}

		void startGame();
		void gameModeChoice();
		void adventureSelected();
		void tournamentSelected();
		void quickMatchSelected();
		void arenaChoice();
		void optionChoice();
		void fighting();
		void checkEndRound();
		void endMatch();
		void notify(Message msg);
		void sendDamage(int nPlayer, int dmg, float stunTime);
	
	private:
		GameManager();
		~GameManager();
		enum ModeRange { None = -1, partieRapide = 2, Tournoi = 1, Aventure = 0, Exit = 8 };
		ModeRange modeSelected;
		bool run, fightRun, roundEnded, resetMatch, returnToArenaSelection, returnToOptionSelection ,p1Death, p2Death;
		int fps = 30, numVictoryP1, numVictoryP2;
		InputManager* inputHandler;
		std::vector<GameMode*> listGameMode;
		std::vector<Player*> listPlayer;
};
#endif
