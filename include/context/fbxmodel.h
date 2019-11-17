/*
==============================
*Copyright(c), huan.liu, 2019
*All rights reversed

*Author:huanliu_uestc@163.com

*FileName:fbxmodel.h
*Brief: fbxmodel

*Date: 2019.11.17
==============================
*/

#ifndef __FBXMODEL_H__
#define __FBXMODEL_H__

#include <windows.h>
#include <vector>
#include <unordered_map>
#include "gl/GL.h"
#include "common_macrosh.h"
#include "fbxsdk.h"
#include "context/vector3f.h"
#include "context/vertex.h"


LH_NAMESPACE_BEGIN

struct Mat
{
	int mType; //0:lambert, 1:phong, other:lambert
	char mDiffuseColorTexture[256]; //��������������ֻ��������������Ϊ��ţͷ�ˣ��ܶණ����ʡ����
};

class LH_EXPORT FBXModel
{
protected:
	void ImportNode(FbxNode* node);

	void ImportMaterial(FbxNode* node);

	void ImportMesh(FbxMesh* mesh);
public:
	void Init(const char* const& filePath);

	void Draw();

public:
	VertexData* mVertexs;

	char mFBXPath[256];

	std::vector<Mat*> mMaterials; //unique mat

	std::unordered_map<int, int> mMaterialIndexes;

private:
	void ImportPositions_i(FbxGeometryBase* geometry, std::vector<Vector3f>& positions);
};

LH_NAMESPACE_END

#endif