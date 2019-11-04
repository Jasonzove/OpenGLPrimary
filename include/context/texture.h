/*
==============================
*Copyright(c), huan.liu, 2019
*All rights reversed

*Author:huanliu_uestc@163.com

*FileName:texture.h
*Brief: texture

*Date: 2019.11.3
==============================
*/

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <windows.h>
#include <gl/GL.h> //ע�⣺windows.h���������ǰ��
#include "common_macrosh.h"

LH_NAMESPACE_BEGIN

class LH_EXPORT Texture
{
public:
	Texture() {};
	~Texture() {};
	void Init(const char* pImagePath);

public:
	GLuint mTextureId; //gpu,ͨ����ID�����ҵ�����

};

LH_NAMESPACE_END

#endif