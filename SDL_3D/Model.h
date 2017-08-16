#pragma once

#include "Component.h"

#include "Mesh.h"
#include <mat4x4.hpp>
#include <vec3.hpp>

class Model : public Component
{

public:
	// TODO: Replace this with MeshID
	Mesh* mShape;

public:
	Model(
		Mesh* shape,
		glm::vec3 translation = glm::vec3(0.0f),
		glm::vec3 scale		  =	glm::vec3(1.0f),
		glm::mat4 rotation	  =	glm::mat4(1.0f)
	);

	inline glm::mat4 Transform()	{ return mTransform; }
	inline glm::mat4 Scale()		{ return mScale; }
	inline glm::mat4 Rotation()		{ return mRotation; }
	inline glm::vec3 Translation()	{ return glm::vec3(mTranslation[2][0], mTranslation[2][1], mTranslation[2][2]); }

	void SetScale(glm::vec3 scale);
	void SetRotation(glm::mat4 rotation);
	void SetTranslation(glm::vec3 translation);

private:
	glm::mat4 mTransform;
	// TODO: Store these as vec3s
	glm::mat4 mTranslation;
	glm::mat4 mScale;
	glm::mat4 mRotation;

private:
	void calcModel();

};
