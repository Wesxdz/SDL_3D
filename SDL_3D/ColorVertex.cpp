#include "ColorVertex.h"

#include "gtc\random.hpp"

ColorVertex::ColorVertex()
{
}

ColorVertex::ColorVertex(float x, float y, float z)
{
	pos = glm::vec3{ x, y, z };
	color = glm::vec3{ glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f) };
}

unsigned int ColorVertex::GetPosOffset()
{
	return 0;
}

unsigned int ColorVertex::GetColorOffset()
{
	return sizeof(pos);
}
