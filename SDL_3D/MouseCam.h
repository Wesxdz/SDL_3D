#pragma once

#include "CameraController.h"
#include "vec3.hpp"

class MouseCam : public CameraController
{
public:
	MouseCam();
	// Inherited via CameraController
	virtual bool Input(SDL_Event* e) override;
	virtual void Update(float dt) override;
public:
	glm::vec3 mFocus;
	float mSpeed;
	float mVerticalAngle;
	float mHorizontalAngle;
};