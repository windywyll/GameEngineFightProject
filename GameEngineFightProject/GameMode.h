#ifndef GAMEMODE
#define GAMEMODE

#include <string>
#include <vector>
#include "Scene.h"

class GameMode
{
	public:
		GameMode();
		~GameMode();
		virtual void selectMode() = 0;

	protected:
		std::string name;
		std::vector<Scene> listArena;
};
#endif