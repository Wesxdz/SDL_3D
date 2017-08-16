#pragma once

#include "Entity.h"
#include <SDL_assert.h>
#include <SDL_events.h>
#include <typeinfo>

/*
The raw data for one aspect of an Entity, and how it interacts with the world
*/
class Component
{
public:
	virtual ~Component();
	// Component interaction events can be used here
	virtual void Init();
	virtual bool Input(SDL_Event* e);
	virtual void Update(float dt);

	template <class T>
	T* GetSiblingComponent()
	{
		SDL_assert(owner);
		return owner->GetComponent<T>();
	}
public:
	// Could be nullptr if not attached to a specific Entity
	Entity* owner{ nullptr };
};