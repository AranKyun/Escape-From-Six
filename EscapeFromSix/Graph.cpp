#include "Graph.h"
#include "ShaderProgram.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vertexInfo* Graph::vertices = nullptr; //��û�м��ع�obj�Ļ�����ָ��Ӧ��Ϊ��ָ��

const char* Graph::objPath = ""; //objģ��·���ɸ�����ָ��



Graph::Graph(GameInstance& gi_t, ShaderProgram& sp_t, int objectID_t) : gi(gi_t), sp(sp_t)
{
	objectID = objectID_t;

	nFace = 0;
	vertices = loadObj(objPath);
	if (vertices == nullptr)
		vertices = loadObj(objPath);
	

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	GLuint vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertexInfo), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertexInfo), (void*)(3 * sizeof(GLfloat)));

	glBindVertexArray(0);

}


Graph::~Graph()
{
	delete vertices;
}


vertexInfo* Graph::loadObj(const char* objPath)
{
	ifstream infile;
	infile.open(objPath);

	int nCoordinate = 0;
	int nNormal = 0;

	/*ͳ�����ꡢ���ߡ��������*/
	string s;
	while (getline(infile, s)){
		if (s[0] == 'v'){
			if (s[1] == 'n')
				nNormal++;
			else
				nCoordinate++;
		}
		else if (s[0] == 'f')
			nFace++;
	}

	infile.close();
	infile.open(objPath);

	GLfloat* coo = new GLfloat[nCoordinate * 3];
	GLfloat* nor = new GLfloat[nNormal * 3];
	vertexInfo* ver = new vertexInfo[nFace * 3];

	/*����������д��������*/
	char tmp[4];
	int i = 0, j = 0, k = 0;
	while (getline(infile, s)){
		if (s[0] == 'v'){
			if (s[1] == 'n'){
				int a = sscanf_s(s.c_str(), "%s %f %f %f", tmp, 3, &nor[i], &nor[i + 1], &nor[i + 2]);
				i += 3;
			}
			else {
				int a = sscanf_s(s.c_str(), "%s %f %f %f", tmp, 3, &coo[j], &coo[j + 1], &coo[j + 2]);
				j += 3;
			}

		}
		else if (s[0] == 'f'){
			int c[3], n[3];
			sscanf_s(s.c_str(), "%s %d//%d %d//%d %d//%d", tmp, 2, &c[0], &n[0], &c[1], &n[1], &c[2], &n[2]);
			for (int p = 0; p < 3; p++) {
				ver[k].coordinate[0] = coo[c[p] * 3 - 3];
				ver[k].coordinate[1] = coo[c[p] * 3 - 2];
				ver[k].coordinate[2] = coo[c[p] * 3 - 1];
				ver[k].normal[0] = nor[n[p] * 3 - 3];
				ver[k].normal[1] = nor[n[p] * 3 - 2];
				ver[k].normal[2] = nor[n[p] * 3 - 1];
				k++;
			}

		}
	}

	infile.close();

	delete coo;
	delete nor;

	return ver;

}


void Graph::updateMVP()
{
	glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(scale)); //����
	model = glm::rotate(initRotateAngle, initRotateAxis) * model; //��ʼ����ת
	if (rotateAnime == true)
		model = glm::rotate(animeRotateAngle, animeRotateAxis) * model; //������ת

	model = glm::translate(glm::vec3(locationX, locationY, locationZ)) * model; //��̶�λ��ƽ��
	if (translationAnime == true)
		model = glm::translate(glm::vec3(translationX, translationY, translationZ)) * model; //����ƽ��

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