#pragma once

#include "GameInstance.h"

class MapContainer
{
	GameInstance& gi;
public:
	MapContainer(GameInstance&);
	~MapContainer();

	void updatePlayerPosition(float, float); //������deltaX, deltaZ��������������������Ҫ����Ƿ�Ϸ������Ϸ����������


};

