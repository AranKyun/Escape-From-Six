#include "Room.h"


Room::Room(GameInstance& gi_t, ShaderProgram& sp_t, int objectID_t, int** doorID_t):Graph(gi_t, sp_t, objectID_t)
{
	vboType = VBO_ROOM;
	rotateAnime = false;
	translationAnime = false;
	doorAndRoomID = doorID_t;

	scale = 1.0;
	initRotateAngle = 0.0;
	initRotateAxis = glm::vec3(0, 0, 0);


}


Room::~Room()
{
}
