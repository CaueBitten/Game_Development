#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),
	m_position((float)pParams->getXDest(), (float)pParams->getYDest()), m_velocity(0, 0),
	m_acceleration(0,0)
{
	m_xSrc = pParams->getXSrc();
	m_ySrc = pParams->getYSrc();

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_currentRow = 1;
	m_currentFrame = 1;

	m_textureID = pParams->getTextureID();
}

SDLGameObject::~SDLGameObject()
{
}

void SDLGameObject::draw()
{
	if (m_velocity.getX() < 0) {
		TheTextureManager::Instance()->drawFrame(m_textureID, m_xSrc, m_ySrc, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height,
			m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TheTextureManager::Instance()->drawFrame(m_textureID, m_xSrc, m_ySrc, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height,
			m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
	}
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::clean()
{
}