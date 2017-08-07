#include "MouseCam.h"

#include "gtx/transform.hpp"
#include "gtc/matrix_transform.hpp"
#include <iostream>
#include <SDL_opengl.h>

MouseCam::MouseCam() :
	mSpeed{ 0.03f },
	mHorizontalAngle { 90.0f }
{
}

bool MouseCam::Input(SDL_Event* e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		if (e->button.button == SDL_BUTTON_RIGHT) {
			mFocus = mCamera->mPosition + mCamera->mViewDirection;
		}
	}
	if (e->type == SDL_MOUSEMOTION) {
		if (e->motion.state & SDL_BUTTON_MMASK) {
			mCamera->mPosition -= mCamera->mRightDirection * (float)e->motion.xrel * mSpeed;
			mCamera->mPosition += mCamera->mUpDirection * (float)e->motion.yrel * mSpeed;
		}
		if (e->motion.state & SDL_BUTTON_RMASK) {
			// TODO: Rotate mCamera view direction around the y-axis
			mCamera->RotateHorizontal(-e->motion.xrel * mSpeed/4);
			mCamera->RotateVertical(-e->motion.yrel * mSpeed/4);
		}
	}
	// TODO: Zoom based on current zoom amount
	if (e->type == SDL_MOUSEWHEEL) {
		if (e->wheel.y > 0) {
			mCamera->mPosition += mCamera->mViewDirection;
		}
		else if (e->wheel.y < 0) {
			mCamera->mPosition -= mCamera->mViewDirection;
		}
	}
	return false;
}

void MouseCam::Update(float dt)
{
}
