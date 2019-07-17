#include "command/command_render_line_strip.h"

LH_NAMESPACE_BEGIN

void RenderLineStripCommand::Render()
{
	glLineWidth(4.0f); //�����߿�
	glBegin(GL_LINE_STRIP); //�����е���������������һ��Ȧ
	glColor4ub(255.0, 0.0, 0.0, 255.0);//���õ�ǰ��ɫ
	glVertex3f(0.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 255.0, 0.0, 255.0);
	glVertex3f(-3.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 0.0, 255.0, 255.0);
	glVertex3f(-3.0f, -2.0f, -10.0f);
	glEnd();
}

LH_NAMESPACE_END