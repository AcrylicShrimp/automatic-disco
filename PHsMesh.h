
/*
	2016.01.30
	Created by PHJ.
*/

#ifndef _PHS_MESH_H

#define _PHS_MESH_H

#include "PHsCommon.h"
#include "PHsBinaryReader.h"
#include "PHsMaterial.h"
#include "PHsSubMesh.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsResource
	{
		class Mesh final
		{
		public:
			using MaterialVector = std::vector <Material>;
			using SubMeshVector = std::vector <SubMesh>;
			using MaterialNameMap = std::unordered_map <std::wstring, Material *>;

		private:
			MaterialVector sMeshMaterialVector;
			SubMeshVector sMeshSubMeshVector;
			MaterialNameMap sMeshMaterialNameMap;

		public:
			Mesh() = default;
			Mesh(Mesh &&sNewMesh);
			Mesh(const Mesh &sNewMesh) = delete;
			~Mesh() = default;

		public:
			Mesh &operator=(Mesh &&sNewMesh);
			Mesh &operator=(const Mesh &sNewMesh) = delete;

			Void loadMesh(const std::wstring &sNewPath);
			Void unloadMesh();
			Void initializeVideoBufferSlot(uInt nNewVertexIndex, uInt nNewNormalIndex, uInt nNewTexCoordIndex, uInt nNewTangentIndex);
			Void finalizeVideoBufferSlot();

			inline const MaterialVector &meshMaterialVector() const;
			inline const SubMeshVector &meshSubMeshVector() const;
			inline const MaterialNameMap &meshMaterialNameMap() const;
		};
		
		inline const Mesh::MaterialVector &Mesh::meshMaterialVector() const
		{
			return this->sMeshMaterialVector;
		}

		inline const Mesh::SubMeshVector &Mesh::meshSubMeshVector() const
		{
			return this->sMeshSubMeshVector;
		}

		inline const Mesh::MaterialNameMap &Mesh::meshMaterialNameMap() const
		{
			return this->sMeshMaterialNameMap;
		}
	}
}

#endif