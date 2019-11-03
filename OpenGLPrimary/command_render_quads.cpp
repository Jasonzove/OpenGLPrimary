#include "command/command_render_quads.h"

LH_NAMESPACE_BEGIN

void RenderQuadsCommand::Render()
{
	///*****************GL_QUADS***********************/
	//glBegin(GL_QUADS); //ÿ�ĸ��㻭һ�������
	//glColor4ub(255.0, 0.0, 0.0, 255.0);
	//glVertex3f(0.0f, 0.0f, -10.0f);
	//glColor4ub(0.0, 255.0, 0.0, 255.0);
	//glVertex3f(-5.0f, -2.0f, -10.0f);
	//glColor4ub(0.0, 0.0, 255.0, 255.0);
	//glVertex3f(-3.0f, -3.0f, -10.0f);
	//glColor4ub(0.0, 66.0, 255.0, 255.0);
	//glVertex3f(2.0f, -2.0f, -10.0f);

	//glColor4ub(255.0, 0.0, 0.0, 255.0);
	//glVertex3f(1.0f, 0.0f, -10.0f);
	//glColor4ub(0.0, 255.0, 0.0, 255.0);
	//glVertex3f(1-5.0f, -2.0f, -10.0f);
	//glColor4ub(0.0, 0.0, 255.0, 255.0);
	//glVertex3f(1-3.0f, -3.0f, -10.0f);
	//glColor4ub(0.0, 66.0, 255.0, 255.0);
	//glVertex3f(1+2.0f, -2.0f, -10.0f);
	//glEnd();

	///*****************GL_QUAD_STRIP***********************/
	//glBegin(GL_QUAD_STRIP); //1-2-4-3, 3-4-6-5
	//glColor4ub(255.0, 0.0, 0.0, 255.0);
	//glVertex3f(0.0f, 0.0f, -10.0f);
	//glColor4ub(0.0, 255.0, 0.0, 255.0);
	//glVertex3f(-5.0f, -2.0f, -10.0f);
	//glColor4ub(0.0, 66.0, 255.0, 255.0);
	//glVertex3f(2.0f, -2.0f, -10.0f);
	//glColor4ub(0.0, 0.0, 255.0, 255.0);
	//glVertex3f(-3.0f, -3.0f, -10.0f);
	//glColor4ub(0.0, 0.0, 255.0, 255.0);
	//glVertex3f(3.0f, 3.0f, -10.0f);
	//glColor4ub(0.0, 66.0, 255.0, 255.0);
	//glVertex3f(4.0f, -3.0f, -10.0f);
	//glEnd();

	///****************GL_POLYGON************************/
	//glBegin(GL_POLYGON); //��������
	//glColor4ub(255.0, 0.0, 0.0, 255.0);
	//glVertex3f(0.0f, 0.0f, -10.0f);
	//glColor4ub(0.0, 255.0, 0.0, 255.0);
	//glVertex3f(-5.0f, -2.0f, -10.0f);
	//glColor4ub(0.0, 0.0, 255.0, 255.0);
	//glVertex3f(-3.0f, -3.0f, -10.0f);
	//glColor4ub(0.0, 66.0, 255.0, 255.0);
	//glVertex3f(2.0f, -2.0f, -10.0f);
	//glEnd();

	/*****************�߿�ģʽ***********************/
	//glPolygonMode(GL_FRONT, GL_LINE);//�߿�ģʽ

	//glPointSize(20);
	//glPolygonMode(GL_FRONT, GL_POINT);
	//glEnable(GL_POINT_SMOOTH); //�����Բ
	////������ܱ�Բ����Ҫ����blend
	//glEnable(GL_BLEND);//�ҵĻ��ӿ��Ա�Բ

	glBegin(GL_POLYGON); //��������
	glColor4ub(255.0, 0.0, 0.0, 255.0);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glColor4ub(0.0, 255.0, 0.0, 255.0);
	glVertex3f(-4.0f, -2.0f, -10.0f);
	glColor4ub(0.0, 0.0, 255.0, 255.0);
	glVertex3f(-3.0f, -3.0f, -10.0f);
	glColor4ub(0.0, 66.0, 255.0, 255.0);
	glVertex3f(2.0f, -2.0f, -10.0f);
	glEnd();
}

LH_NAMESPACE_END