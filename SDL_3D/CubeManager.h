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

public:
	GraphicalObject mCubes[5];
private:
	ShaderProgram* mShaderManager;
	void InitCubes();
	ShapeGenerator mShapeGen;
};

