#ifndef SCENE
#define SCENE

#include <string>
#include <vector>
#include "Round.h"

class Scene
{
	public:
		Scene();
		Scene(std::string n);
		~Scene();
		std::string getName();

	private:
		std::string name;
		std::vector<Round*> listRound;
};
#endif