#include "Entity.h"

#include "Component.h"

Entity::~Entity()
{
	for (Component* c : mComponents) {
		delete c;
	}
}

bool Entity::Input(SDL_Event* e)
{
	for (Component* c : mComponents) {
		c->Input(e);
	}
	return false;
}

void Entity::Update(float dt)
{
	for (Component* c : mComponents) {
		c->Update(dt);
	}
}

void Entity::AddComponent(Component* c)
{
	c->owner = this;
	c->Init();
	mComponents.push_back(c);
}
