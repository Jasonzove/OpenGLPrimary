#include "texture.h"
#include "utlis.h"
#include "soil.h"

std::unordered_map<std::string, Texture*> Texture::mTextures;

void Texture::Init(const char * const & pFilePath, bool invertY)
{
	int flags = SOIL_FLAG_POWER_OF_TWO;
	if (invertY)
	{
		flags |= SOIL_FLAG_INVERT_Y;
	}
	/*********************SOIL�⴦��ͼ��***************************/
	mTextureId = SOIL_load_OGL_texture(pFilePath, 0, 0, flags);
	mFilePath = pFilePath;
	return;
	/*********************SOIL�⴦��ͼ��***************************/
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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pPixelData); //�����ݴ����Կ�
	glBindTexture(GL_TEXTURE_2D, 0); //���꽫��������Ϊ0

	//delete[] pFileContent; pFileContent = nullptr;
	return;
}

Texture* Texture::LoadTexture(const char* const& pFilePath, bool invertY)
{
	if (mTextures.find(pFilePath) != mTextures.end())
	{
		return mTextures[pFilePath];
	}

	Texture* texture = new Texture();
	texture->Init(pFilePath,invertY);
	mTextures.insert(std::make_pair(pFilePath, texture));

	return texture;
}

void Texture::UnLoadTexture(const Texture*& ptexture)
{
	auto iter = mTextures.find(ptexture->mFilePath);
	if (iter != mTextures.end())
	{
		mTextures.erase(iter);
		glDeleteTextures(1, &iter->second->mTextureId);
		delete(ptexture);
		ptexture = nullptr;
	}
}
