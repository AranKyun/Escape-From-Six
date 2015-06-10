#pragma once

#include "GameInstance.h"
#include "Graph.h"
#include "Room.h"

struct singleItem {
	singleItem* nextItem;
	int itemId;
	Graph* itemInstance;
};

const int roomAndDoorList[][6][2] = {
	{ { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 5, 6 } },
	{ { 12, -1 }, { 13, -1 }, { 6, 2 }, { 0, 0 }, { 11, 6 }, { 29, -1 } },
	{ { 14, -1 }, { 15, -1 }, { 16, -1 }, { 7, 3 }, { 1, 0 }, { 6, 1 } },
	{ { 7, 2 }, { 17, -1 }, { 18, -1 }, { 19, -1 }, { 8, 4 }, { 2, 0 } },
	{ { 3, 0 }, { 8, 3 }, { 20, -1 }, { 21, -1 }, { 22, -1 }, { 9, 5 } },
	{ { 10, 6 }, { 4, 0 }, { 9, 4 }, { 23, -1 }, { 24, -1 }, { 25, -1 } },
	{ { 28, -1 }, { 11, 1 }, { 5, 0 }, { 10, 5 }, { 26, -1 }, { 27, -1 } }
};


class GameInstance;

class MapContainer
{
	float playerX;
	float playerY;
	float playerZ;

	static const int nRoom = 7;
	Room roomList[nRoom];
	
	static const int nDoor = 30;
	Door doorList[nDoor];
	

	GameInstance& gi;
public:
	MapContainer(GameInstance&);
	~MapContainer();

	void updatePlayerPosition(float, float); //参数是deltaX, deltaZ，是坐标增量，这里需要检查是否合法，若合法则更新数据
	bool dropItemFromPlayer(); //从玩家丢弃物品至脚下

	int searchItemAround(); //寻找前方的最近物品


};

