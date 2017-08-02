#include "Example.h"

#include "Game.h"
#include "ShaderProgram.h"
#include <SDL_opengl.h>
#include "CubeManager.h"
#include <iostream>

void Example::Init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
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
}

void Example::Input(SDL_Event* e)
{
	if (e->type == SDL_QUIT) {
		Game::inst->mLoop = false;
	}
}

void Example::Update(float dt)
{
	cubes.Update(dt);
}

void Example::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	cubes.Draw();
}
