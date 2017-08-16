#include "RenderSys.h"

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

	GLint positionSize = 3;
	GLint colorSize = 3;

	// Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer
	GLuint positionOffset = 0;
	GLuint colorOffset = sizeof(glm::vec3);

	// Specifies the byte offset between consecutive generic vertex attributes
	GLsizei vertexStride = sizeof(glm::vec3) * 2;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, cube->getVertSize(), cube->mVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(positionIndex, positionSize, GL_FLOAT, GL_FALSE, vertexStride, (void*)positionOffset);
	glEnableVertexAttribArray(positionIndex);

	glVertexAttribPointer(colorIndex, colorSize, GL_FLOAT, GL_FALSE, vertexStride, (void*)colorOffset);
	glEnableVertexAttribArray(colorIndex);

	GLuint indexBuffer;

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cube->getIndexSize(), cube->mIndices, GL_STATIC_DRAW);
	delete cube;
}

void RenderSys::Draw()
{
	GLint tintName = Game::inst.shaders.GetUniformLocation("tint");
	GLint transformName = Game::inst.shaders.GetUniformLocation("MVP");
	for (Entity* entity : Game::inst.currentState->entities) {
		Model* model;
		if (model = entity->GetComponent<Model>()) {
			glUniform3f(tintName, 0.0f, 0.0f, 1.0f);
			glUniformMatrix4fv(transformName, 1, GL_FALSE,
				glm::value_ptr(Game::inst.camera->Projection() * Game::inst.camera->View() * model->Transform()));
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
		}
	}
}
