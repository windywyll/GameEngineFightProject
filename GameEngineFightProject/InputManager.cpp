#include "InputManager.h"

using namespace std;

InputManager::InputManager()
{

}


InputManager::~InputManager()
{

}

string InputManager::handleInput()
{
	string toReturn;
	cin >> toReturn;
	return toReturn;
}

char InputManager::handleInputChar()
{
	char toReturn;
	cin >> toReturn;
	return toReturn;
}