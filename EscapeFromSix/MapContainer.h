#pragma once

#include "GameInstance.h"

class MapContainer
{
	GameInstance& gi;
public:
	MapContainer(GameInstance&);
	~MapContainer();

	void updatePlayerPosition(float, float); //参数是deltaX, deltaZ，是坐标增量，这里需要检查是否合法，若合法则更新数据


};

