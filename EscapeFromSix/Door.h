#pragma once
#include "Graph.h"
class Door :
	public Graph
{

public:
	Door(GameInstance&, ShaderProgram&, int, float);
	~Door();
};

