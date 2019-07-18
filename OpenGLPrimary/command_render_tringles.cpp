#include "command/command_render_tringles.h"

LH_NAMESPACE_BEGIN

void RenderTringlesCommand::Render()
{
	glBegin(GL_TRIANGLES); //Ĭ����ʱ�뷽��ccw��
	glColor4ub(255.0, 0.0, 0.0, 255.0);//���õ�ǰ��ɫ
	glVertex3f(0.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 255.0, 0.0, 255.0);
	glVertex3f(-3.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 0.0, 255.0, 255.0);
	glVertex3f(-3.0f, -2.0f, -10.0f);
	glEnd();
}

LH_NAMESPACE_END