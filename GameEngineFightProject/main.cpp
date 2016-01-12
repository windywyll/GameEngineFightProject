#include "GameManager.h"
#include "Player.h"
#include "Jump.h"
#include "Move.h"
using namespace std;

int main()
{
	mainWill();
	
	return 0;
}


void mainWill()
{
	Player P1 = Player(50, "JEAN", 1);
	Player P2 = Player(50, "JEANNE", 1);
	Move* j = new Move("jump", 0.0, 0.0, 0.0, 0.0);

	cout << P1.getPosition().x << " " << P1.getState() << endl;
	P1.useAction(j);
	cout << P1.getPosition().x << " " << P1.getState() << endl;
	P1.useAction(j);
	cout << P1.getPosition().x << " " << P1.getState() << endl;
	P1.setState(DEATH);
	P1.useAction(j);
	cout << P1.getPosition().x << " " << P1.getState() << endl;
	
	system("PAUSE");
	delete j;
}

void mainJord()
{
	GameManager* gm = GameManager::getInstance();
	gm->startGame();
}