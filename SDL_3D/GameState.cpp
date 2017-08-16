#include "GameState.h"

GameState::~GameState()
{
	for (Entity* entity : entities) {
		delete entity;
	}
}

void GameState::Input(SDL_Event * e)
{
	for (Entity* entity : entities) {
		entity->Input(e);
	}
}

void GameState::Update(float dt)
{
	for (Entity* entity : entities) {
		entity->Update(dt);
	}
}
