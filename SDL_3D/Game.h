#pragma once

class GameState;
#include "Camera.h"
#include "ShaderProgram.h"
#include <SDL.h>

class Game
{
public:
	static void Init(const char* name, int width, int height);
	static void Run(GameState* startState);
	static void SetState(GameState* currentState);

private:
	Game();
	~Game();
	void RunInst();

public:
	ShaderProgram mShaders;
	bool mLoop{ true };
	GameState* mCurrentState{ nullptr };
	SDL_Window* mWindow{ nullptr };
	SDL_GLContext mContext;
	Uint32 mLastTick{ 0 };
	Camera mCamera;

public:
	static Game* inst;
};
