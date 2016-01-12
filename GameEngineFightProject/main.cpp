#include "GameManager.h"
#include "Player.h"
#include "Jump.h"
#include "Move.h"
using namespace std;

int main()
{
	/*GameManager* gm = GameManager::getInstance();
	gm->startGame();*/
	Player P1 = Player(50, "JEAN");
	Player P2 = Player(50, "JEANNE");
	Move* j = new Move("jump",0.0,0.0,0.0,0.0);
	
	cout << P1.getPosition().x <<" "<< P1.getState() <<endl;
	P1.useAction(j);
	cout << P1.getPosition().x << " " << P1.getState() << endl;
	P1.useAction(j);
	cout << P1.getPosition().x << " " << P1.getState() << endl;
	P1.setState(DEATH);
	P1.useAction(j);
	cout << P1.getPosition().x << " " << P1.getState() << endl;
	



	system("PAUSE");
	delete j;
	return 0;
}