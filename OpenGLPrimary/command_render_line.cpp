#include "command/command_render_line.h"

LH_NAMESPACE_BEGIN

void RenderLineCommand::Render()
{
	glLineWidth(4.0f); //�����߿�
	glBegin(GL_LINES); //ÿ���������һ����
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(-3.0f, 0.0f, -10.0f);

	glVertex3f(-3.0f, 0.0f, -10.0f);
	glVertex3f(-3.0f, -2.0f, -10.0f);
	glEnd();
}

LH_NAMESPACE_END