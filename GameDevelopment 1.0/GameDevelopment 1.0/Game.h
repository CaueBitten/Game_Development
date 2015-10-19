#pragma once

#include "SDL.h"
#include <iostream>
#include <vector>
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;

	GameStateMachine* m_pGameStateMachine;

	bool			m_bRunning;
	int				m_currentFrame;

	static Game*	s_pInstance;

	Game();

public:
	~Game();

	static Game* Instance();

	bool			init(const char* title, int xPos, int yPos, int widht, int height);					
	void			render();			
	void			update();
	void			handleEvents();
	void			clean();
	void			quit();

	bool			isRunning();

	SDL_Renderer*	getRenderer() const;

	GameStateMachine* getStateMachine();
};
typedef Game TheGame;
