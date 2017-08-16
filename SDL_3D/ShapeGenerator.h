#pragma once

class GraphicalObject;
struct Mesh;
#include "ColorVertex.h"

class ShapeGenerator
{
public:
	// Use 24 if you want to change the colors of each face individually
	// The actual vertices of the cube
	static ColorVertex cubeVerts[24];
	// The indexes of which vertices to draw in order
	static unsigned short cubeIndices[36];

public:
	static Mesh* GenCubeMesh();

private:
	static void SetColors(float* color0, int numVerts, int stride);
};

