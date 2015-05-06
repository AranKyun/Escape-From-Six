#pragma once

class PlayerEntity
{

	float x; //x����
	float y; //y����
	float z; //z����
	float horiAngle; //�ӽ�ˮƽ��
	float vertAngle; //�ӽ���ֱ��


public:

	PlayerEntity();
	~PlayerEntity();

	//��ȡX��Z
	float getX();
	float getZ();
	//����X��Z
	void setX(float);
	void setZ(float);
	//����X��Z
	void addX(float);
	void addZ(float);

	float getY(); //��ȡY

	void jump(); //��Ծ�����м���Y

	void dropItem(); //������Ʒ
	int getItemHeld(); //��ȡ������ƷID
	void pickUpItem(); //ʰ����Ʒ

	void useItemInteract(); //�����������ｻ���ķ�ʽʹ����Ʒ
	void useItemSelf(); //ʹ����Ʒ������

};

