#pragma once
#include "GameState.h"
#include <vector>
class GameStateMachine
{
private:

	std::vector<GameState*> m_gameStates;

public:
	GameStateMachine();
	~GameStateMachine();

	void		pushState(GameState* pState);
	void		changeState(GameState* pState);
	void		popState();

	void		update();
	void		render();
};

