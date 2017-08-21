#include "ShapeGenerator.h"

#include "Mesh.h"
#include <gtc/random.hpp>
#include <iostream>

ColorVertex ShapeGenerator::cubeVerts[24] =
{
	// Back Face
	ColorVertex{ -1.0, +1.0, -1.0 },
	ColorVertex{ +1.0, +1.0, -1.0 },
	ColorVertex{ +1.0, -1.0, -1.0 },
	ColorVertex{ -1.0, -1.0, -1.0 },

	// Right Side
	ColorVertex{ +1.0, +1.0, -1.0 },
	ColorVertex{ +1.0, +1.0, +1.0 },
	ColorVertex{ +1.0, -1.0, +1.0 },
	ColorVertex{ +1.0, -1.0, -1.0 },

	// Left Side
	ColorVertex{ -1.0, +1.0, -1.0 },
	ColorVertex{ -1.0, +1.0, +1.0 },
	ColorVertex{ -1.0, -1.0, +1.0 },
	ColorVertex{ -1.0, -1.0, -1.0 },

	// Top
	ColorVertex{ -1.0, +1.0, -1.0 },
	ColorVertex{ +1.0, +1.0, -1.0 },
	ColorVertex{ +1.0, +1.0, +1.0 },
	ColorVertex{ -1.0, +1.0, +1.0 },

	// Bottom
	ColorVertex{ -1.0, -1.0, -1.0 },
	ColorVertex{ +1.0, -1.0, -1.0 },
	ColorVertex{ +1.0, -1.0, +1.0 },
	ColorVertex{ -1.0, -1.0, +1.0 },

	// Front Face
	ColorVertex{ -1.0, +1.0, +1.0 },
	ColorVertex{ +1.0, +1.0, +1.0 },
	ColorVertex{ +1.0, -1.0, +1.0 },
	ColorVertex{ -1.0, -1.0, +1.0 },
};

unsigned short ShapeGenerator::cubeIndices[36] =
{
	// Back
	0, 1, 2,
	0, 2, 3,

	// Right Side
	4, 5, 6,
	4, 6, 7,

	// Left Side
	8, 9, 10,
	8, 10, 11,

	// Top
	12, 13, 14,
	12, 14, 15,

	// Bottom
	16, 17, 18,
	16, 18, 19,

	// Front
	20, 21, 22,
	20, 22, 23,
};

Mesh* ShapeGenerator::GenCubeMesh()
{
	Mesh* cube = new Mesh();
	// mVertices should point to an array of 24 ColorVertex’s. 4 vertexes per face times 6 faces. Make sure these vertices involve 1.0f and -1.0f only.
	cube->mVertices = &cubeVerts[0];
	cube->mNumVerts = 24;
	// mIndices should point to an array of 36 indices. 3 indices per triangle times 2 triangles per face times 6 faces.
	cube->mIndices = &cubeIndices[0];
	cube->mNumIndices = 36;
	SetColors(&cube->mVertices->color[0], 24, 6);
	return cube;
}

void ShapeGenerator::SetColors(float* color0, int numVerts, int stride)
{
	for (int iVert = 0; iVert < numVerts; iVert++) {
		for (int iColor = 0; iColor < 3; iColor++) {
			color0[(iVert * stride) + iColor] = glm::linearRand(0.01f, 1.0f);
		}
	}
}
