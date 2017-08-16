#include "CameraController.h"

#include "Game.h"

CameraController::CameraController()
{
	mCamera = Game::inst.camera;
}

CameraController::~CameraController()
{
}
