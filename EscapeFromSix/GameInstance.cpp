#include <iostream>
#include "glew.h"

#include "GameInstance.h"

GameInstance::GameInstance() :ct(new Controller(*this)), pe(new PlayerEntity(*this)), mc(new MapContainer(*this))
{
	initialize();
}


GameInstance::~GameInstance()
{
	delete ct, pe, mc;
}

MapContainer& GameInstance::getMapContainer()
{
	return *mc;
}

PlayerEntity& GameInstance::getPlayerEntity()
{
	return *pe;
}

Controller& GameInstance::getController()
{
	return *ct;
}

void GameInstance::updateTime()
{
	double temp = currentTime;
	currentTime = glfwGetTime();
	deltaTime = currentTime - temp;
}

double GameInstance::getDeltaTime()
{
	return deltaTime;
}


void GameInstance::initialize()
{

	if (!glfwInit()){
		fprintf(stderr, "GLFW initialization failed!\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);

	currentTime = glfwGetTime();

	if (glewInit() != GLEW_OK){
		fprintf(stderr, "GLEW initialization failed!\n");
		exit(EXIT_FAILURE);
	}

}


glm::mat4& GameInstance::getPerspectiveMat()
{
	return perspectiveMat;
}