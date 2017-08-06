#include "KeyCam.h"

#include "Camera.h"
#include <gtx/transform.hpp>

bool KeyCam::Input(SDL_Event* e)
{
	return false;
}

void KeyCam::Update(float dt)
{
	auto keyboard = SDL_GetKeyboardState(NULL);
	// Left and right
	if (keyboard[SDL_SCANCODE_A]) { mCamera->mPosition += glm::vec3(mSpeed * dt, 0.0f, 0.0f); }
	if (keyboard[SDL_SCANCODE_D]) { mCamera->mPosition += glm::vec3(-mSpeed * dt, 0.0f, 0.0f); }

	// Forward and backwards
	if (keyboard[SDL_SCANCODE_S]) { mCamera->mPosition += glm::vec3(0.0f, 0.0f, mSpeed * dt); }
	if (keyboard[SDL_SCANCODE_W]) { mCamera->mPosition += glm::vec3(0.0f, 0.0f, -mSpeed * dt); }

	// Up and down
	if (keyboard[SDL_SCANCODE_R]) { mCamera->mPosition += glm::vec3(0.0f, -mSpeed * dt, 0.0f); }
	if (keyboard[SDL_SCANCODE_F]) { mCamera->mPosition += glm::vec3(0.0f, mSpeed * dt, 0.0f); }
}
