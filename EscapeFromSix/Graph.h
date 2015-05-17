#pragma once
#include <glew.h>
#include <glm\glm.hpp>

struct vertexInfo{
	GLfloat coordinate[3];
	GLfloat normal[3];
};


class Graph
{
	
	GLuint vaoID;

	GLint nFace;
	static vertexInfo* vertices;
	
	
	static const char* objPath;

public:
	Graph();
	~Graph();

	vertexInfo* loadObj(const char*); //����objģ��
	void draw(); //����ģ��

};


