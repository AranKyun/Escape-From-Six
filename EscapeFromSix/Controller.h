#pragma once
#include "GameInstance.h"

class GameInstance;

class Controller
{

	float deltaX; //X轴位移
	float deltaZ; //Z轴位移
	GameInstance& gi; //对GameInstance的引用

	GLFWwindow* window;//游戏窗口指针的副本

public:

	Controller(GameInstance&);
	~Controller();
	
	void getControl(); //对键盘鼠标的操作进行检查和响应
	void calMove(); //计算位移
	void calViewDir(); //计算视角变化

};

