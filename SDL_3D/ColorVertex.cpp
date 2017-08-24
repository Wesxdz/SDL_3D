#include "ColorVertex.h"

#include "gtc\random.hpp"

ColorVertex::ColorVertex()
{
}

ColorVertex::ColorVertex(float x, float y, float z, glm::vec3 norm)
{
	pos = glm::vec3{ x, y, z };
	color = glm::vec3{ glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f) };
	normal = norm;
}

unsigned int ColorVertex::GetPosOffset()
{
	return 0;
}

unsigned int ColorVertex::GetColorOffset()
{
	return sizeof(glm::vec3);
}

unsigned int ColorVertex::GetNormalOffset()
{
	return sizeof(glm::vec3) * 2;
}
