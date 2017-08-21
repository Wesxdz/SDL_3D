#pragma once

#include "GameState.h"

class Example : public GameState
{
public:
	// Inherited via GameState
	virtual void Init() override;
};