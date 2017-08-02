#pragma once

class GraphicalObject;
struct Mesh;
#include "ColorVertex.h"

class ShapeGenerator
{
public:
	ShapeGenerator();
	~ShapeGenerator();
	// Use 24 if you want to change the colors of each face individually
	// The actual vertices of the cube
	static ColorVertex cubeVerts[24];
	// The indexes of which vertices to draw in order
	static unsigned short cubeIndices[36];
	Mesh* mDefaultCube{ nullptr };

public:
	/*
	@return: The first float in an array of floats used to represent a cube
	The floats will be X, Y, Z, R, G, B for each vertex
	@mutate: sets numVerts to number of vertices returned
	*/
	void MakeCube(GraphicalObject* gob);
	Mesh* GenCubeMesh();
private:
	static void SetColors(float* color0, int numVerts, int stride);
};

