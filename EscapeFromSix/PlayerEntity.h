#pragma once

#include "GameInstance.h"
#include <glm\glm.hpp>

class GameInstance;

class PlayerEntity
{
      float playerY; 
      
    int heldItemID;
	float horiAngle; //�ӽ�ˮƽ��
	float vertAngle; //�ӽ���ֱ��

	bool jumping; //������Ծ����
	double jumpTime;
	
	int y;
	const gravity = 9.8;
    const speed = 3.1;  

	glm::mat4 viewMat; //�۲�����

	GameInstance& gi;


public:

	PlayerEntity(GameInstance&);
	~PlayerEntity();
    
	void jump(); //��Ծ�����м���Y
    float distanceCaculate();
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
   
	void updateViewMat(); //�ؼ����۲�����
	glm::mat4& getViewMat(); //��ȡ�۲�����
    
};

