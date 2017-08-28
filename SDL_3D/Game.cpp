#include "Game.h"

#include "GameState.h"
#include <GL/glew.h>

Game Game::inst;

Game::Game()
{

}

Game::~Game()
{
	delete currentState;
	activeShader->Shutdown();
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Init(const char* name, int width, int height)
{	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("SDL video initialization failed: %s", SDL_GetError());
	}

	inst.window = SDL_CreateWindow(
		name,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		width, height, 
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!inst.window) {
		SDL_Log("SDL unable to create window: %s", SDL_GetError());
	}
	inst.camera = new Camera;
	inst.camera->mScreenAspect = width / (float)height;

	inst.glContext = SDL_GL_CreateContext(inst.window);
	if (!inst.glContext) {
		SDL_Log("SDL unable to create OpenGL context: %s", SDL_GetError());
	}

	glewExperimental = GL_TRUE;
	glewInit();
}

void Game::Run(GameState* startState)
{
	SetState(startState);
	inst.RunInst();
}

void Game::SetState(GameState* state)
{
	inst.currentState = state;
	state->Init();
}

void Game::Exit()
{
	// TODO: Shutdown various systems;
	// TODO: Exit function call to currentState
	inst.mLoop = false;
}

void Game::RunInst()
{
	SDL_Event e;
	while (mLoop) {
		while (SDL_PollEvent(&e)) {
			currentState->Input(&e);
			if (e.type == SDL_QUIT) {
				Game::Exit();
			}
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					Game::Exit();
				}
			}
		}
		float dt = (SDL_GetTicks() - mLastTick)/1000.0f;
		mLastTick = SDL_GetTicks();
		currentState->Update(dt);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer.Draw();
		SDL_GL_SwapWindow(window);
	}
}
