/*
==============================
*Copyright(c), huan.liu, 2019
*All rights reversed

*Author:huanliu_uestc@163.com

*FileName:camera.h
*Brief: camera

*Date: 2019.11.7
==============================
*/

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "context/vector3f.h"
#include "common_macrosh.h"

LH_NAMESPACE_BEGIN

class LH_EXPORT Camera
{
public:
	Camera();

public:
	Vector3f mEye;
	Vector3f mViewCenter;
	Vector3f mUp;
	bool mIsMoveLeft;
	bool mIsMoveRight;
	bool mIsMoveForward;
	bool mIsMoveBackward;
	/******2D,3D�����******/
	int mViewPortWidth;
	int mViewPortHeight;

public:
	void Update(float deltaTime);
	void Pitch(float angele);

	/******2D,3D�����******/
	void SwitchTo3D();
	void SwitchTo2D();

private:
	void RotateView_i(float angle, float x, float y, float z);
};

LH_NAMESPACE_END

#endif