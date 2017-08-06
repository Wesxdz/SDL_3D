#pragma once

#include "CameraController.h"

// Control a Camera using keyboard input
class KeyCam : public CameraController
{
public:
	// Inherited via CameraController
	virtual bool Input(SDL_Event* e) override;
	virtual void Update(float dt) override;
public:
	int mSpeed{ 1 };
};
