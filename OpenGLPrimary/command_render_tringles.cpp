#include "command/command_render_tringles.h"

LH_NAMESPACE_BEGIN

void RenderTringlesCommand::Render()
{
	glBegin(GL_TRIANGLES); //Ĭ����ʱ�뷽��ccw:contour clock wise��
	glColor4ub(255.0, 0.0, 0.0, 255.0);//���õ�ǰ��ɫ
	glVertex3f(0.0f, 0.0f, -10.0f); //ÿ���������һ�������Σ����Ի����������
	glColor4ub(0.0, 255.0, 0.0, 255.0);
	glVertex3f(-3.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 0.0, 255.0, 255.0);
	glVertex3f(-3.0f, -2.0f, -10.0f);

	glColor4ub(255.0, 0.0, 0.0, 255.0);
	glVertex3f(3.0f, 0.0f, -10.0f); 
	glColor4ub(0.0, 255.0, 0.0, 255.0);
	glVertex3f(3.0f-3.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 0.0, 255.0, 255.0);
	glVertex3f(3.0f-3.0f, -2.0f, -10.0f);
	glEnd();

	////����������ʹ����CW
	//glEnable(GL_CULL_FACE); //ֻ��ʾ���棨CW�����������Ч�ʣ����û���������
	//glFrontFace(GL_CW); //���Խ�Ĭ������ĳ�CW����
	//glBegin(GL_TRIANGLES); 
	//glColor4ub(255.0, 0.0, 0.0, 255.0);
	//glVertex3f(0.0f, 0.0f, -10.0f);
	//glColor4ub(0.0, 0.0, 255.0, 255.0);
	//glVertex3f(-3.0f, -2.0f, -10.0f);
	//glColor4ub(0.0, 255.0, 0.0, 255.0);
	//glVertex3f(-3.0f, 0.0f, -10.0f);
	//glEnd();
}

LH_NAMESPACE_END