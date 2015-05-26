#pragma once

#include "Graph.h"

struct ObjectLink{
	int objectID;
	Graph* objectPtr;
	ObjectLink* nextPtr;
};


class DrawContainer
{

	ObjectLink* first;
	ObjectLink* last;

public:
	DrawContainer();
	~DrawContainer();

	void push_back(int, Graph*);
	void deleteObject(int);

	void drawAll();
};

