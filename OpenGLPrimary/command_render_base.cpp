#include "command/command_render_base.h"
#include "context/texture.h"
#include "context/context_helper.h"

LH_NAMESPACE_BEGIN

void RenderCommandBase::Render()
{

}

void RenderCommandBase::Init()
{
	glMatrixMode(GL_PROJECTION);//�ú����������õ�ǰ����GL_PROJECTION:ͶӰ����
	gluPerspective(50.0f /*�Ƕ�*/, 800 / 600/*������߱�*/, 0.1f/*��������ľ���*/, 1000.0f/*��Զ�����ľ���*/);//�ú���Ӱ�쵱ǰ����Ҳ����˵�����˵�ǰ����
	glMatrixMode(GL_MODELVIEW);//����ǰ�������ó�ģ���ӿھ���
	glLoadIdentity();//����ģ���ӿھ��������ã�����һ����λ����
}

void RenderCommandBase::InitTexture()
{
	Texture textture;
	textture.Init("text.bmp");
}

LH_NAMESPACE_END