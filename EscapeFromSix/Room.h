#pragma once
#include "Graph.h"
class Room :
	public Graph
{
	
	int** doorAndRoomID; //�����������������ID��ͨ��ķ���ID

public:
	Room(GameInstance&, ShaderProgram&, int, int**);
	~Room();
};

