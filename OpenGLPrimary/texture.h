#pragma once
#include <windows.h>
#include<gl/GL.h> //Ҫʹ�������������<windows.h>

class Texture
{
public:
	void Init(const char* const& pFilePath);

	GLuint mTextureId;
};
