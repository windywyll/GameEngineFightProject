#ifndef INPUTMANAGER
#define INPUTMANAGER

#include <string>;
#include <iostream>
#include <stdio.h>

class InputManager
{
	public:
		static InputManager* getInstance()
		{
			static InputManager instance;

			return &instance;
		}

		std::string handleInput();

	private:
		InputManager();
		~InputManager();
};
#endif