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

	printf("%s\n", pFileContent);
	return pFileContent;
}
