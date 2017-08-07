#pragma once

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"

/*
Manages the View and Projection matrices
*/
class Camera
{
public:
	Camera();
public:
	// World space to camera space
	glm::mat4 View();

	// Camera space to screen space
	glm::mat4 Projection();

public:
	// Where the camera is positioned in world space
	glm::vec3 mPosition;

	float mVerticalAngle;
	float mHorizontalAngle;

	// Where the camera is looking towards in world space
	glm::vec3 mViewDirection;
	glm::vec3 mUpDirection;
	glm::vec3 mRightDirection;

	// window.width/window.height
	float mScreenAspect;
	float mFOVAngle{ glm::radians(60.0f) };

private:
	void Orient();

public:
	inline void RotateVertical(float verticleAngle) { 
		mVerticalAngle += verticleAngle;
		Orient();
	}
	inline void RotateHorizontal(float horizontal) {
		mHorizontalAngle += horizontal;
		Orient();
	}
};