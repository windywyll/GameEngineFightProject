#include "Adventure.h"

using namespace std;

Adventure::Adventure()
{
	name = "adventure";
	listArena = vector<Scene>();
}


Adventure::~Adventure()
{

}

void Adventure::selectMode()
{
	cout << endl << "As soon as you stepped outside of your house you died of an cardiac arrest. Game over." << endl << endl;
}
