
/*
	2016.01.30
	Created by PHJ.
*/

#ifndef _PHS_SUB_MESH_CPP

#define _PHS_SUB_MESH_CPP

#include "PHsSubMesh.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsResource
	{
		using namespace std;

		SubMesh::SubMesh(BinaryReader &sNewBinaryReader) :
			sSubMeshName{sNewBinaryReader.readWSTRING()},
			sSubMeshMaterialName{sNewBinaryReader.readWSTRING()}
		{
			Float *pVertexBuffer = new Float[this->nSubMeshVertexCount = sNewBinaryReader.readUINT()];

			for(uInt nIndex = 0u ; nIndex < this->nSubMeshVertexCount ; ++nIndex)
				pVertexBuffer[nIndex] = sNewBinaryReader.readFLOAT();

			Float *pNormalBuffer = new Float[this->nSubMeshNormalCount = sNewBinaryReader.readUINT()];

			for(uInt nIndex = 0u ; nIndex < this->nSubMeshNormalCount ; ++nIndex)
				pNormalBuffer[nIndex] = sNewBinaryReader.readFLOAT();

			Float *pTexCoordBuffer = new Float[this->nSubMeshTexCoordCount = sNewBinaryReader.readUINT()];

			for(uInt nIndex = 0u ; nIndex < this->nSubMeshTexCoordCount ; ++nIndex)
				pTexCoordBuffer[nIndex] = sNewBinaryReader.readFLOAT();

			Float *pTangentBuffer;

			if(this->nSubMeshTangentCount = sNewBinaryReader.readUINT())
			{
				pTangentBuffer = new Float[this->nSubMeshTangentCount];

				for(uInt nIndex = 0u ; nIndex < this->nSubMeshTangentCount ; ++nIndex)
					pTangentBuffer[nIndex] = sNewBinaryReader.readFLOAT();
			}
			else
				pTangentBuffer = nullptr;

			uInt *pIndexBuffer = new uInt[this->nSubMeshIndexCount = sNewBinaryReader.readUINT()];

			for(uInt nIndex = 0u ; nIndex < this->nSubMeshIndexCount ; ++nIndex)
				pIndexBuffer[nIndex] = sNewBinaryReader.readUINT();

			this->sSubMeshVertexBuffer.initializeVideoBuffer();
			VideoBuffer::activeVideoBuffer(this->sSubMeshVertexBuffer);
			VideoBuffer::specifyVideoBuffer(VideoBufferUsage::BufferUsage_StaticDraw, this->nSubMeshVertexCount * sizeof(Float), pVertexBuffer);

			this->sSubMeshNormalBuffer.initializeVideoBuffer();
			VideoBuffer::activeVideoBuffer(this->sSubMeshNormalBuffer);
			VideoBuffer::specifyVideoBuffer(VideoBufferUsage::BufferUsage_StaticDraw, this->nSubMeshNormalCount * sizeof(Float), pNormalBuffer);

			this->sSubMeshTexCoordBuffer.initializeVideoBuffer();
			VideoBuffer::activeVideoBuffer(this->sSubMeshTexCoordBuffer);
			VideoBuffer::specifyVideoBuffer(VideoBufferUsage::BufferUsage_StaticDraw, this->nSubMeshTexCoordCount * sizeof(Float), pTexCoordBuffer);

			if(pTangentBuffer)
			{
				this->sSubMeshTangentBuffer.initializeVideoBuffer();
				VideoBuffer::activeVideoBuffer(this->sSubMeshTangentBuffer);
				VideoBuffer::specifyVideoBuffer(VideoBufferUsage::BufferUsage_StaticDraw, this->nSubMeshTangentCount * sizeof(Float), pTangentBuffer);
			}

			this->sSubMeshIndexBuffer.initializeVideoBuffer();
			VideoBuffer::activeVideoBuffer(this->sSubMeshIndexBuffer);
			VideoBuffer::specifyVideoBuffer(VideoBufferUsage::BufferUsage_StaticDraw, this->nSubMeshIndexCount * sizeof(uInt), pIndexBuffer);

			delete[] pVertexBuffer;
			delete[] pNormalBuffer;
			delete[] pTexCoordBuffer;

			if(pTangentBuffer)
				delete[] pTangentBuffer;

			delete[] pIndexBuffer;

			this->nSubMeshVertexCount /= 3u;
			this->nSubMeshNormalCount /= 3u;
			this->nSubMeshTexCoordCount /= 2u;
			this->nSubMeshTangentCount /= 3u;
		}

		SubMesh::SubMesh(SubMesh &&sNewSubMesh) :
			nSubMeshVertexCount{sNewSubMesh.nSubMeshVertexCount},
			nSubMeshNormalCount{sNewSubMesh.nSubMeshNormalCount},
			nSubMeshTexCoordCount{sNewSubMesh.nSubMeshTexCoordCount},
			nSubMeshTangentCount{sNewSubMesh.nSubMeshTangentCount},
			nSubMeshIndexCount{sNewSubMesh.nSubMeshIndexCount},

			pSubMeshMaterialPointer{sNewSubMesh.pSubMeshMaterialPointer},

			sSubMeshVertexBuffer{move(sNewSubMesh.sSubMeshVertexBuffer)},
			sSubMeshNormalBuffer{move(sNewSubMesh.sSubMeshNormalBuffer)},
			sSubMeshTexCoordBuffer{move(sNewSubMesh.sSubMeshTexCoordBuffer)},
			sSubMeshTangentBuffer{move(sNewSubMesh.sSubMeshTangentBuffer)},
			sSubMeshIndexBuffer{move(sNewSubMesh.sSubMeshIndexBuffer)},
			sSubMeshVideoBufferSlot{move(sNewSubMesh.sSubMeshVideoBufferSlot)},

			sSubMeshName{move(sNewSubMesh.sSubMeshName)},
			sSubMeshMaterialName{move(sNewSubMesh.sSubMeshMaterialName)}
		{
			//Empty.
		}

		SubMesh &SubMesh::operator=(SubMesh &&sNewSubMesh)
		{
			this->nSubMeshVertexCount = sNewSubMesh.nSubMeshVertexCount;
			this->nSubMeshNormalCount = sNewSubMesh.nSubMeshNormalCount;
			this->nSubMeshTexCoordCount = sNewSubMesh.nSubMeshTexCoordCount;
			this->nSubMeshTangentCount = sNewSubMesh.nSubMeshTangentCount;
			this->nSubMeshIndexCount = sNewSubMesh.nSubMeshIndexCount;

			this->pSubMeshMaterialPointer = sNewSubMesh.pSubMeshMaterialPointer;

			this->sSubMeshVertexBuffer = move(sNewSubMesh.sSubMeshVertexBuffer);
			this->sSubMeshNormalBuffer = move(sNewSubMesh.sSubMeshNormalBuffer);
			this->sSubMeshTexCoordBuffer = move(sNewSubMesh.sSubMeshTexCoordBuffer);
			this->sSubMeshTangentBuffer = move(sNewSubMesh.sSubMeshTangentBuffer);
			this->sSubMeshIndexBuffer = move(sNewSubMesh.sSubMeshIndexBuffer);
			this->sSubMeshVideoBufferSlot = move(sNewSubMesh.sSubMeshVideoBufferSlot);

			this->sSubMeshName = move(sNewSubMesh.sSubMeshName);
			this->sSubMeshMaterialName = move(sNewSubMesh.sSubMeshMaterialName);

			return *this;
		}

		Void SubMesh::initializeVideoBufferSlot(uInt nNewVertexIndex, uInt nNewNormalIndex, uInt nNewTexCoordIndex, uInt nNewTangentIndex)
		{
			this->sSubMeshVideoBufferSlot.initializeVideoBufferSlot();
			VideoBufferSlot::activeVideoBufferSlot(this->sSubMeshVideoBufferSlot);

			if(nNewVertexIndex != maxValue <uInt>())
			{
				VideoBuffer::activeVideoBuffer(this->sSubMeshVertexBuffer);
				VideoBufferSlot::enableVideoBufferSlot(nNewVertexIndex);
				VideoBufferSlot::specifyVideoBufferSlot(nNewVertexIndex, VideoBufferSlotType::BufferSlotType_Vector3, VideoBufferSlotLife::SlotLife_Per_Vertex);
			}

			if(nNewNormalIndex != maxValue <uInt>())
			{
				VideoBuffer::activeVideoBuffer(this->sSubMeshNormalBuffer);
				VideoBufferSlot::enableVideoBufferSlot(nNewNormalIndex);
				VideoBufferSlot::specifyVideoBufferSlot(nNewNormalIndex, VideoBufferSlotType::BufferSlotType_Vector3, VideoBufferSlotLife::SlotLife_Per_Vertex);
			}

			if(nNewTexCoordIndex != maxValue <uInt>())
			{
				VideoBuffer::activeVideoBuffer(this->sSubMeshTexCoordBuffer);
				VideoBufferSlot::enableVideoBufferSlot(nNewTexCoordIndex);
				VideoBufferSlot::specifyVideoBufferSlot(nNewTexCoordIndex, VideoBufferSlotType::BufferSlotType_Vector2, VideoBufferSlotLife::SlotLife_Per_Vertex);
			}

			if(nNewTangentIndex != maxValue <uInt>())
			{
				VideoBuffer::activeVideoBuffer(this->sSubMeshTangentBuffer);
				VideoBufferSlot::enableVideoBufferSlot(nNewTangentIndex);
				VideoBufferSlot::specifyVideoBufferSlot(nNewTangentIndex, VideoBufferSlotType::BufferSlotType_Vector3, VideoBufferSlotLife::SlotLife_Per_Vertex);
			}
		}

		Void SubMesh::finalizeVideoBufferSlot()
		{
			this->sSubMeshVideoBufferSlot.finalizeVideoBufferSlot();
		}
	}
}

#endif