#pragma once

class Component;
#include <SDL_events.h>
#include <typeinfo>
#include <list>

/*
A general purpose object that interacts within the current GameState
*/
class Entity
{

private:
	// A unique ID to represent this
	Uint16 ID;
	// Component memory should be stored in collections within the System that uses them
	std::list<Component*> mComponents;

public:

	~Entity();

	bool Input(SDL_Event* e);
	void Update(float dt);
	void AddComponent(Component* c);

	template <class T> T* GetComponent() const;

};

template <class T> T* Entity::GetComponent() const
{
	for (Component* c : mComponents)
	{
		if (!c) continue;
		if (typeid(T) == typeid(*c))
		{
			return static_cast<T*> (c);
		}
	}
	return nullptr;
}
