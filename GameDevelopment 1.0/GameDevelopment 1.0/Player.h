#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
private:

	void handleInput();

public:

	Player(const LoaderParams* pParams);
	~Player();

	virtual void	draw();
	virtual void	update();
	virtual void	clear();
};

