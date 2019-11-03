#include "command/command_render_pan_rotate_zoom_matrix_light.h"

LH_NAMESPACE_BEGIN

void RenderPanRotateZoomMatrixLightCommand::Render()
{
	///*****************ƽ�ƣ���ת������*******************/
	////glLoadIdentity(); //��֤ÿ�ν������ǵ�λ����
	//glPushMatrix();
	////glScalef(2.0f, 2.0f, 0.5f); //����
	//glTranslatef(2.0f, -2.0f, 0.0f);
	//glRotatef(30, 0.0f, 0.0f, 1.0f);//������������Ĵָָ���Լ�����ȭ��������ת����
	//glBegin(GL_TRIANGLES);
	//glColor4ub(255, 0, 0, 255);
	//glVertex3f(0.0f, 1.0f, -20.0f);

	//glColor4ub(0, 255, 0, 255);
	//glVertex3f(-1.0f, 0.0f, -20.0f);

	//glColor4ub(0, 0, 255, 255);
	//glVertex3f(1.0f, 0.0f, -20.0f);
	//glEnd();
	//glPopMatrix();


	/*****************����*******************/
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	glEnable(GL_LIGHTING); //��������
	glEnable(GL_LIGHT0); //���ù�Դ
	//glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, 1.0, 0.0); //�����ߣ������������
	glVertex3f(-1.0f, -0.5f, -2.0f);

	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(1.0f, -0.5f, -2.0f);


	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, -0.5f, -10.0f);
	glEnd();
	glPopMatrix();
}

LH_NAMESPACE_END