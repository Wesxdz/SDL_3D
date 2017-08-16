#pragma once

#include "Component.h"

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

/*
Manages the View and Projection matrices
*/
class Camera : public Component
{

public:
	// Where the camera is positioned in world space
	glm::vec3 mPosition;

	/*
	Camera rotation about the x-axis
	This is like a person nodding thier head up and down
	baseball = pitcher winding up arm
	*/
	float mPitchRotation;
	/*
	Camera view direction  about the y-axis
	This is like an owl rotating its head 
	who-who = YAWn (because I'm tired at night)
	*/
	float mYawRotation;

	// Where the camera is looking towards in world space
	glm::vec3 mViewDirection;
	glm::vec3 mUpDirection;
	glm::vec3 mRightDirection;
	glm::vec3 mForwardDirection;

	// window.width/window.height
	float mScreenAspect;
	float mFOVAngle{ glm::radians(60.0f) };

public:
	Camera();

	inline void RotatePitch(float rads) {
		mPitchRotation += rads;
		Orient();
	}

	inline void RotateYaw(float rads) {
		mYawRotation += rads;
		Orient();
	}

	virtual bool Input(SDL_Event* e) override;

	// World space to camera space
	glm::mat4 View();

	// Camera space to screen space
	glm::mat4 Projection();


private:
	void Orient();

};