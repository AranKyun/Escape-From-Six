#pragma once

#include <glew.h>


class ShaderProgram
{
	GLuint programID;
	GLuint mvpID;

public:
	ShaderProgram(const char*, const char*);
	~ShaderProgram();

	GLuint loadShader(const char*, GLenum);
	GLuint genProgram(const char*, const char*);

	GLuint getProgramID();
	GLuint getMvpID();

};


