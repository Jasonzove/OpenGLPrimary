#include "command/command_render_skybox.h"
#include "common_macrosh.h"


LH_NAMESPACE_BEGIN

RenderSkyBoxCommand::~RenderSkyBoxCommand()
{
	DEL_PTR(mSkyBox);
}

void RenderSkyBoxCommand::Render()
{
	glDisable(GL_LIGHTING);
	//glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST); //ʲô����Ȳ��ԣ������Ϣ�������ڵ����ص㡣�����Խ�������ֵԽС����֮Խ��glDisable(GL_DEPTH_TEST)���Ժ����ֵ����ı�
	glPushMatrix();
	glTranslatef(mX, mY, mZ); //����պи����������ʹ����������պ�

	mSkyBox->mDisplayList.Draw(); //��ʾ�б����

	glPopMatrix();
}

void RenderSkyBoxCommand::Init_i()
{
	mSkyBox = new SkyBox();
	mSkyBox->Init("res/skybox");
}

LH_NAMESPACE_END