#include "GameManager.h"

int main()
{
	GameManager* gm = GameManager::getInstance();

	gm->startGame();

	return 0;
}