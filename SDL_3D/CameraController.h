#pragma once

#include "Component.h"

#include "Camera.h"

class CameraController : public Component
{

public:
	CameraController();
	virtual ~CameraController();
	inline Camera* GetCamera() { return mCamera; }
	inline void SetCamera(Camera* camera) { mCamera = camera; }
	virtual bool Input(SDL_Event* e) override = 0;
	virtual void Update(float dt) override = 0;

protected:
	Camera* mCamera;

};