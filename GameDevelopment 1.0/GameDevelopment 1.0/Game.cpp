#include "Game.h"

using namespace std;

Game* Game::s_pInstance = 0; 


Game::Game()
{
	m_pWindow = 0;
	m_pRenderer = 0;
	m_bRunning = false;
}

Game::~Game()
{
	m_pRenderer = 0;
	m_pWindow = 0;
	s_pInstance = 0;
}

Game * Game::Instance()
{
	if (s_pInstance == 0) {
		s_pInstance = new Game();
		return s_pInstance;
	}

	return s_pInstance;
}

bool Game::init(const char* title, int xPos, int yPos, int widht, int height)
{
	// Attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		// Init the window
		m_pWindow = SDL_CreateWindow(title, xPos, yPos, widht, height, 0);

		if (m_pWindow != 0) {		// window init success			
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);			

			if (m_pRenderer != 0) {		// render init success
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else {
				cout << "render init fail" << endl;
				return false;	// render init fail
			}
		}	
		else {
			cout << "window init fail" << endl;
			return false;	// window init fail
		}
	}
	else {
		cout << "SDL init fail" << endl;
		return false;	// SDL init fail
	}

	TheInputHandler::Instance()->Instance();

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(MenuState::Instance());

	m_bRunning = true;	// start the main loop

	return true;	// everything inited successfully
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);	// clear the renderer to the draw color

	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer);	// draw to the screen
}

void Game::update()
{
	m_pGameStateMachine->update();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	/* 
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_pGameStateMachine->changeState(new PlayState());
	}
	*/
	/*
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		m_pGameStateMachine->changeState(MenuState::Instance());
	}
	*/
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
}

bool Game::isRunning()
{
	return m_bRunning;
}

SDL_Renderer * Game::getRenderer() const
{
	return m_pRenderer;
}

GameStateMachine * Game::getStateMachine()
{
	return m_pGameStateMachine;
}
