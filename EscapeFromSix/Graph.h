#pragma once

#include <glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

#include "GameInstance.h"
#include "ShaderProgram.h"

struct vertexInfo{
	GLfloat coordinate[3];
	GLfloat normal[3];
};


class Graph
{
	GameInstance& gi; 
	ShaderProgram& sp;

	GLuint vaoID;

	int objectID;

	GLint nFace;
	static vertexInfo* vertices;
	
	glm::mat4 MVP;

	static const char* objPath;

	float scale;
	float initRotateAngle;
	glm::vec3 initRotateAxis;
	bool rotateAnime;
	float animeRotateAngle;
	glm::vec3 animeRotateAxis;

	float locationX;
	float locationY;
	float locationZ;
	bool translationAnime;
	float translationX;
	float translationY;
	float translationZ;


public:
	Graph(GameInstance&, ShaderProgram&, int);
	~Graph();

	vertexInfo* loadObj(const char*); //����objģ�� ����-��ַ
	void draw(); //����ģ��

	void updateMVP(); //����mvp

};


