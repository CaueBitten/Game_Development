#include "MenuButton.h"
#include "MenuState.h"


MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
	m_currentFrame = CURSOR_OUT;
}


MenuButton::~MenuButton()
{
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::update()
{
	int cursorPosY = MenuState::Instance()->getCursorPosition() * 120;
	
	if (m_position.getY() <= cursorPosY && cursorPosY < (m_position.getY() + m_height)) {
		m_currentFrame = CURSOR_OVER;
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
			m_currentFrame = CLICKED;

			m_callback();
		} 
	}
	else {
		m_currentFrame = CURSOR_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
