#include "PlayState.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState()
{
}


PlayState::~PlayState()
{
}

void PlayState::update()
{
	//TheInputHandler::Instance()->update();
	
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	std::cout << "Erro aqui" << std::endl;
}

void PlayState::render()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}

	std::cout << "Erro aqui" << std::endl;
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/cara.png", "player", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* player = new Player(new LoaderParams(48 * 2, 0, 0, 0, 48, 55, "player"));

	m_gameObjects.push_back(player);

	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("player");

	std::cout << "exiting PlayState" << std::endl;
	return true;
}

std::string PlayState::getStateID() const
{
	return s_playID;
}
