#include "texture.h"
#include "utlis.h"

void Texture::Init(const char * const & pFilePath)
{
	//load file content
	unsigned char* pFileContent = nullptr;
	pFileContent = LoadFileContent(pFilePath);
	if (pFilePath == nullptr)
	{
		//��־
	}

	//decode data
	unsigned char* pPixelData = nullptr;
	int width = 0;
	int height = 0;
	pPixelData = DecodeBMP(pFileContent, width, height);
	if (pPixelData == nullptr)
	{
		//��־
	}

	//��������
	glGenTextures(1, &mTextureId); //����1������
	glBindTexture(GL_TEXTURE_2D, mTextureId); //���õ�ǰ����
	//�����������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pPixelData); //�����ݴ����Կ�
	glBindTexture(GL_TEXTURE_2D, 0); //���꽫��������Ϊ0

	//delete[] pFileContent; pFileContent = nullptr;
	return;
}
