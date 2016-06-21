
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_MATERIAL_H

#define _PHS_MATERIAL_H

#include "PHsCommon.h"
#include "PHsBinaryReader.h"
#include "PHsTexture.h"
#include "PHsTexture2D.h"
#include "PHsTextureManager.h"

#include <fstream>
#include <memory.h>
#include <string>
#include <utility>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsResource
	{
		class Material final
		{
		public:
			std::wstring sMaterialName;
			Float vAmbientColor[4];
			Float vDiffuseColor[4];
			Float vSpeculerColor[4];
			Float nSpecularExponent;
			Float nTransparent;
			std::wstring sDiffuseTexturePath;
			std::wstring sSpecularTexturePath;
			std::wstring sSpecularHighlightTexturePath;
			std::wstring sTransparentTexturePath;
			std::wstring sNormalMapTexturePath;
			Texture2D *pDiffuseTexture;
			Texture2D *pSpecularTexture;
			Texture2D *pSpecularHighlightTexture;
			Texture2D *pTransparentTexture;
			Texture2D *pNormalMapTexture;

		public:
			Material(BinaryReader &sNewBinaryReader, const std::wstring &sNewMeshPath);
			Material(Material &&sNewMaterial);
			Material(const Material &sNewMaterial);
			~Material();

		public:
			Material &operator=(Material &&sNewMaterial);
			Material &operator=(const Material &sNewMaterial);
		};
	}
}

#endif