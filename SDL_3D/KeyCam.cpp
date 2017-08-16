#include "KeyCam.h"

#include "Camera.h"
#include <gtx/transform.hpp>

KeyCam::KeyCam() :
	mMoveSpeed{ 4 },
	mRiseSpeed{ 4 },
	mRotateSpeed{ 1 }
{
}

bool KeyCam::Input(SDL_Event* e)
{
	return false;
}

void KeyCam::Update(float dt)
{
	auto keyboard = SDL_GetKeyboardState(NULL);
	// Left and right
	if (keyboard[SDL_SCANCODE_A]) { mCamera->mPosition -= dt * mCamera->mRightDirection * mMoveSpeed; }
	if (keyboard[SDL_SCANCODE_D]) { mCamera->mPosition += dt * mCamera->mRightDirection * mMoveSpeed;
	}

	// Forward and backwards
	if (keyboard[SDL_SCANCODE_S]) { mCamera->mPosition -= dt * mCamera->mForwardDirection * mMoveSpeed; }
	if (keyboard[SDL_SCANCODE_W]) { mCamera->mPosition += dt * mCamera->mForwardDirection * mMoveSpeed; }

	// Up and down
	if (keyboard[SDL_SCANCODE_R]) { mCamera->mPosition += glm::vec3(0.0f, dt * mRiseSpeed, 0.0f); }
	if (keyboard[SDL_SCANCODE_F]) { mCamera->mPosition += glm::vec3(0.0f, -dt * mRiseSpeed, 0.0f); }

	if (keyboard[SDL_SCANCODE_Q]) { mCamera->RotateYaw(dt * mRotateSpeed); }
	if (keyboard[SDL_SCANCODE_E]) { mCamera->RotateYaw(-dt * mRotateSpeed); }

	if (keyboard[SDL_SCANCODE_T]) { mCamera->RotatePitch(dt * mRotateSpeed); }
	if (keyboard[SDL_SCANCODE_G]) { mCamera->RotatePitch(-dt * mRotateSpeed); }
}
