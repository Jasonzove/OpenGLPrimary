#include "command/command_render_line_loop.h"

LH_NAMESPACE_BEGIN

void RenderLineLoopCommand::Render()
{
	glLineWidth(4.0f); //�����߿�
	glBegin(GL_LINE_LOOP); //�����е�����һ��Ȧ
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(-3.0f, 0.0f, -10.0f);
	glVertex3f(-3.0f, -2.0f, -10.0f);
	glEnd();
}

LH_NAMESPACE_END