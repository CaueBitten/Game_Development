#pragma once

#include "GameObject.h"
#include "TextureManager.h" 
//#include "Game.h"
#include "Vector2D.h"

class Game;

class SDLGameObject : public GameObject
{
protected:

	int m_xSrc;
	int m_ySrc;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;
	
	int m_currentRow;
	int m_currentFrame;
	
	std::string m_textureID;

	

public:

	SDLGameObject(const LoaderParams* pParams);
	~SDLGameObject();

	virtual void draw();
	virtual void update();
	virtual void clean();
};


