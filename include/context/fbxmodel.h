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
#include "gl/GL.h"
#include "common_macrosh.h"
#include "fbxsdk.h"
#include "context/vector3f.h"
#include "context/vertex.h"


LH_NAMESPACE_BEGIN

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

private:
	void ImportPositions_i(FbxGeometryBase* geometry, std::vector<Vector3f>& positions);
};

LH_NAMESPACE_END

#endif