
/*
	2016.01.30
	Created by PHJ.
*/

#ifndef _PHS_MESH_CPP

#define _PHS_MESH_CPP

#include "PHsMesh.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsResource
	{
		using namespace std;

		Mesh::Mesh(Mesh &&sNewMesh) :
			sMeshMaterialVector{move(sNewMesh.sMeshMaterialVector)},
			sMeshSubMeshVector{move(sNewMesh.sMeshSubMeshVector)},
			sMeshMaterialNameMap{move(sNewMesh.sMeshMaterialNameMap)}
		{
			//Empty.
		}

		Mesh &Mesh::operator=(Mesh &&sNewMesh)
		{
			this->sMeshMaterialVector = move(sNewMesh.sMeshMaterialVector);
			this->sMeshSubMeshVector = move(sNewMesh.sMeshSubMeshVector);
			this->sMeshMaterialNameMap = move(sNewMesh.sMeshMaterialNameMap);

			return *this;
		}

		Void Mesh::loadMesh(const wstring &sNewPath)
		{
			if(sNewPath.length() < 2u || sNewPath[1] != L':')
				return;

			BinaryReader sReader{sNewPath};

			if(!sReader.readerOpened())
				return;

			Char vSignature[8]
			{
				//Empty.
			};

			sReader.readCHAR(vSignature, 8u);
			
			if(vSignature[0] != 'P' ||
				vSignature[1] != 'H' ||
				vSignature[2] != 'S' ||
				vSignature[3] != '_' ||
				vSignature[4] != 'M' ||
				vSignature[5] != 'E' ||
				vSignature[6] != 'S' ||
				vSignature[7] != 'H')
				return;

			uInt nCount = sReader.readUINT();
			this->sMeshMaterialVector.reserve(nCount);

			const wstring sPath = sNewPath.substr(0u, sNewPath.find_last_of(L"\\/") + 1u);

			for(uInt nIndex = 0u ; nIndex < nCount ; ++nIndex)
			{
				this->sMeshMaterialVector.emplace_back(sReader, sPath);
				this->sMeshMaterialNameMap[this->sMeshMaterialVector.back().sMaterialName] = &this->sMeshMaterialVector.back();
			}

			nCount = sReader.readUINT();
			this->sMeshSubMeshVector.reserve(nCount);

			for(uInt nIndex = 0u ; nIndex < nCount ; ++nIndex)
			{
				this->sMeshSubMeshVector.emplace_back(sReader);
				auto iIndex = this->sMeshMaterialNameMap.find(this->sMeshSubMeshVector.back().sSubMeshMaterialName);
				
				if(iIndex != this->sMeshMaterialNameMap.end())
					this->sMeshSubMeshVector.back().pSubMeshMaterialPointer = iIndex->second;
			}
		}

		Void Mesh::unloadMesh()
		{
			this->sMeshMaterialVector.clear();
			this->sMeshSubMeshVector.clear();
			this->sMeshMaterialNameMap.clear();
		}

		Void Mesh::initializeVideoBufferSlot(uInt nNewVertexIndex, uInt nNewNormalIndex, uInt nNewTexCoordIndex, uInt nNewTangentIndex)
		{
			for(SubMesh &sSubMesh : this->sMeshSubMeshVector)
				sSubMesh.initializeVideoBufferSlot(nNewVertexIndex, nNewNormalIndex, nNewTexCoordIndex, nNewTangentIndex);
		}

		Void Mesh::finalizeVideoBufferSlot()
		{
			for(SubMesh &sSubMesh : this->sMeshSubMeshVector)
				sSubMesh.finalizeVideoBufferSlot();
		}
	}
}

#endif