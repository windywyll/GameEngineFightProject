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
		void reset();
		void resetMatch();
		void displayOption();
		int getNumberRoundToWin();
		int getOptionSelected();
		bool getOptionConfirmed();
		bool getOptionCancel();
		void setSelectedOption(int option, int value);
		void selectOptions(int selectNum);
		void launchNewRound();
		void secondPass();
		void registerObserver(ObserverDefeat* obs);
		void unregisterObserver(ObserverDefeat* obs);

	private:
		std::string name;
		enum optionRange { none = -1, timeLimit = 0, roundToWin = 1, accept = 2, exit = 8 };
		optionRange optionSelected;
		std::vector<RoundMatch*> listRound;
		int limitTimeRound;
		int numberRoundToWin;
};
#endif