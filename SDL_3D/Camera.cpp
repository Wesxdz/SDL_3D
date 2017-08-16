#include "Camera.h"

#include "Game.h"
#include <gtx/transform.hpp>
#include <iostream>

Camera::Camera() :
	mPosition{ 0, 4, 4 },
	mYawRotation { 0 },
	mPitchRotation{ -45 }
{
	Orient();
}

bool Camera::Input(SDL_Event* e)
{
	if (e->type == SDL_WINDOWEVENT) {
		if (e->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			int w, h;
			SDL_GetWindowSize(Game::inst.window, &w, &h);
			mScreenAspect = w / (float)h;
			glViewport(0, 0, w, h);
		}
	}
	return false;
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
		cos(mPitchRotation) * sin(mYawRotation),
		sin(mPitchRotation), 
		cos(mPitchRotation) * cos(mYawRotation));
	mRightDirection = glm::vec3(
		sin(mYawRotation - 3.14f / 2.0f),
		0,
		cos(mYawRotation - 3.14f / 2.0f));
	mUpDirection = glm::cross(mRightDirection, mViewDirection);
	mForwardDirection = glm::cross(mUpDirection, mRightDirection);
}
