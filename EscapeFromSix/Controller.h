#pragma once
class Controller
{
	float deltaX; //X��λ��
	float deltaZ; //Z��λ��
	GameInstance& gi; //��GameInstance������
public:
	Controller();
	~Controller();

	void getKey(); //�Լ������Ĳ������м�����Ӧ
	void calMove(); //����λ��
	void calViewDir(); //�����ӽǱ仯
};

