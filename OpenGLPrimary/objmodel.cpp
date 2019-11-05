#include <stdio.h>
#include <sstream>
#include "context/objmodel.h"
#include "context/context_helper.h"

LH_NAMESPACE_BEGIN

void ObjModel::Init(const char* objModel)
{
	unsigned char* pFileContent = ContextHelper::LoadFileContent(objModel);
	//�ҳ����õ���Ϣ��V:���� Vt:�������� Vn�����ߣ�f: face 
	std::stringstream ssFileContent((char*)pFileContent);
	char onlineContent[256]; //һ������
	while (!ssFileContent.eof())
	{
		memset(onlineContent, 0, 256);
		ssFileContent.getline(onlineContent, 256);

		if (strlen(onlineContent) > 0) //���в���
		{
			switch (*onlineContent)
			{
			case 'v':
				if (*(onlineContent + 1) == 't')
				{
					printf("texure:%s\n", onlineContent);
				}
				else if(*(onlineContent + 1) == 'n')
				{
					printf("normal:%s\n", onlineContent);
				}
				else
				{
					printf("vertex:%s\n", onlineContent);
				}
				break;
			case 'f':
				printf("face:%s\n", onlineContent);
				break;
			default:
				break;
			}
		}
	}

	DEL_PTR(pFileContent);

}


LH_NAMESPACE_END