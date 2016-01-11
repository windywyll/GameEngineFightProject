#ifndef INPUTMANAGER
#define INPUTMANAGER

class InputManager
{
	public:
		static InputManager* getInstance()
		{
			static InputManager instance;

			return &instance;
		}

		char handleInput();

	private:
		InputManager();
		~InputManager();
};
#endif