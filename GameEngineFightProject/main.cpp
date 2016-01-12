#include "GameManager.h"
#include "Player.h"
#include "Jump.h"
#include "Attack.h"
#include "Move.h"
using namespace std;

void mainWill()
{
	Player P1 = Player(50, "JEAN", 1);
	Player P2 = Player(50, "JEANNE", 1);
	Action* punch = P1.actionList.at('a');
	Move* j = new Move("jump", 0.0, 0.0, 0.0, 0.0);
	P1.useAction(punch);
	P1.useAction(punch);
	cout << P1.currentCombo.at(0)->name << P1.currentCombo.at(1)->name << endl;
	cout << P1.currentCombo.size() << " " << P1.CheckCurrentCombo()->name << endl;

	system("PAUSE");
	delete j;
}

void mainJord()
{
	GameManager* gm = GameManager::getInstance();
	gm->startGame();
}

int main()
{
	mainWill();
	
	return 0;
}


