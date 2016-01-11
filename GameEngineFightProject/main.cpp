#include "GameManager.h"
#include "Player.h"
#include "Jump.h"

using namespace std;

int main()
{
	/*GameManager* gm = GameManager::getInstance();
	gm->startGame();*/
	Player P1 = Player(50, "JEAN");
	Player P2 = Player(50, "JEANNE");
	Jump* j = new Jump("jump",0.0,0.0,0.0,0.0);
	cout << P1.position.y << endl;
	P1.useAction(j);
	cout << P1.position.y << endl;



	system("PAUSE");
	delete j;
	return 0;
}