#pragma once

#include "ColorVertex.h"
#include "GL\glew.h"

/*
A container for the vertices and indices data needed to display an object on the screen. 
You only need one mesh instance per type of object.
*/
struct Mesh
{
public:
	Mesh();
	~Mesh();
public:
	ColorVertex* mVertices;
	GLuint mNumVerts;
	GLushort* mIndices;
	GLuint mNumIndices;
public:
	// Used for glBufferSubData()
	GLsizeiptr getVertSize();
	GLsizeiptr getIndexSize();
};

