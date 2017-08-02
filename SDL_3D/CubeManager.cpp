#include "CubeManager.h"

#include "ShapeGenerator.h"
#include <GL/glew.h>
#include <iostream>
#include "ShaderProgram.h"
#include "glm.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtx/transform.hpp"

CubeManager::CubeManager()
{
}

CubeManager::~CubeManager()
{
}

void CubeManager::Update(float dt)
{
	for (int i = 0; i < 5; i++) {
		mCubes[i].Update(dt);
	}
}

void CubeManager::Draw()
{
	GLint tintName = mShaderManager->GetUniformLocation("tint");
	GLint transformName = mShaderManager->GetUniformLocation("transform");
	for (int i = 0; i < 5; i++) { 
		glUniform3f(tintName, mCubes[i].mTint.x, mCubes[i].mTint.y, mCubes[i].mTint.z);
		glUniformMatrix4fv(transformName, 1, GL_FALSE, glm::value_ptr(mCubes[i].Transform()));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
	}
}

void CubeManager::Init(ShaderProgram* shaderManager)
{
	mShaderManager = shaderManager;
	InitCubes();

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
	glBufferData(GL_ARRAY_BUFFER, mShapeGen.mDefaultCube->getVertSize(), mShapeGen.mDefaultCube->mVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(positionIndex, positionSize, GL_FLOAT, GL_FALSE, vertexStride, (void*)positionOffset);
	glEnableVertexAttribArray(positionIndex);
	
	glVertexAttribPointer(colorIndex, colorSize, GL_FLOAT, GL_FALSE, vertexStride, (void*)colorOffset);
	glEnableVertexAttribArray(colorIndex);

	GLuint indexBuffer;

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mShapeGen.mDefaultCube->getIndexSize(), mShapeGen.mDefaultCube->mIndices, GL_STATIC_DRAW);
}

void CubeManager::InitCubes()
{
	for (int i = 0; i < 5; i++) {
		mShapeGen.MakeCube(&mCubes[i]);
	}

	// One cube must be large, front and center on the screen with a rotate axis that shows off all faces, or at least 5 of them
	mCubes[0].mScale = glm::scale(glm::vec3(0.2f, 0.5f, 0.5f));
	mCubes[0].mTranslation = glm::translate(glm::vec3(0, 0, 0));
	mCubes[0].mRotateAxis = glm::vec3(0.5, 1, 0.5);
	mCubes[0].mRotateSpeed = 1.0f;
	mCubes[0].mTint = glm::vec3(0.9f, 0.0f, 0.9f);

	// Place one cube in the upper - left of the screen, have it rotate around the X - axis.
	mCubes[1].mScale = glm::scale(glm::vec3(0.085, 0.2, 0.2));
	mCubes[1].mTranslation = glm::translate(glm::vec3(-0.5f, +0.5f, 0));
	mCubes[1].mRotateAxis = glm::vec3(1, 0, 0);
	mCubes[1].mRotateSpeed = 2.0f;
	mCubes[1].mTint = glm::vec3(1.0f, 0.2f, 0.0f);

	// Place one cube in the upper - right of the screen, have it rotate around the Y - axis.
	mCubes[2].mScale = glm::scale(glm::vec3(0.085, 0.2, 0.2));
	mCubes[2].mTranslation = glm::translate(glm::vec3(0.5f, 0.5f, 0));
	mCubes[2].mRotateAxis = glm::vec3(0, 1, 0);
	mCubes[2].mRotateSpeed = 2.0f;
	mCubes[2].mTint = glm::vec3(0.0f, 0.7f, 0.3f);

	// Place one cube in the lower - right of the screen, rotating around the Z - axis.
	mCubes[3].mScale = glm::scale(glm::vec3(0.085, 0.2, 0.2));
	mCubes[3].mTranslation = glm::translate(glm::vec3(0.5f, -0.5f, 0));
	mCubes[3].mRotateAxis = glm::vec3(0, 0, 1);
	mCubes[3].mRotateSpeed = 2.0f;
	mCubes[3].mTint = glm::vec3(0.2f, 0.5f, 0.8f);

	// Place one cube in the lower - left of the screen, have it rotate around the same axis as the first cube, but have it rotate in the other direction.
	mCubes[4].mScale = glm::scale(glm::vec3(0.085, 0.2, 0.2));
	mCubes[4].mTranslation = glm::translate(glm::vec3(-0.5f, -0.5f, 0));
	mCubes[4].mRotateAxis = glm::vec3(0, 0, 1);
	mCubes[4].mRotateSpeed = -2.0f;
	mCubes[4].mTint = glm::vec3(0.2f, 0.5f, 0.8f);
}