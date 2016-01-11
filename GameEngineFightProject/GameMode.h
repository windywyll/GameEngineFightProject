#ifndef GAMEMODE
#define GAMEMODE

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Scene.h"

class GameMode
{
	public:
		GameMode();
		~GameMode();
		virtual void selectMode() = 0;
		std::string getName();

	protected:
		std::string name;
		std::vector<Scene*> listArena;
};
#endif