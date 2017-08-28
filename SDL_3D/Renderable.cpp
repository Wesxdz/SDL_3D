#include "Renderable.h"

#include "Game.h"
#include "Model.h"
#include "ShaderSys.h"
#include <gtc/type_ptr.hpp>


Renderable::Renderable()
{
	// By default, use the active ShaderSys
	programToUse = Game::inst.activeShader->mProgramID;
}

Renderable::~Renderable()
{
}

void SimpleRender::Prepare()
{
	glUseProgram(programToUse);
	Model* model = GetSiblingComponent<Model>();
	glUniformMatrix4fv(Game::inst.activeShader->GetUniformLocation("Model"), 1, GL_FALSE,
		glm::value_ptr(model->Transform()));
}

void LightingRender::Prepare()
{
	glUseProgram(programToUse);
	Model* model = GetSiblingComponent<Model>();
	glUniformMatrix4fv(Game::inst.activeShader->GetUniformLocation("Model"), 1, GL_FALSE,
		glm::value_ptr(model->Transform()));
}
