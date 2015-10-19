#pragma once
#include "SDLGameObject.h"

class MenuState;
class MenuButton :
	public SDLGameObject
{
private:

	enum button_state {
		CURSOR_OUT = 0,
		CURSOR_OVER = 1,
		CLICKED = 2
	};

	void (*m_callback)();

public:
	
	MenuButton(const LoaderParams* pParams, void (*callback)());
	~MenuButton();

	virtual void draw();
	virtual void update();
	virtual void clean();
};

