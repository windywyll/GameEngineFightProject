#ifndef SCENE
#define SCENE

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Round.h"

class Scene
{
	public:
		Scene();
		Scene(std::string n);
		~Scene();
		std::string getName();
		void reset();
		void displayOption();
		int getOptionSelected();
		bool getOptionConfirmed();
		bool getOptionCancel();
		void setSelectedOption(int option, int value);
		void selectOptions(int selectNum);

	private:
		std::string name;
		enum optionRange { none = -1, timeLimit = 0, roundToWin = 1, accept = 2, exit = 8 };
		optionRange optionSelected;
		std::vector<Round*> listRound;
		int limitTimeRound;
		int numberRoundToWin;
};
#endif