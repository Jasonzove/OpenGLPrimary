#include "command/command_render_quads.h"

LH_NAMESPACE_BEGIN

void RenderQuadsCommand::Render()
{
	glBegin(GL_QUADS); //ÿ�ĸ��㻭һ�������
	glColor4ub(255.0, 0.0, 0.0, 255.0);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 255.0, 0.0, 255.0);
	glVertex3f(-5.0f, -2.0f, -10.0f);
	glColor4ub(0.0, 0.0, 255.0, 255.0);
	glVertex3f(-3.0f, -3.0f, -10.0f);
	glColor4ub(0.0, 66.0, 255.0, 255.0);
	glVertex3f(2.0f, -2.0f, -10.0f);
	glEnd();
}

LH_NAMESPACE_END