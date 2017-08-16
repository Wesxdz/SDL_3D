#pragma once

#include "Mesh.h"
#include "mat4x4.hpp"
#include "vec3.hpp"

// TODO: Change to Model : Component
/*
Contains the transforms and other information needed for each object on the screen
*/
class GraphicalObject
{
public:
	GraphicalObject();
	~GraphicalObject();

	void Update(float dt);
	glm::mat4 Model();
public:
	GLuint mMeshID;
	Mesh* mShape;

	glm::mat4 mScale;
	glm::mat4 mRotation;
	glm::mat4 mTranslation;

	// TODO: Move rotation to another Component
	glm::vec3 mRotateAxis;
	int mRotateSpeed;
	int mRotateAngle;

	// Uniform values
	// TODO: Move to different Component?
	glm::vec3 mTint;
};

