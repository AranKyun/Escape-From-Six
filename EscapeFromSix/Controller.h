#pragma once
#include "GameInstance.h"

class GameInstance;

class Controller
{

	float deltaX; //X��λ��
	float deltaZ; //Z��λ��
	GameInstance& gi; //��GameInstance������

	GLFWwindow* window;//��Ϸ����ָ��ĸ���

public:

	Controller(GameInstance&);
	~Controller();
	
	void getControl(); //�Լ������Ĳ������м�����Ӧ
	void calMove(); //����λ��
	void calViewDir(); //�����ӽǱ仯

};

