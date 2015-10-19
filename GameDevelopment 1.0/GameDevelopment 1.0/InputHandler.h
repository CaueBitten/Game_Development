#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"


class Game;
class InputHandler
{
private:

	static InputHandler* s_pInstance;

	const Uint8* m_keyStates;

	InputHandler();
	~InputHandler();

	void onKeyDown();
	void onKeyUp();

public:

	static InputHandler* Instance();

	void update();
	void clean();

	bool isKeyDown(SDL_Scancode key);

};
typedef InputHandler TheInputHandler;
