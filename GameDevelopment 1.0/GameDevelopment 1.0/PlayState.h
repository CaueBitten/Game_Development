#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>
#include <iostream>

class Game;
class PlayState :
	public GameState
{
private :

	static const std::string s_playID;

	std::vector<GameObject*> m_gameObjects;

public:
	PlayState();
	~PlayState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const;
};

