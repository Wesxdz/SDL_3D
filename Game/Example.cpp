#include "Example.h"

#include "CubeManager.h"
#include "Game.h"
#include "KeyCam.h"
#include "MouseCam.h"
#include "Rotate.h"
#include "ShaderSys.h"
#include "ShapeGenerator.h"
#include <iostream>
#include <SDL_opengl.h>

void Example::Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glDepthFunc(GL_LEQUAL);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.2f, 0.2f, 0.3f, 1.0f);

	Game::inst.shaders.AddVertexShader("../resources/shaders/Cube.vert.shader");
	Game::inst.shaders.AddFragmentShader("../resources/shaders/Cube.frag.shader");
	Game::inst.shaders.LinkAndUseProgram();
	Game::inst.renderer.Init();
	// TODO: Load all necessary Mesh objects and then create GL VBOs in AssetSys

	Entity* camera = new Entity;
	camera->AddComponent(Game::inst.camera);
	camera->AddComponent(new MouseCam);
	camera->AddComponent(new KeyCam);
	entities.push_back(camera);

	Mesh* cubeMesh = ShapeGenerator::GenCubeMesh();

	Entity* cube = new Entity;
	cube->AddComponent(new Model(cubeMesh, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.3f)));
	cube->AddComponent(new Rotate(glm::vec3(0.5f, 1.0f, 0.5f), 1.0f));
	entities.push_back(cube);

	//Entity** cubes = new Entity*[5];
	//// One cube must be large, front and center on the screen with a rotate axis that shows off all faces, or at least 5 of them
	//cubes[0]->AddComponent(new Model(shapeGen.mDefaultCube, glm::vec3(0.0f), glm::vec3(0.3f)));
	//cubes[0]->AddComponent(new Rotate(glm::vec3(0.5f, 1.0f, 0.5f), 1.0f));

	//// Place one cube in the upper - left of the screen, have it rotate around the X - axis.
	//cubes[1]->AddComponent(new Model(shapeGen.mDefaultCube, glm::vec3(-5.0f, -5.0f, 1.0f), glm::vec3(0.1f)));
	//cubes[1]->AddComponent(new Rotate(glm::vec3(1.0f, 0.0f, 0.0f), 2.0f));

	//// Place one cube in the upper - right of the screen, have it rotate around the Y - axis.
	//cubes[2]->AddComponent(new Model(shapeGen.mDefaultCube, glm::vec3(0.5f, 0.5f, 10.0f), glm::vec3(0.1f)));
	//cubes[2]->AddComponent(new Rotate(glm::vec3(0.0f, 1.0f, 0.0f), 2.0f));

	//// Place one cube in the lower - right of the screen, rotating around the Z - axis.
	//cubes[3]->AddComponent(new Model(shapeGen.mDefaultCube, glm::vec3(0.5f, -0.5f, 4.0f), glm::vec3(0.1f)));
	//cubes[3]->AddComponent(new Rotate(glm::vec3(0.0f, 0.0f, 1.0f), 2.0f));

	//// Place one cube in the lower - left of the screen, have it rotate around the same axis as the first cube, but have it rotate in the other direction.
	//cubes[4]->AddComponent(new Model(shapeGen.mDefaultCube, glm::vec3(-0.5f, -0.5f, -4.0f), glm::vec3(0.1f)));
	//cubes[4]->AddComponent(new Rotate(glm::vec3(0.0f, 0.0f, 1.0f), -2.0f));

	//for (int i = 0; i < 5; i++) {
	//	entities.push_back(cubes[i]);
	//}

	//delete[] cubes;

}
