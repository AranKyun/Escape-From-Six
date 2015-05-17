#pragma once

#include "GameInstance.h"

class GameInstance;

class PlayerEntity
{

	float horiAngle; //�ӽ�ˮƽ��
	float vertAngle; //�ӽ���ֱ��

	bool jumping; //������Ծ���

	GameInstance& gi;


public:

	PlayerEntity(GameInstance&);
	~PlayerEntity();

	void jump(); //��Ծ�����м���Y

	void dropItem(); //������Ʒ
	int getItemHeld(); //��ȡ������ƷID
	void pickUpItem(); //ʰ����Ʒ

	void useItemInteract(); //�����������ｻ���ķ�ʽʹ����Ʒ
	void useItemSelf(); //ʹ����Ʒ������

	bool isMovingLocked(); //�����ж��Ƿ�����
	void setMovingLocked(bool); //���������ж�

	bool isViewLocked(); //������Ұ�Ƿ�����
	void setViewLocked(bool); //����������Ұ

	void setView(float, float); //�����ӽ�
	void addView(float, float); //�����ӽ�
	float getHoriAngle(); //��ȡˮƽ�ӽ�
	float getVertAngle(); //��ȡ��ֱ�ӽ�

};

