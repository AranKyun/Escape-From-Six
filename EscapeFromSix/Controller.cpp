#include "Controller.h"


Controller::Controller(GameInstance& g) :gi(g)
{
	window = gi.getWindow();
}


Controller::~Controller()
{
}


void Controller::getControl()
{
}