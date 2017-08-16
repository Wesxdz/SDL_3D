#pragma once

#include "Entity.h"
#include <SDL_events.h>
#include <vector>

class GameState
{

public:
	std::vector<Entity*> entities;

public:
	virtual ~GameState();
	virtual void Init() = 0;
	void Input(SDL_Event* e);
	void Update(float dt);

};