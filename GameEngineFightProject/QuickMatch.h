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
		void reset();
		bool selectArena(int selectNum);
		int getSelectedArena();

	private:
		enum arenaRange{none = -1, quarry = 0, wasteland = 1, exit = 8};
		arenaRange arenaSelected;
};
#endif
