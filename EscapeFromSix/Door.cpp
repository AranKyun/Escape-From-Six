#include "Door.h"


Door::Door(GameInstance& gi_t, ShaderProgram& sp_t, int objectID_t, float rotateAngle) :Graph(gi_t, sp_t, objectID_t)
{
	vboType = VBO_DOOR;
	rotateAnime = false;
	translationAnime = false;

	scale = 1.0;
	initRotateAngle = rotateAngle;

}


Door::~Door()
{
}
