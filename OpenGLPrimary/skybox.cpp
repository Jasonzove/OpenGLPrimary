#include "skybox.h"

void SkyBox::Init(const char * const & pFolderPath)
{
	char filePath[128];
	memset(filePath, 0, 128 * sizeof(char));
	//front
	std::strcat(filePath, pFolderPath);
	std::strcat(filePath, "/front.bmp");
	mFront = Texture::LoadTexture(filePath);
	mFront->mFilePath = filePath;
	//left
	memset(filePath, 0, 128 * sizeof(char));
	std::strcat(filePath, pFolderPath);
	std::strcat(filePath, "/left.bmp");
	mLeft = Texture::LoadTexture(filePath);
	mLeft->mFilePath = filePath;
	//back
	memset(filePath, 0, 128 * sizeof(char));
	std::strcat(filePath, pFolderPath);
	std::strcat(filePath, "/back.bmp");
	mBack = Texture::LoadTexture(filePath);
	mBack->mFilePath = filePath;
	//right
	memset(filePath, 0, 128 * sizeof(char));
	std::strcat(filePath, pFolderPath);
	std::strcat(filePath, "/right.bmp");
	mRight = Texture::LoadTexture(filePath);
	mRight->mFilePath = filePath;
	//top
	memset(filePath, 0, 128 * sizeof(char));
	std::strcat(filePath, pFolderPath);
	std::strcat(filePath, "/top.bmp");
	mTop = Texture::LoadTexture(filePath);
	mTop->mFilePath = filePath;
	//bottom
	memset(filePath, 0, 128 * sizeof(char));
	std::strcat(filePath, pFolderPath);
	std::strcat(filePath, "/bottom.bmp");
	mBottom = Texture::LoadTexture(filePath);
	mBottom->mFilePath = filePath;

	//�ŵ����ﲻ��ÿ�λ��ƶ���������
	mDisplayList.Init([&]()->void {
		//front
		glBindTexture(GL_TEXTURE_2D, mFront->mTextureId);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, -0.5f, -0.5f);

		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);

		//left
		glBindTexture(GL_TEXTURE_2D, mLeft->mTextureId);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(-0.5f, -0.5f, -0.5f);

		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);

		//back
		glBindTexture(GL_TEXTURE_2D, mBack->mTextureId);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(-0.5f, -0.5f, 0.5f);

		glTexCoord2f(0.0, 1.0);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);

		//right
		glBindTexture(GL_TEXTURE_2D, mRight->mTextureId);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, -0.5f, 0.5f);

		glTexCoord2f(0.0, 1.0);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);

		//top
		glBindTexture(GL_TEXTURE_2D, mTop->mTextureId);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, 0.5f, -0.5f);

		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);

		//bottom
		glBindTexture(GL_TEXTURE_2D, mBottom->mTextureId);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, -0.5f, 0.5f);

		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	});
}

void SkyBox::Draw(const int& x, const int& y, const int& z)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST); //��ǰdepth=1.0Ϊ��Զ�����ڹر���Ȳ��ԣ��������л��Ƶ����嶼���Ը�ס��ǰ����
	glPushMatrix();
	glTranslatef(x, y, z); //����������ƶ�
		
	mDisplayList.Draw();

	glPopMatrix();


}
