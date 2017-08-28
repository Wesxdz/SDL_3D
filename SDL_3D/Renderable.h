#pragma once

#include "Component.h"
#include <GL/glew.h>

class ShaderSys;

/*
Determines which ShaderSys will be used to render this Entity
*/
class Renderable : public Component
{

public:
	GLuint programToUse;

public:
	Renderable();
	~Renderable();

	// Set relevant glUniforms
	virtual void Prepare() = 0;

};

class SimpleRender : public Renderable
{
	// Inherited via Renderable
	virtual void Prepare() override;
};

class LightingRender : public Renderable
{
	// Inherited via Renderable
	virtual void Prepare() override;
};

