#include "DrawContainer.h"


DrawContainer::DrawContainer()
{
}


DrawContainer::~DrawContainer()
{
}


void DrawContainer::push_back(int objectID, Graph* objectPtr)
{
	if (first == nullptr)
		first = last = new ObjectLink;
	else{
		last->nextPtr = new ObjectLink;
		last = last->nextPtr;
	}
	last->objectID = objectID;
	last->objectPtr = objectPtr;
}


void DrawContainer::deleteObject(int objectID)
{
	if (first->objectID == objectID){
		ObjectLink* temp = first;
		first = first->nextPtr;
		delete temp;
	}
	else{
		ObjectLink* searchPtr = first;
		while (searchPtr->nextPtr->objectID != objectID)
			searchPtr = searchPtr->nextPtr;
		if (searchPtr->nextPtr == last){
			delete last;
			last = searchPtr;
			last->nextPtr = nullptr;
		}
		else{
			ObjectLink* temp = searchPtr->nextPtr;
			searchPtr->nextPtr = searchPtr->nextPtr->nextPtr;
			delete temp;
		}
	}
}


void DrawContainer::drawAll(){
	ObjectLink* searchPtr = first;
	while (searchPtr == nullptr){
		searchPtr->objectPtr->draw();
		searchPtr = searchPtr->nextPtr;
	}
}