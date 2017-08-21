#pragma once

#include "Component.h"

#include <vec3.hpp>

class Color : public Component
{

public:
	float r, g, b;

public:
	Color(float red, float green, float blue);

};
