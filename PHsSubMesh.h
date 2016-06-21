
/*
	2016.01.30
	Created by PHJ.
*/

#ifndef _PHS_SUB_MESH_H

#define _PHS_SUB_MESH_H

#include "PHsCommon.h"
#include "PHsBinaryReader.h"
#include "PHsMaterial.h"
#include "PHsOpenGLExt.h"
#include "PHsVideoBuffer.h"
#include "PHsVideoBufferSlot.h"

#include <string>
#include <utility>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsResource
	{
		class SubMesh final
		{
		public:
			uInt nSubMeshVertexCount;
			uInt nSubMeshNormalCount;
			uInt nSubMeshTexCoordCount;
			uInt nSubMeshTangentCount;
			uInt nSubMeshIndexCount;
			const Material *pSubMeshMaterialPointer{nullptr};
			VideoBuffer sSubMeshVertexBuffer{VideoBufferType::BufferType_Array};
			VideoBuffer sSubMeshNormalBuffer{VideoBufferType::BufferType_Array};
			VideoBuffer sSubMeshTexCoordBuffer{VideoBufferType::BufferType_Array};
			VideoBuffer sSubMeshTangentBuffer{VideoBufferType::BufferType_Array};
			VideoBuffer sSubMeshIndexBuffer{VideoBufferType::BufferType_Element};
			VideoBufferSlot sSubMeshVideoBufferSlot;
			std::wstring sSubMeshName;
			std::wstring sSubMeshMaterialName;

		public:
			SubMesh(BinaryReader &sNewBinaryReader);
			SubMesh(SubMesh &&sNewSubMesh);
			SubMesh(const SubMesh &sNewSubMesh) = delete;
			~SubMesh() = default;

		public:
			SubMesh &operator=(SubMesh &&sNewSubMesh);
			SubMesh &operator=(const SubMesh &sNewSubMesh) = delete;

			Void initializeVideoBufferSlot(uInt nNewVertexIndex, uInt nNewNormalIndex, uInt nNewTexCoordIndex, uInt nNewTangentIndex);
			Void finalizeVideoBufferSlot();
		};
	}
}

#endif