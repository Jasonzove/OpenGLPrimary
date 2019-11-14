#include "context/displaylist.h"



LH_NAMESPACE_BEGIN

void DisplayList::Init(std::function<void()> foo)
{
	mDisplayList = glGenLists(1); //�½���ʾ�б�

	//������ʾ�б�ִ�еĶ���
	glNewList(mDisplayList, GL_COMPILE);
	foo();
	glEndList();
}

void DisplayList::Draw()
{
	glCallList(mDisplayList); //��ʾ�б����
}


LH_NAMESPACE_END