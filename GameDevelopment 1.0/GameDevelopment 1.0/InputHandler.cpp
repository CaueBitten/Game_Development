#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{

}


InputHandler::~InputHandler()
{
}

void InputHandler::onKeyDown()
{
}

void InputHandler::onKeyUp()
{
}

InputHandler * InputHandler::Instance()
{
	if (s_pInstance == 0) {
		s_pInstance = new InputHandler();
		return s_pInstance;
	}

	return s_pInstance;
}

void InputHandler::update()
{
	SDL_Event event;
	m_keyStates = SDL_GetKeyboardState(0);

	while (SDL_PollEvent(&event)) {
		
		switch (event.type)
		{
		case SDL_QUIT:						// se o usuário saiu da aplicação
			TheGame::Instance()->quit();
			break;

		case SDL_KEYDOWN:
			onKeyDown();
			break;

		case SDL_KEYUP:
			onKeyUp();
			break;
	
		default:
			break;
		}
		
		
	}

}

void InputHandler::clean()
{
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{

	if (m_keyStates != 0) {
		if (m_keyStates[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

