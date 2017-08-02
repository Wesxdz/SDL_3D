#include "Component.h"

Component::~Component()
{
}

bool Component::Input(SDL_Event * e)
{
	return false;
}

void Component::Update(float dt)
{
}

void Component::Draw()
{
}
