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
void PlayerEntity::jump()
{
   if(jumping);
   else{
        jumping=ture;
        jumptime=gi.getCurrentTime();
        }
}
float  PlayerEntity::distanceCaculate()
  {
   if (jumping)
   {
   t=gi.getCurrentTime()-jumpTime;
   playerY=vt-1/2*g*t^2;
   }
}
   
   y=vt-1/2*g*currentTime^2;
   return y;
}
void PlayerEntity::dropItem()
{
    if(gi.getMapContainer().dropItemFromPlayer())
    heldItemID=-1;
}
int PlayerEntity::getItemHeld()
{
	return heldItemID;
}
void PlayEntity::pickUpItem()
{
	int item=gi.getMapContainer().searchItemAround();
	if(item=-1);
	else{
		headItemID=item;
	}
}
void PlayEntity::useItemInteract()
{
	
}
void PlayEntity::useItemSelf()
{
	
}
bool PlayEntity::isViewLocked()
{
	
} 
void PlayEntity::setViewLocked(bool)
{
	
}
void PlayEntity::setView(float newHoriAngle, float newVertAngle)
{
	horiAngle = newHoriAngle;
	vertAngle = newVertAngle;
}
void PlayEntity::addView(float newHoriAngle, float newVertAngle)
{
	horiAngle = horiAngle+newHoriAngle;
	vertAngle = vertAngle+newVertAngle;
}
float PlayEntity::getHoriAngle()
{
	return horiAngle;
}
float PlayEntity::getVertAngle()
{
	return vertAngle;
}












