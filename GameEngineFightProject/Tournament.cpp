#include "Tournament.h"

using namespace std;

Tournament::Tournament()
{
	name = "tournament";
	listArena = vector<Scene>();
}


Tournament::~Tournament()
{
	
}

void Tournament::selectMode()
{
	cout << endl << "You were too late to enter the tournament. Maybe next time." << endl << endl;
}