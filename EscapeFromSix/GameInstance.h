#pragma once

#include "MapContainer.h"
#include "PlayerEntity.h"
#include "Controller.h"
#include "glfw3.h"

#include <glm\glm.hpp>

class MapContainer;
class PlayerEntity;
class Controller;

class GameInstance
{
	MapContainer* mc;
	PlayerEntity* pe;
	Controller* ct;

	double currentTime;
	double deltaTime;

	GLFWwindow* window;

	glm::mat4 perspectiveMat;

	int width = 800;
	int height = 600;
	char* title = "title";

public:
	GameInstance();
	~GameInstance();

	MapContainer& getMapContainer();
	PlayerEntity& getPlayerEntity();
	Controller& getController();

	void updateTime();
	double getDeltaTime();

	glm::mat4& getPerspectiveMat();

	void initialize();
};

