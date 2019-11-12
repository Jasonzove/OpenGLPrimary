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
	glDisable(GL_DEPTH_TEST);
	glPushMatrix();
	glTranslatef(mX, mY, mZ); //����պи����������ʹ����������պ�

	glBindTexture(GL_TEXTURE_2D, mSkyBox->mFront->mTextureId);

	glColor4ub(255, 255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); //��������
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();
	glPopMatrix();
}

void RenderSkyBoxCommand::Init_i()
{
	mSkyBox = new SkyBox();
	mSkyBox->Init("res/skybox");
}

LH_NAMESPACE_END