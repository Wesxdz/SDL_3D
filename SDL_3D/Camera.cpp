#include "Camera.h"
#include "gtx/transform.hpp"

#include <iostream>

Camera::Camera() :
	mPosition{ 0, 4, 4 },
	mHorizontalAngle { 0 },
	mVerticalAngle{ -45 }
{
	Orient();
}

glm::mat4 Camera::View()
{
	return glm::lookAt(mPosition, mPosition + mViewDirection, mUpDirection);
}

glm::mat4 Camera::Projection()
{
	return glm::perspective(mFOVAngle, mScreenAspect, 0.1f, 100.f);
}

void Camera::Orient()
{
	mViewDirection = glm::vec3(
		cos(mVerticalAngle) * sin(mHorizontalAngle),
		sin(mVerticalAngle), 
		cos(mVerticalAngle) * cos(mHorizontalAngle));
	mRightDirection = glm::vec3(
		sin(mHorizontalAngle - 3.14f / 2.0f),
		0,
		cos(mHorizontalAngle - 3.14f / 2.0f));
	mUpDirection = glm::cross(mRightDirection, mViewDirection);
}
