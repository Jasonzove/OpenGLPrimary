#include "command/command_render_objmodel.h"


LH_NAMESPACE_BEGIN

void RenderObjModelCommand::Render()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT, GL_LINE); //�߿�ģʽ
	//��ת�Ƕ�
	//static float angle = 0.0;
	//if (angle > 360)
	//{
	//	angle = 0.0f;
	//}
	//angle += 0.2f;
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f); //???
	//glRotatef(angle, 0.0f, 1.0f, 0.0f);
	//glScalef(0.01f, 0.01f, 0.01f); //����
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture.mTextureId);
	/**************����***************/
	float blackColor[] = { 0.0f,0.0f,0.0f,1.0f };
	float whiteColor[] = { 1.0f,1.0f,1.0f,1.0f };
	float lightPos[] = { 0.0f,1.0f,0.0f,0.0f }; //������꣬���һλΪ0��ʾ����������Զ��
	glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos); //���ù�Դλ��

	float blakMat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float ambientMat[] = { 0.1f, 0.1f, 0.1f, 1.0f }; //������
	float diffuseMat[] = { 0.4f, 0.4f, 0.4f, 1.0f }; //�������
	float specularMat[] = { 0.9f, 0.9f, 0.9f, 1.0f }; //�������
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMat); //���ò���
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMat);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);
	//glMaterialf(GL_FRONT, GL_SHININESS, 60.0F); //�������ù��,��ֵԽ�󣬹��ԽС

	glEnable(GL_LIGHTING); //��������
	glEnable(GL_LIGHT0); //���ù�Դ
	/***************************************/


	glBegin(GL_TRIANGLES);

	for (int i = 0;  i < mObjModel.mIndicesCount; ++i)
	{
		//glVertex3f(mObjModel.mVertexes[mObjModel.mIndices[i]].mPosition[0], 
		//	mObjModel.mVertexes[mObjModel.mIndices[i]].mPosition[1], 
		//	mObjModel.mVertexes[mObjModel.mIndices[i]].mPosition[2]);
		glTexCoord2fv(mObjModel.mVertexes[mObjModel.mIndices[i]].mTexcoord);
		glNormal3fv(mObjModel.mVertexes[mObjModel.mIndices[i]].mNormal);
		glVertex3fv(mObjModel.mVertexes[mObjModel.mIndices[i]].mPosition);
	}

	glEnd();
	glPopMatrix();
}

void RenderObjModelCommand::Init_i()
{
	mObjModel.Init("./res/Sphere.obj");
	mTexture.Init("./res/earth.bmp");
}

LH_NAMESPACE_END