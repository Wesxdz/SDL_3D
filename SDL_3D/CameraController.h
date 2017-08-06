#pragma once

class Camera;
#include "Component.h"

class CameraController : public Component
{
public:
	virtual bool Input(SDL_Event* e) override = 0;
	virtual void Update(float dt) override = 0;
public:
	CameraController();
	virtual ~CameraController();
	inline Camera* GetCamera() { return mCamera; }
	inline void SetCamera(Camera* camera) { mCamera = camera; }
protected:
	Camera* mCamera;
};