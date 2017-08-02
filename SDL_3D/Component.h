#pragma once

#include <SDL_events.h>

class Component
{
public:
	virtual ~Component();
	virtual bool Input(SDL_Event* e);
	virtual void Update(float dt);
	virtual void Draw();
};