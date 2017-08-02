#pragma once

class ShaderProgram;
#include "GraphicalObject.h"
#include "ShapeGenerator.h"

class CubeManager
{
public:
	CubeManager();
	~CubeManager();

	void Update(float dt);
	void Draw();

	void Init(ShaderProgram* shaderManager);
private:
	ShaderProgram* mShaderManager;
	void InitCubes();
	GraphicalObject mCubes[5];
	ShapeGenerator mShapeGen;
};

