#pragma once

#include <glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

#include "GameInstance.h"

#include "VBOContainer.h"
#include "ShaderProgram.h"

struct vertexInfo{
	GLfloat coordinate[3];
	GLfloat normal[3];
};


class Graph
{
protected:
	GameInstance& gi; 
	ShaderProgram& sp;

	GLuint vaoID;
	VBO_TYPE vboType;

	int objectID;

	GLint nFace;
	
	glm::mat4 MVP;

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

	void init();

	vertexInfo* loadObj(const char*); //加载obj模型 参数-地址

	void draw(); //绘制模型

	void updateMVP(); //设置mvp

	void setLocationXYZ(float, float, float);

};


