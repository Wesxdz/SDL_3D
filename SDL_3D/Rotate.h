#pragma once

#include "Component.h"

class Model;
#include <vec3.hpp>

class Rotate : public Component
{

public:
	glm::vec3 mAxis;
	float mSpeed;

public:
	Rotate(glm::vec3 axis, float speed);
	virtual void Update(float dt) override;
	virtual void Init() override;

private:
	Model* mTarget;

};