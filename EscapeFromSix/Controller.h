#pragma once
#include "GameInstance.h"

class GameInstance;

class Controller
{

	float deltaX; //X��λ��
	float deltaZ; //Z��λ��
	GameInstance& gi; //��GameInstance������

public:

	Controller(GameInstance&);
	~Controller();
	
	void getKey(); //�Լ������Ĳ������м�����Ӧ
	void calMove(); //����λ��
	void calViewDir(); //�����ӽǱ仯

};

