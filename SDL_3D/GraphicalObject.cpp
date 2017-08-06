#include "GraphicalObject.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtx/transform.hpp"

GraphicalObject::GraphicalObject()
{
}


GraphicalObject::~GraphicalObject()
{
}

void GraphicalObject::Update(float dt)
{
	mRotation = glm::rotate(mRotation, dt * mRotateSpeed, mRotateAxis);
}

glm::mat4 GraphicalObject::Model()
{
	return mTranslation * mRotation * mScale;
}
