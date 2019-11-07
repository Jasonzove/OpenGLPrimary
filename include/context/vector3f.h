﻿/*
==============================
*Copyright(c), huan.liu, 2019
*All rights reversed

*Author:huanliu_uestc@163.com

*FileName:vector3f.h
*Brief: vector3f model

*Date: 2019.11.7
==============================
*/

#ifndef __VECTOR3F_H__
#define __VECTOR3F_H__

#include "common_macrosh.h"
#include <math.h>

LH_NAMESPACE_BEGIN

class LH_EXPORT Vector3f
{
public:
	Vector3f(float x, float y, float z);

	union
	{
		struct
		{
			float x, y, z;
		};

		float v[3];
	};
};

LH_NAMESPACE_END

#endif