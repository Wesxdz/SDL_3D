#pragma once

#include "vec3.hpp"

/*
Describes a vertex (a point in space) that has an associated color
*/
struct ColorVertex
{
	ColorVertex();
	ColorVertex(float x, float y, float z);
	glm::vec3 pos;
	glm::vec3 color;
	static unsigned int GetPosOffset();
	static unsigned int GetColorOffset();
};