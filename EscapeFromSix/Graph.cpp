#include "Graph.h"
#include "ShaderProgram.h"
#include <vector>
#include <fstream>

using namespace std;




Graph::Graph(GameInstance& gi_t, ShaderProgram& sp_t, int objectID_t) : gi(gi_t), sp(sp_t)
{
	objectID = objectID_t;

	init();
}


Graph::~Graph()
{
}


void Graph::init()
{

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glBindBuffer(GL_ARRAY_BUFFER, gi.getVBOContainer().searchVBO(vboType));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertexInfo), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertexInfo), (void*)(3 * sizeof(GLfloat)));

	glBindVertexArray(0);
}


void Graph::updateMVP()
{
	glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(scale)); //放缩
	model = glm::rotate(initRotateAngle, initRotateAxis) * model; //初始化旋转
	if (rotateAnime == true)
		model = glm::rotate(animeRotateAngle, animeRotateAxis) * model; //动画旋转

	model = glm::translate(glm::vec3(locationX, locationY, locationZ)) * model; //向固定位置平移
	if (translationAnime == true)
		model = glm::translate(glm::vec3(translationX, translationY, translationZ)) * model; //动画平移

	MVP = gi.getPerspectiveMat() * gi.getPlayerEntity().getViewMat() * model;
}


void Graph::draw()
{
	glUseProgram(sp.getProgramID());
	glBindVertexArray(vaoID);
	glUniformMatrix4fv(sp.getMvpID(), 1, GL_FALSE, &(MVP[0][0]));
	glDrawArrays(GL_TRIANGLES, 0, nFace * 3);
	glBindVertexArray(0);
	glUseProgram(0);

	
}


void Graph::setLocationXYZ(float X, float Y, float Z)
{
	locationX = X;
	locationY = Y;
	locationZ = Z;
}