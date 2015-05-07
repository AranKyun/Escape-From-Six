#pragma once

#include "GameInstance.h"

class PlayerEntity
{

	float horiAngle; //视角水平角
	float vertAngle; //视角竖直角

	bool jumping; //正在跳跃与否

	GameInstance& gi;


public:

	PlayerEntity(GameInstance&);
	~PlayerEntity();

	void jump(); //跳跃过程中计算Y

	void dropItem(); //丢弃物品
	int getItemHeld(); //获取所持物品ID
	void pickUpItem(); //拾起物品

	void useItemInteract(); //以与其他事物交互的方式使用物品
	void useItemSelf(); //使用物品自身功能

	bool isMovingLocked(); //人物行动是否锁定
	void setMovingLocked(bool); //锁定人物行动

	bool isViewLocked(); //人物视野是否锁定
	void setViewLocked(bool); //锁定人物视野

	void setView(float, float); //设置视角
	void addView(float, float); //自增视角
	float getHoriAngle(); //获取水平视角
	float getVertAngle(); //获取竖直视角

};

