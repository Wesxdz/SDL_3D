#pragma once

#include "GameState.h"

class Example : public GameState
{
public:
	//std::vector<ShaderSys> gameShaders;

public:
	// Inherited via GameState
	virtual void Init() override;
};