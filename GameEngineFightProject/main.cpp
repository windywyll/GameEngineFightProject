#include "GameManager.h"
#include "Player.h"
#include "Jump.h"
#include "Move.h"
using namespace std;

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

int main()
{
	cout << "- 1 : main Jordan" << endl;
	cout << "- 2 : main William" << endl;

	string input;
	cin >> input;
	int selection = atoi(input.c_str());

	if (selection == 1)
	{
		system("cls");
		mainJord();
	}

	if (selection == 2)
	{
		system("cls");
		mainWill();
	}
	
	return 0;
}