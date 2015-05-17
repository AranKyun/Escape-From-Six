#pragma once

#include "MapContainer.h"
#include "PlayerEntity.h"
#include "Controller.h"



class GameInstance
{
	MapContainer mc;
	PlayerEntity pe;
	Controller ct;

	float currentTime;
	float deltaTime;

public:
	GameInstance();
	~GameInstance();

	MapContainer& getMapContainer();
	PlayerEntity& getPlayerEntity();
	Controller& getController();

	void updateTime();
	float getDeltaTime();

};

