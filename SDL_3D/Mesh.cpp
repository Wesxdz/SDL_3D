#include "Mesh.h"

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

GLsizeiptr Mesh::getVertSize()
{
	return sizeof(mVertices[0]) * mNumVerts;
}

GLsizeiptr Mesh::getIndexSize()
{
	return sizeof(mIndices[0]) * mNumIndices;
}
