#pragma once

#include "Mesh.h"
#include "mat4x4.hpp"
#include "vec3.hpp"

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
	Mesh* mShape;

	glm::mat4 mScale;
	glm::mat4 mRotation;
	glm::mat4 mTranslation;

	glm::vec3 mRotateAxis;
	int mRotateSpeed;
	int mRotateAngle;

	glm::vec3 mTint;
};

