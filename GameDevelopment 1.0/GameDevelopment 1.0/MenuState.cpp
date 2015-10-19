#include "MenuState.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

MenuState* MenuState::s_pInstance = 0;

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

void MenuState::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		SDL_Delay(200);
		if (m_cursorPosition <= 0) {
			m_cursorPosition = 4;
		}
		m_cursorPosition--;
		m_cursorPosition = m_cursorPosition % 4;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		SDL_Delay(200);
		
		m_cursorPosition++;
		m_cursorPosition = m_cursorPosition % 4;
	}
}

MenuState::MenuState()
{
}


MenuState::~MenuState()
{
	s_pInstance = 0;
}

MenuState * MenuState::Instance()
{
	if (s_pInstance == 0) {
		s_pInstance = new MenuState();
		return s_pInstance;
	}

	return s_pInstance;
}

void MenuState::update()
{
	handleInput();
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	m_cursorPosition = 0;

	if (!TheTextureManager::Instance()->load("assets/play_button.png", "play_button", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/options_button.png", "options_button", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/instructions_button.png", "instructions_button", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit_button.png", "exit_button", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* buttonPlay = new MenuButton(new LoaderParams(0, 0, 0, 0, 640, 120, "play_button"), s_menuToPlay);
	GameObject* buttonOptions = new MenuButton(new LoaderParams(0, 0, 0, 120, 640, 120, "options_button"), s_menuToPlay);
	GameObject* buttonInstructions = new MenuButton(new LoaderParams(0, 0, 0, 240, 640, 120, "instructions_button"), s_menuToPlay);
	GameObject* buttonExit = new MenuButton(new LoaderParams(0, 0, 0, 360, 640, 120, "exit_button"), s_exitFromMenu);

	m_gameObjects.push_back(buttonPlay);
	m_gameObjects.push_back(buttonOptions);
	m_gameObjects.push_back(buttonInstructions);
	m_gameObjects.push_back(buttonExit);

	std::cout << "Começou o bagui" << std::endl;

	return true;
}

bool MenuState::onExit()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("play_button");
	TheTextureManager::Instance()->clearFromTextureMap("options_button");
	TheTextureManager::Instance()->clearFromTextureMap("instructions_button");
	TheTextureManager::Instance()->clearFromTextureMap("exit_button");

	s_pInstance = 0;

	return true;
}

std::string MenuState::getStateID() const
{
	return s_menuID;
}

int MenuState::getCursorPosition() const
{
	return m_cursorPosition;
}
