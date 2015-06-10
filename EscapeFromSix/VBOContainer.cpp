#include "VBOContainer.h"


VBOContainer::VBOContainer()
{
}


VBOContainer::~VBOContainer()
{
}


GLuint VBOContainer::searchVBO(VBO_TYPE vtype)
{
	if (vtype == VBO_NULL)
		return -1;
	if (vboList[vtype] == nullptr)
		vboList[vtype] = new VBO(objPaths[vtype]);
	return vboList[vtype]->getVBOID();
}
                                                                             