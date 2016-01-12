#ifndef QUICKMATCH
#define QUICKMATCH

#include "GameMode.h"

class QuickMatch : public GameMode
{
	public:
		QuickMatch();
		~QuickMatch();
		void selectMode();
		void displayArena();
		void displayOptions();
		void reset();
		void resetOptions();
		void resetMatch();
		void launchNewRound();
		bool selectArena(int selectNum);
		void selectOptions(int selectNum);
		int getSelectedArena();
		int getOptionSelected();
		int getNumberRoundToWin();
		bool getOptionConfirmed();
		bool getOptionsCancel();
		void setSelectedOption(int option, int value);
		void secondPass();
		void registerObserver(ObserverDefeat* obs);
		void unregisterObserver(ObserverDefeat* obs);

	private:
		enum arenaRange{none = -1, quarry = 0, wasteland = 1, exit = 8};
		arenaRange arenaSelected;
};
#endif
