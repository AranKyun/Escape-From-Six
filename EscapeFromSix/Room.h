#pragma once
#include "Graph.h"
class Room :
	public Graph
{
	
	int** doorAndRoomID; //这里存放六个方向的门ID和通向的房间ID

public:
	Room(GameInstance&, ShaderProgram&, int, int**);
	~Room();
};

