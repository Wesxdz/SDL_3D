#pragma once

class GameState;
#include "Camera.h"
#include "ShaderSys.h"
#include "RenderSys.h"
#include <SDL.h>
#include <vector>

/*
The Game class contains a singleton, #inst, that holds all Systems
*/
class Game
{

public:
	static Game inst;

public:
	static void Init(const char* name, int width, int height);
	static void Run(GameState* startState);
	static void SetState(GameState* currentState);
	static void Exit();

public:
	GameState* currentState{ nullptr };

	SDL_Window* window{ nullptr };
	SDL_GLContext glContext;

	ShaderSys shaders;
	RenderSys renderer;

	Camera* camera;

private:
	bool mLoop{ true };
	Uint32 mLastTick{ 0 };

private:
	Game();
	~Game();
	void RunInst();

};
