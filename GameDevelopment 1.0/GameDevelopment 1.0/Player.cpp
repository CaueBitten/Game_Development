#include "Player.h"


void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(1);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-1);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_velocity.setY(-1);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_velocity.setY(1);
	}
	
}

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	SDLGameObject::SDLGameObject(pParams);
}


Player::~Player()
{
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	m_currentFrame = int( (SDL_GetTicks() / 100) % 5);

	SDLGameObject::update();
}

void Player::clear()
{
}
