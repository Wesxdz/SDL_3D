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
	virtual void Input(SDL_Event* e) override;
	virtual void Update(float dt) override;
	virtual void Draw() override;

public:
	CubeManager cubes;
	KeyCam test;
	MouseCam mouser;
};