#include "context/texture.h"
#include "context/context_helper.h"
#include "common_macrosh.h"

#include "soil.h"
#pragma comment(lib, "soil.lib")

LH_NAMESPACE_BEGIN

void Texture::Init(const char* pImagePath)
{
	/*******************��һ�ַ�ʽ����**********************/
	mTextureId = SOIL_load_OGL_texture(pImagePath, 0, 0, SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_INVERT_Y);
	mImagePath = pImagePath;
	return;

	/*******************�ڶ��ַ�ʽ����**********************/
	//����ͼƬ����
	unsigned char* pImageContent = nullptr;
	pImageContent = ContextHelper::LoadFileContent(pImagePath);
	if (pImageContent == nullptr)
	{
		//log
		return;
	}

	//����ͼƬ  -12.30
	unsigned char* pBmpData = nullptr;
	int width = 0;
	int height = 0;
	pBmpData = ContextHelper::DecodeBMP(pImageContent, width, height);//���������
	if (pBmpData == nullptr)
	{
		//log
		return;
	}

	//��������
	glGenTextures(1, &mTextureId);//����һ������
	glBindTexture(GL_TEXTURE_2D, mTextureId); //���õ�ǰ����
	//������ǰ����
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //�Ŵ���С���˷�ʽ�����Թ���
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);//��������0-1���������ֵĴ���ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);//repeatedģʽ��1.1��0.1ȡ������һ����һ������

	//�������������Դ�
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pBmpData);

	glBindTexture(GL_TEXTURE_2D, 0);

	DEL_PTR(pImageContent);
}

/**************************************************************************/

std::unordered_map<std::string, Texture*> Texture::mTextures;

Texture* Texture::LoadTextures(const char* pImagePath)
{
	if (mTextures.find(pImagePath) != mTextures.end())
	{
		return mTextures[pImagePath];
	}

	auto pTexture = new Texture();
	pTexture->Init(pImagePath);
	mTextures.insert(std::make_pair(pImagePath, pTexture));
	return pTexture;
}

void Texture::UnLoadTextures(Texture* pTexture)
{
	auto iter = mTextures.find(pTexture->mImagePath);
	if (iter != mTextures.end())
	{
		mTextures.erase(pTexture->mImagePath);
		glDeleteTextures(1, &(iter->second->mTextureId));
		delete pTexture;
	}
}

LH_NAMESPACE_END