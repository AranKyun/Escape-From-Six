#include "PlayerEntity.h"


PlayerEntity::PlayerEntity(GameInstance& g) :gi(g)
{
	
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
     //test code
}
