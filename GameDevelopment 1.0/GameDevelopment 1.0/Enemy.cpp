#include "Enemy.h"



Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}


Enemy::~Enemy()
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_position.setX(m_position.getX() - 1);
	m_currentFrame = int( (SDL_GetTicks() / 100) % 5);
}

void Enemy::clear()
{
}
