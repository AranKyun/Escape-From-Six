#include "ShaderProgram.h"
#include <iostream>
#include <fstream>
#include <string>

ShaderProgram::ShaderProgram(const char* vertexShaderCodePath, const char* fragmentShaderCodePath)
{
	programID = genProgram(vertexShaderCodePath, fragmentShaderCodePath);

	mvpID = glGetUniformLocation(programID, "MVP");
}


ShaderProgram::~ShaderProgram()
{
}


GLuint ShaderProgram::loadShader(const char* path, GLenum type)
{
	//开始编译
	using namespace std;
	GLuint shaderID = glCreateShader(type);

	string code;
	ifstream codeStream(path, ios::in);

	if (codeStream.is_open()) {
		string line = "";
		while (getline(codeStream, line))
			code += "\n" + line;
		codeStream.close();
	}

	const char* sourcePointer = code.c_str();
	glShaderSource(shaderID, 1, &sourcePointer, NULL);
	glCompileShader(shaderID);

	//输出报错
	GLint result = GL_FALSE;
	int infoLogLength;

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

	char* errMsg = new char[infoLogLength];

	glGetShaderInfoLog(shaderID, infoLogLength, NULL, errMsg);
	fprintf(stderr, "%s\n", errMsg);

	delete(errMsg);

	return shaderID;
}


GLuint ShaderProgram::genProgram(const char* vertCodePath, const char* fragCodePath)
{
	//生成两个着色器
	GLuint vertexShader = loadShader(vertCodePath, GL_VERTEX_SHADER);
	GLuint fragmentShader = loadShader(fragCodePath, GL_FRAGMENT_SHADER);

	//生成program
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);

	GLint result = GL_FALSE;
	int infoLogLength;

	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

	char* errMsg = new char[infoLogLength];

	glGetProgramInfoLog(programID, infoLogLength, NULL, errMsg);
	fprintf(stderr, "%s\n", errMsg);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return programID;
}

GLuint ShaderProgram::getMvpID()
{
	return mvpID;
}

GLuint ShaderProgram::getProgramID()
{
	return programID;
}