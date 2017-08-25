#pragma once

#include "Model.h"
#include <vector>

class RenderSys
{

public:
	void Init();
	void Draw();

private:
	GLint modelLocation;
	GLint viewLocation;
	GLint projectionLocation;
	GLint viewPosLocation;
	//std::vector<Model> mModels;

};