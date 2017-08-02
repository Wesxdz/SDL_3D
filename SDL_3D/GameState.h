#pragma once

#include <SDL_events.h>

class GameState
{
public:
	virtual ~GameState();
	virtual void Init() = 0;
	virtual void Input(SDL_Event* e) = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
};