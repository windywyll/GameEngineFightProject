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
		bool selectArena(int selectNum);
		void selectOptions(int selectNum);
		int getSelectedArena();
		int getOptionSelected();
		bool getOptionConfirmed();
		bool getOptionsCancel();
		void setSelectedOption(int option, int value);

	private:
		enum arenaRange{none = -1, quarry = 0, wasteland = 1, exit = 8};
		arenaRange arenaSelected;
};
#endif
