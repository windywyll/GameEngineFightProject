#ifndef GAMEMANAGER
#define GAMEMANAGER

#include <vector>
#include "ObserverDefeat.h"
#include "InputManager.h"
#include "GameMode.h"
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
		void notify();
	
	private:
		GameManager();
		~GameManager();
		InputManager* inputHandler;
		std::vector<GameMode> listGameMode;
		std::vector<Player> listPlayer;
};
#endif
