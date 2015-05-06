#pragma once

class PlayerEntity
{

	float x; //x坐标
	float y; //y坐标
	float z; //z坐标
	float horiAngle; //视角水平角
	float vertAngle; //视角竖直角


public:

	PlayerEntity();
	~PlayerEntity();

	//获取X、Z
	float getX();
	float getZ();
	//设置X、Z
	void setX(float);
	void setZ(float);
	//自增X、Z
	void addX(float);
	void addZ(float);

	float getY(); //获取Y

	void jump(); //跳跃过程中计算Y

	void dropItem(); //丢弃物品
	int getItemHeld(); //获取所持物品ID
	void pickUpItem(); //拾起物品

	void useItemInteract(); //以与其他事物交互的方式使用物品
	void useItemSelf(); //使用物品自身功能

};

