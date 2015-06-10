#pragma once

#include "GameInstance.h"
#include <glm\glm.hpp>

class GameInstance;

class PlayerEntity
{
<<<<<<< HEAD
	float playerX;
	float playerY;
	float playerZ;

	int heldItemID;
=======
      float playerY; 
      
    int heldItemID;
	float horiAngle; //ï¿½Ó½ï¿½Ë®Æ½ï¿½ï¿½
	float vertAngle; //ï¿½Ó½ï¿½ï¿½ï¿½Ö±ï¿½ï¿½
>>>>>>> origin/master

	bool jumping; //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô¾ï¿½ï¿½ï¿½ï¿½
	double jumpTime;
	
	int y;
	const gravity = 9.8;
    const speed = 3.1;  

	glm::mat4 viewMat; //ï¿½Û²ï¿½ï¿½ï¿½ï¿½ï¿½

	GameInstance& gi;


public:

	PlayerEntity(GameInstance&);
	~PlayerEntity();
<<<<<<< HEAD

	void jump(); //ÌøÔ¾¹ý³ÌÖÐ¼ÆËãY£¬ÔÝÊ±²»×ö

	void dropItem(); //¶ªÆúÎïÆ·£¬Í¨Öªmc¶ªÆú×ø±ê
	int getItemHeld(); //»ñÈ¡Ëù³ÖÎïÆ·ID
	void pickUpItem(); //Ê°ÆðÎïÆ·

	void useItemInteract(); //ÒÔÓëÆäËûÊÂÎï½»»¥µÄ·½Ê½Ê¹ÓÃÎïÆ·
	void useItemSelf(); //Ê¹ÓÃÎïÆ·×ÔÉí¹¦ÄÜ

	bool isMovingLocked(); //ÈËÎïÐÐ¶¯ÊÇ·ñËø¶¨
	void setMovingLocked(bool); //Ëø¶¨ÈËÎïÐÐ¶¯

	bool isViewLocked(); //ÈËÎïÊÓÒ°ÊÇ·ñËø¶¨
	void setViewLocked(bool); //Ëø¶¨ÈËÎïÊÓÒ°

	void setView(float, float); //ÉèÖÃÊÓ½Ç
	void addView(float, float); //×ÔÔöÊÓ½Ç
	float getHoriAngle(); //»ñÈ¡Ë®Æ½ÊÓ½Ç
	float getVertAngle(); //»ñÈ¡ÊúÖ±ÊÓ½Ç

	void updateViewMat(); //ÖØ¼ÆËã¹Û²ì¾ØÕó
	glm::mat4& getViewMat(); //»ñÈ¡¹Û²ì¾ØÕó
=======
    
	void jump(); //ï¿½ï¿½Ô¾ï¿½ï¿½ï¿½ï¿½ï¿½Ð¼ï¿½ï¿½ï¿½Y
    float distanceCaculate();
	void dropItem(); //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ·
	int getItemHeld(); //ï¿½ï¿½È¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ·ID
	void pickUpItem(); //Ê°ï¿½ï¿½ï¿½ï¿½Æ·

	void useItemInteract(); //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï½»ï¿½ï¿½ï¿½Ä·ï¿½Ê½Ê¹ï¿½ï¿½ï¿½ï¿½Æ·
	void useItemSelf(); //Ê¹ï¿½ï¿½ï¿½ï¿½Æ·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½

	bool isMovingLocked(); //ï¿½ï¿½ï¿½ï¿½ï¿½Ð¶ï¿½ï¿½Ç·ï¿½ï¿½ï¿½ï¿½ï¿½
	void setMovingLocked(bool); //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð¶ï¿½

	bool isViewLocked(); //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò°ï¿½Ç·ï¿½ï¿½ï¿½ï¿½ï¿½
	void setViewLocked(bool); //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò°

	void setView(float, float); //ï¿½ï¿½ï¿½ï¿½ï¿½Ó½ï¿½
	void addView(float, float); //ï¿½ï¿½ï¿½ï¿½ï¿½Ó½ï¿½
	float getHoriAngle(); //ï¿½ï¿½È¡Ë®Æ½ï¿½Ó½ï¿½
	float getVertAngle(); //ï¿½ï¿½È¡ï¿½ï¿½Ö±ï¿½Ó½ï¿½
   
	void updateViewMat(); //ï¿½Ø¼ï¿½ï¿½ï¿½ï¿½Û²ï¿½ï¿½ï¿½ï¿½ï¿½
	glm::mat4& getViewMat(); //ï¿½ï¿½È¡ï¿½Û²ï¿½ï¿½ï¿½ï¿½ï¿½
    
>>>>>>> origin/master
};

