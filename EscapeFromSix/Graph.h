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

	vertexInfo* loadObj(const char*); //加载obj模型 参数-地址
	void draw(); //绘制模型

	void updateMVP(); //设置mvp

};


