#pragma once

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"

/*
Manages the View and Projection matrices
*/
class Camera
{
public:
	// World space to camera space
	glm::mat4 View();

	// Camera space to screen space
	glm::mat4 Projection();
public:

	// Where the camera is positioned in world space
	glm::vec3 mPosition{ 0, 0, 2 };
	// Where the camera is looking towards in world space
	glm::vec3 mViewDirection{ 0, 0, -1 };
	glm::vec3 mUpDirection{ 0, 1, 0 };

	// window.width/window.height
	float mScreenAspect;
	float mFOVAngle{ glm::radians(60.0f) };

};