#include "Camera.h"
#include "gtx/transform.hpp"

#include <iostream>

glm::mat4 Camera::View()
{
	return glm::lookAt(mPosition, mPosition + mViewDirection, mUpDirection);
}

glm::mat4 Camera::Projection()
{
	return glm::perspective(mFOVAngle, mScreenAspect, 0.1f, 100.f);
}
