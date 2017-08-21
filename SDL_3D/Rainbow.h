#pragma once

#include "Color.h"
#include "Component.h"

class Rainbow : public Component
{
public:
	Rainbow(float speed);
	virtual void Update(float dt) override;
	virtual void Init();

public:
	float mPhase;

private:
	Color* mColor;
	float mStage;

};
