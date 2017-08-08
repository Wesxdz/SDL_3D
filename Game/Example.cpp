#include "Example.h"

#include "Game.h"
#include "ShaderProgram.h"
#include <SDL_opengl.h>
#include "CubeManager.h"
#include <iostream>

void Example::Init()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
	ShaderProgram* shaders = &Game::inst->mShaders;
	shaders->Init();
	shaders->AddVertexShader("../resources/shaders/Cube.vert.shader");
	shaders->AddFragmentShader("../resources/shaders/Cube.frag.shader");
	for (GLuint i = 0; i < shaders->mNumShaders; i++) {
		shaders->CheckShaderCompileStatus(shaders->mShaders[i].id);
	}
	shaders->LinkAndUseProgram();
	cubes.Init(&Game::inst->mShaders);
	test.SetCamera(&Game::inst->mCamera);
	mouser.SetCamera(&Game::inst->mCamera);
}

void Example::Input(SDL_Event* e)
{
	if (e->type == SDL_QUIT) {
		Game::inst->mLoop = false;
	}
	if (e->type == SDL_KEYDOWN) {
		if (e->key.keysym.sym == SDLK_ESCAPE) {
			Game::inst->mLoop = false;
		}
	}
	if (e->type == SDL_WINDOWEVENT) {
		if (e->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			// TODO: Move this to Game
			int w, h;
			SDL_GetWindowSize(Game::inst->mWindow, &w, &h);
			Game::inst->mCamera.mScreenAspect = w / (float)h;
			glViewport(0, 0, w, h); // Hooray!
		}
	}
	mouser.Input(e);
}

void Example::Update(float dt)
{
	test.Update(dt);
	cubes.Update(dt);
	mouser.Update(dt);
}

void Example::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cubes.Draw();
}
