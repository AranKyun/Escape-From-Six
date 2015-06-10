#pragma once
#include "VBO.h"
	
enum VBO_TYPE{VBO_NULL = -1, VBO_ROOM, VBO_KEY, VBO_DOOR};


class VBOContainer
{
	static const int nVBOType = 2;
	VBO* vboList[nVBOType];
	const char* objPaths[] = {
		"room.obj",
		"key.obj",
		"door.obj"
	};
public:
	VBOContainer();
	~VBOContainer();

	GLuint searchVBO(VBO_TYPE);
};

