#include "RenderSys.h"

#include "Color.h"
#include "Game.h"
#include "GameState.h"
#include "Model.h"
#include "ShapeGenerator.h"
#include <iostream>
#include <gtc/type_ptr.hpp>
#include <SDL_opengl.h>

void RenderSys::Init()
{
	Mesh* cube = ShapeGenerator::GenCubeMesh();

	GLuint vertexBuffer;
	// Locations of uniform variables in Cube.vert.shader
	GLuint positionIndex = 0;
	GLuint colorIndex = 1;
	GLuint normalIndex = 2;

	GLint positionSize = 3;
	GLint colorSize = 3;
	GLint normalSize = 3;

	// Specifies a noffset of the first component of the first generic vertex attribute in the array in the data store of the buffer
	GLuint positionOffset = ColorVertex::GetPosOffset();
	GLuint colorOffset = ColorVertex::GetColorOffset();
	GLuint normalOffset = ColorVertex::GetNormalOffset();

	// Specifies the byte offset between consecutive generic vertex attributes
	GLsizei vertexStride = sizeof(glm::vec3) * 3;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, cube->getVertSize(), cube->mVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(positionIndex, positionSize, GL_FLOAT, GL_FALSE, vertexStride, (void*)positionOffset);
	glEnableVertexAttribArray(positionIndex);

	glVertexAttribPointer(colorIndex, colorSize, GL_FLOAT, GL_FALSE, vertexStride, (void*)colorOffset);
	glEnableVertexAttribArray(colorIndex);

	glVertexAttribPointer(normalIndex, normalSize, GL_FLOAT, GL_FALSE, vertexStride, (void*)normalOffset);
	glEnableVertexAttribArray(normalIndex);

	GLuint indexBuffer;

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube->getIndexSize(), cube->mIndices, GL_STATIC_DRAW);

	delete cube;

	modelLocation = Game::inst.shaders.GetUniformLocation("Model");
	viewLocation = Game::inst.shaders.GetUniformLocation("View");
	projectionLocation = Game::inst.shaders.GetUniformLocation("Projection");

	glUniform3f(Game::inst.shaders.GetUniformLocation("lightPos"), -5.0f, -5.0f, 1.0f);

}

void RenderSys::Draw()
{
	GLint tintName = Game::inst.shaders.GetUniformLocation("tint");
	for (Entity* entity : Game::inst.currentState->entities) {
		// TODO: Store Models in RenderSys, then loop through them
		Model* model;
		if (model = entity->GetComponent<Model>()) {
			Color* color;
			if (color = entity->GetComponent<Color>()) {
				glUniform3f(tintName, color->r, color->g, color->b);
			}
			else {
				glUniform3f(tintName, 1.0f, 1.0f, 1.0f);
			}
			glUniformMatrix4fv(modelLocation, 1, GL_FALSE,
				glm::value_ptr(model->Transform()));
			glUniformMatrix4fv(viewLocation, 1, GL_FALSE,
				glm::value_ptr(Game::inst.camera->View()));
			glUniformMatrix4fv(projectionLocation, 1, GL_FALSE,
				glm::value_ptr(Game::inst.camera->Projection()));
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
		}
	}
}
