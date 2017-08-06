#include "Game.h"

#include "GameState.h"
#include <GL/glew.h>


Game* Game::inst{ nullptr };

Game::Game()
{

}

Game::~Game()
{
	delete mCurrentState;
	mShaders.Shutdown();
	SDL_GL_DeleteContext(mContext);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::Init(const char* name, int width, int height)
{
	inst = new Game;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("SDL video initialization failed: %s", SDL_GetError());
	}

	inst->mWindow = SDL_CreateWindow(
		name, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		width, height, 
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!inst->mWindow) {
		SDL_Log("SDL unable to create window: %s", SDL_GetError());
	}
	inst->mCamera.mScreenAspect = width / (float)height;

	inst->mContext = SDL_GL_CreateContext(inst->mWindow);
	if (!inst->mContext) {
		SDL_Log("SDL unable to create OpenGL context: %s", SDL_GetError());
	}

	glewExperimental = GL_TRUE;
	glewInit();
}

void Game::Run(GameState* startState)
{
	SetState(startState);
	inst->RunInst();
}

void Game::SetState(GameState* state)
{
	inst->mCurrentState = state;
	state->Init();
}

void Game::RunInst()
{
	while (mLoop) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			mCurrentState->Input(&e);
		}
		float dt = (SDL_GetTicks() - mLastTick)/1000.0f;
		mLastTick = SDL_GetTicks();
		mCurrentState->Update(dt);
		mCurrentState->Draw();
		SDL_GL_SwapWindow(mWindow);
	}
}
