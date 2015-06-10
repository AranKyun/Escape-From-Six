#pragma once
#include "glew.h"

struct vertexInfo{
	GLfloat coordinate[3];
	GLfloat normal[3];
};


class VBO
{
	GLuint vboID;

	vertexInfo* vertices;

	const char* objPath;

	int nFace;

public:

	VBO(const char*);
	~VBO();

	GLuint getVBOID();
	int getFaceNum();

	vertexInfo* loadObj(const char*);
};

