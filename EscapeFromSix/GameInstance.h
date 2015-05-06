#pragma once

#include "MapContainer.h"
#include "PlayerEntity.h"
#include "Controller.h"

class GameInstance
{
	MapContainer& mc;
	PlayerEntity& pe;
	Controller& ct;
public:
	GameInstance();
	~GameInstance();
};

