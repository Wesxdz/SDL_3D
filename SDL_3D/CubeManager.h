#pragma once

class ShaderSys;
#include "GraphicalObject.h"
#include "ShapeGenerator.h"

class CubeManager
{
public:
	CubeManager();
	~CubeManager();

	void Update(float dt);
	void Draw();

	void Init(ShaderSys* shaderManager);

public:
	GraphicalObject mCubes[5];
private:
	ShaderSys* mShaderManager;
	void InitCubes();
	ShapeGenerator mShapeGen;
};

