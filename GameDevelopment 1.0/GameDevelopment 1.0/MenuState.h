#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include <math.h>
#include <iostream>

class Game;
class MenuState :
	public GameState
{
private:

	// call back functions for menu itens
	static void s_menuToPlay();
	static void s_exitFromMenu();

	static const std::string s_menuID;
	
	int m_cursorPosition;

	static MenuState* s_pInstance;

	std::vector<GameObject*> m_gameObjects;

	void handleInput();

	MenuState();

public:

	~MenuState();
	
	static MenuState* Instance();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;
	int getCursorPosition() const;
};
typedef MenuState TheMenuState;
