#include "CameraController.h"
#include "Camera.h"

CameraController::CameraController()
{
}

CameraController::~CameraController()
{
	delete mCamera;
}
