#include <stdio.h>
#include "utlis.h"

unsigned char * LoadFileContent(const char * const & pFilePath)
{
	unsigned char* pFileContent = nullptr;
	FILE* pFile = nullptr;
	fopen_s(&pFile, pFilePath, "rb");
	if (pFile == nullptr)
	{
		return pFileContent;
	}

	fseek(pFile, 0, SEEK_END); //�����ļ�ĩβ
	int len = ftell(pFile); //ȡ�ó���
	if (len > 0)
	{
		rewind(pFile); //����ͷ��
		pFileContent = new unsigned char[len + 1];
		fread(pFileContent, sizeof(unsigned char), len, pFile);
		pFileContent[len] = '\0';
	}

	fclose(pFile);

	//printf("%s\n", pFileContent);
	return pFileContent;
}

unsigned char * DecodeBMP(unsigned char * const & pFileContent, int & width, int & height)
{
	unsigned char* pPixelData = nullptr;
	if (pFileContent == nullptr)
	{
		return pPixelData;
	}

	int pixelDataOffeset = *((int*)(pFileContent + 10));
	width = *((int*)(pFileContent + 18));
	height = *((int*)(pFileContent + 22));
	pPixelData = (unsigned char*)(pFileContent + pixelDataOffeset);
	if (pPixelData == nullptr)
	{
		//��־
		return pPixelData;
	}

	//bgr -> rgb
	for (int i = 0; i < width*height*3; i += 3)
	{
		pPixelData[i] = pPixelData[i] ^ pPixelData[i + 2];
		pPixelData[i+2] = pPixelData[i] ^ pPixelData[i + 2];
		pPixelData[i] = pPixelData[i] ^ pPixelData[i + 2];
	}

	return pPixelData;
}
