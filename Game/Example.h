#pragma once

#include "CubeManager.h"
#include "GameState.h"
#include "KeyCam.h"
#include "MouseCam.h"

class Example : public GameState
{
public:
	// Inherited via GameState
	virtual void Init() override;
};