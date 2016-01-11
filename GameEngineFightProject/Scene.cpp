#include "Scene.h"

using namespace std;

Scene::Scene()
{
	name = "default";
	listRound = vector<Round*>();
}

Scene::Scene(string n)
{
	name = n;
	listRound = vector<Round*>();
}


Scene::~Scene()
{
}

string Scene::getName()
{
	return name;
}