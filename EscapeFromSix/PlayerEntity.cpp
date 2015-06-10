#include "PlayerEntity.h"


PlayerEntity::PlayerEntity(GameInstance& g) :gi(g)
{
	heldItemID = -1;
}


PlayerEntity::~PlayerEntity()
{
}

glm::mat4& PlayerEntity::getViewMat()
{
	return viewMat;
}


void PlayerEntity::dropItem()
{
	if (gi.getMapContainer().dropItemFromPlayer())
		heldItemID = -1;
}


int PlayerEntity::getItemHeld()
{
	return heldItemID;
}

void PlayerEntity::pickUpItem()
{
	int item = gi.getMapContainer().searchItemAround();
	if (item == -1);
	else {
		heldItemID = item;
	}
}