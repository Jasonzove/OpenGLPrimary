#pragma once
#include "vector3f.h"

class Camera
{
public:
	Camera();
	void Update(float deltaTime);
	void Pitch(const float& angle); //������ת:X
	void Yam(const float& angle); //���ң�Y
	//void Roll(const float& angle); //Z
	void SwitchTo2D();
	void SwitchTo3D();
public:
	Vector3f mPos, mViewCenter, mUp;
	bool mMoveLeft, mMoveRight, mMoveFoward, mMoveBackWord;
	int viewPortWidth, viewPortHeight;

protected:
	void RotateView(const float& angle, const float& x, const float& y, const float& z);
};