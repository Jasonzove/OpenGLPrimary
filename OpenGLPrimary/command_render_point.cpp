#include "command/command_render_point.h"

LH_NAMESPACE_BEGIN

void RenderPointCommand::Render()
{
	glPointSize(20.0f); //Ĭ�ϴ�СΪ1.0f,̫С��������
	glBegin(GL_POINTS);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.0f, 0.0f, -0.5f);
	glEnd();
}

LH_NAMESPACE_END