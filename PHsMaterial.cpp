
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_MATERIAL_CPP

#define _PHS_MATERIAL_CPP

#include "PHsMaterial.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsResource
	{
		using namespace std;

		Material::Material(BinaryReader &sNewBinaryReader, const wstring &sNewMeshPath) :
			sMaterialName{sNewBinaryReader.readWSTRING()}
		{
			for(Float &nAmbientColor : this->vAmbientColor)
				nAmbientColor = sNewBinaryReader.readFLOAT();

			for(Float &nDiffuseColor : this->vDiffuseColor)
				nDiffuseColor = sNewBinaryReader.readFLOAT();

			for(Float &nSpeculerColor : this->vSpeculerColor)
				nSpeculerColor = sNewBinaryReader.readFLOAT();

			this->nSpecularExponent = sNewBinaryReader.readFLOAT();
			this->nTransparent = sNewBinaryReader.readFLOAT();

			if((this->sDiffuseTexturePath = sNewBinaryReader.readWSTRING()).length() < 2u || this->sDiffuseTexturePath[1] != L':')
				this->sDiffuseTexturePath = sNewMeshPath + this->sDiffuseTexturePath;

			if((this->sSpecularTexturePath = sNewBinaryReader.readWSTRING()).length() < 2u || this->sSpecularTexturePath[1] != L':')
				this->sSpecularTexturePath = sNewMeshPath + this->sSpecularTexturePath;

			if((this->sSpecularHighlightTexturePath = sNewBinaryReader.readWSTRING()).length() < 2u || this->sSpecularHighlightTexturePath[1] != L':')
				this->sSpecularHighlightTexturePath = sNewMeshPath + this->sSpecularHighlightTexturePath;

			if((this->sTransparentTexturePath = sNewBinaryReader.readWSTRING()).length() < 2u || this->sTransparentTexturePath[1] != L':')
				this->sTransparentTexturePath = sNewMeshPath + this->sTransparentTexturePath;

			if((this->sNormalMapTexturePath = sNewBinaryReader.readWSTRING()).length() < 2u || this->sNormalMapTexturePath[1] != L':')
				this->sNormalMapTexturePath = sNewMeshPath + this->sNormalMapTexturePath;

			TextureManager &sTextureManager = TextureManager::getManager();

			this->pDiffuseTexture = this->sDiffuseTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sDiffuseTexturePath, TexIntFormat::Int_RGB);
			this->pSpecularTexture = this->sSpecularTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sSpecularTexturePath, TexIntFormat::Int_RGB);
			this->pSpecularHighlightTexture = this->sSpecularHighlightTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sSpecularHighlightTexturePath, TexIntFormat::Int_RGB);
			this->pTransparentTexture = this->sTransparentTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sTransparentTexturePath, TexIntFormat::Int_RGB);
			this->pNormalMapTexture = this->sNormalMapTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sNormalMapTexturePath, TexIntFormat::Int_RGB);
		}

		Material::Material(Material &&sNewMaterial) :
			sMaterialName{move(sNewMaterial.sMaterialName)},

			sDiffuseTexturePath{move(sNewMaterial.sDiffuseTexturePath)},
			sSpecularTexturePath{move(sNewMaterial.sSpecularTexturePath)},
			sSpecularHighlightTexturePath{move(sNewMaterial.sSpecularHighlightTexturePath)},
			sTransparentTexturePath{move(sNewMaterial.sTransparentTexturePath)},
			sNormalMapTexturePath{move(sNewMaterial.sNormalMapTexturePath)},

			nSpecularExponent{sNewMaterial.nSpecularExponent},
			nTransparent{sNewMaterial.nTransparent},

			pDiffuseTexture{sNewMaterial.pDiffuseTexture},
			pSpecularTexture{sNewMaterial.pSpecularTexture},
			pSpecularHighlightTexture{sNewMaterial.pSpecularHighlightTexture},
			pTransparentTexture{sNewMaterial.pTransparentTexture},
			pNormalMapTexture{sNewMaterial.pNormalMapTexture}
		{
			memcpy_s(this->vAmbientColor, sizeof(this->vAmbientColor), sNewMaterial.vAmbientColor, sizeof(sNewMaterial.vAmbientColor));
			memcpy_s(this->vDiffuseColor, sizeof(this->vDiffuseColor), sNewMaterial.vDiffuseColor, sizeof(sNewMaterial.vDiffuseColor));
			memcpy_s(this->vSpeculerColor, sizeof(this->vSpeculerColor), sNewMaterial.vSpeculerColor, sizeof(sNewMaterial.vSpeculerColor));
		}

		Material::Material(const Material &sNewMaterial) :
			sMaterialName{sNewMaterial.sMaterialName},

			sDiffuseTexturePath{sNewMaterial.sDiffuseTexturePath},
			sSpecularTexturePath{sNewMaterial.sSpecularTexturePath},
			sSpecularHighlightTexturePath{sNewMaterial.sSpecularHighlightTexturePath},
			sTransparentTexturePath{sNewMaterial.sTransparentTexturePath},
			sNormalMapTexturePath{sNewMaterial.sNormalMapTexturePath},

			nSpecularExponent{sNewMaterial.nSpecularExponent},
			nTransparent{sNewMaterial.nTransparent},

			pDiffuseTexture{sNewMaterial.pDiffuseTexture},
			pSpecularTexture{sNewMaterial.pSpecularTexture},
			pSpecularHighlightTexture{sNewMaterial.pSpecularHighlightTexture},
			pTransparentTexture{sNewMaterial.pTransparentTexture},
			pNormalMapTexture{sNewMaterial.pNormalMapTexture}
		{
			memcpy_s(this->vAmbientColor, sizeof(this->vAmbientColor), sNewMaterial.vAmbientColor, sizeof(sNewMaterial.vAmbientColor));
			memcpy_s(this->vDiffuseColor, sizeof(this->vDiffuseColor), sNewMaterial.vDiffuseColor, sizeof(sNewMaterial.vDiffuseColor));
			memcpy_s(this->vSpeculerColor, sizeof(this->vSpeculerColor), sNewMaterial.vSpeculerColor, sizeof(sNewMaterial.vSpeculerColor));
		}

		Material::~Material()
		{
			TextureManager &sTextureManager = TextureManager::getManager();

			if(!this->sDiffuseTexturePath.empty())
				sTextureManager.releaseTexture(this->sDiffuseTexturePath);

			if(!this->sSpecularTexturePath.empty())
				sTextureManager.releaseTexture(this->sSpecularTexturePath);

			if(!this->sSpecularHighlightTexturePath.empty())
				sTextureManager.releaseTexture(this->sSpecularHighlightTexturePath);

			if(!this->sTransparentTexturePath.empty())
				sTextureManager.releaseTexture(this->sTransparentTexturePath);

			if(!this->sNormalMapTexturePath.empty())
				sTextureManager.releaseTexture(this->sNormalMapTexturePath);
		}

		Material &Material::operator=(Material &&sNewMaterial)
		{
			TextureManager &sTextureManager = TextureManager::getManager();

			if(!this->sDiffuseTexturePath.empty())
				sTextureManager.releaseTexture(this->sDiffuseTexturePath);

			if(!this->sSpecularTexturePath.empty())
				sTextureManager.releaseTexture(this->sSpecularTexturePath);

			if(!this->sSpecularHighlightTexturePath.empty())
				sTextureManager.releaseTexture(this->sSpecularHighlightTexturePath);

			if(!this->sTransparentTexturePath.empty())
				sTextureManager.releaseTexture(this->sTransparentTexturePath);

			if(!this->sNormalMapTexturePath.empty())
				sTextureManager.releaseTexture(this->sNormalMapTexturePath);

			this->sMaterialName = move(sNewMaterial.sMaterialName);
			this->sDiffuseTexturePath = move(sNewMaterial.sDiffuseTexturePath);
			this->sSpecularTexturePath = move(sNewMaterial.sSpecularTexturePath);
			this->sSpecularHighlightTexturePath = move(sNewMaterial.sSpecularHighlightTexturePath);
			this->sTransparentTexturePath = move(sNewMaterial.sTransparentTexturePath);
			this->sNormalMapTexturePath = move(sNewMaterial.sNormalMapTexturePath);

			memcpy_s(this->vAmbientColor, sizeof(this->vAmbientColor), sNewMaterial.vAmbientColor, sizeof(sNewMaterial.vAmbientColor));
			memcpy_s(this->vDiffuseColor, sizeof(this->vDiffuseColor), sNewMaterial.vDiffuseColor, sizeof(sNewMaterial.vDiffuseColor));
			memcpy_s(this->vSpeculerColor, sizeof(this->vSpeculerColor), sNewMaterial.vSpeculerColor, sizeof(sNewMaterial.vSpeculerColor));

			this->nSpecularExponent = sNewMaterial.nSpecularExponent;
			this->nTransparent = sNewMaterial.nTransparent;

			this->pDiffuseTexture = sNewMaterial.pDiffuseTexture;
			this->pSpecularTexture = sNewMaterial.pSpecularTexture;
			this->pSpecularHighlightTexture = sNewMaterial.pSpecularHighlightTexture;
			this->pTransparentTexture = sNewMaterial.pTransparentTexture;
			this->pNormalMapTexture = sNewMaterial.pNormalMapTexture;

			return *this;
		}

		Material &Material::operator=(const Material &sNewMaterial)
		{
			TextureManager &sTextureManager = TextureManager::getManager();

			if(!this->sDiffuseTexturePath.empty())
				sTextureManager.releaseTexture(this->sDiffuseTexturePath);

			if(!this->sSpecularTexturePath.empty())
				sTextureManager.releaseTexture(this->sSpecularTexturePath);

			if(!this->sSpecularHighlightTexturePath.empty())
				sTextureManager.releaseTexture(this->sSpecularHighlightTexturePath);

			if(!this->sTransparentTexturePath.empty())
				sTextureManager.releaseTexture(this->sTransparentTexturePath);

			if(!this->sNormalMapTexturePath.empty())
				sTextureManager.releaseTexture(this->sNormalMapTexturePath);

			this->sMaterialName = sNewMaterial.sMaterialName;
			this->sDiffuseTexturePath = sNewMaterial.sDiffuseTexturePath;
			this->sSpecularTexturePath = sNewMaterial.sSpecularTexturePath;
			this->sSpecularHighlightTexturePath = sNewMaterial.sSpecularHighlightTexturePath;
			this->sTransparentTexturePath = sNewMaterial.sTransparentTexturePath;
			this->sNormalMapTexturePath = sNewMaterial.sNormalMapTexturePath;

			memcpy_s(this->vAmbientColor, sizeof(this->vAmbientColor), sNewMaterial.vAmbientColor, sizeof(sNewMaterial.vAmbientColor));
			memcpy_s(this->vDiffuseColor, sizeof(this->vDiffuseColor), sNewMaterial.vDiffuseColor, sizeof(sNewMaterial.vDiffuseColor));
			memcpy_s(this->vSpeculerColor, sizeof(this->vSpeculerColor), sNewMaterial.vSpeculerColor, sizeof(sNewMaterial.vSpeculerColor));

			this->nSpecularExponent = sNewMaterial.nSpecularExponent;
			this->nTransparent = sNewMaterial.nTransparent;

			this->pDiffuseTexture = this->sDiffuseTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sDiffuseTexturePath, TexIntFormat::Int_RGB);
			this->pSpecularTexture = this->sSpecularTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sSpecularTexturePath, TexIntFormat::Int_RGB);
			this->pSpecularHighlightTexture = this->sSpecularHighlightTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sSpecularHighlightTexturePath, TexIntFormat::Int_RGB);
			this->pTransparentTexture = this->sTransparentTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sTransparentTexturePath, TexIntFormat::Int_RGB);
			this->pNormalMapTexture = this->sNormalMapTexturePath.empty() ? nullptr : sTextureManager.getTexture(this->sNormalMapTexturePath, TexIntFormat::Int_RGB);

			return *this;
		}
	}
}

#endif