#include "GameInstance.h"
#include <glfw3.h>


GameInstance::GameInstance() :ct(Controller(*this)), pe(PlayerEntity(*this)), mc(MapContainer(*this))
{
	currentTime = glfwGetTime();
}


GameInstance::~GameInstance()
{
}

MapContainer& GameInstance::getMapContainer()
{
	return mc;
}

PlayerEntity& GameInstance::getPlayerEntity()
{
	return pe;
}

Controller& GameInstance::getController()
{
	return ct;
}

void GameInstance::updateTime()
{
	float temp = currentTime;
	currentTime = glfwGetTime();
	deltaTime = currentTime - temp;
}

float GameInstance::getDeltaTime()
{
	return deltaTime;
}