
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_MANAGER_CPP

#define _PHS_TEXTURE_MANAGER_CPP

#include "PHsTextureManager.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using namespace std;

		TextureManager::TextureManager()
		{
			FreeImage_Initialise();
		}

		TextureManager::~TextureManager()
		{
			FreeImage_DeInitialise();
		}

		Texture2D *TextureManager::getTexture(const wstring &sNewTexturePath, TexIntFormat eNewInternalFormat)
		{
			auto iIndex = this->sTextureHandleMap.find(sNewTexturePath);

			if(iIndex != this->sTextureHandleMap.end())
			{
				++iIndex->second.nReferenceCount;
				return &iIndex->second.sTexture2D;
			}

			FREE_IMAGE_FORMAT eFileFormat = FreeImage_GetFileTypeU(sNewTexturePath.c_str());

			if(eFileFormat == FREE_IMAGE_FORMAT::FIF_UNKNOWN)
				eFileFormat = FreeImage_GetFIFFromFilenameU(sNewTexturePath.c_str());

			if(eFileFormat == FREE_IMAGE_FORMAT::FIF_UNKNOWN)
				return nullptr;

			if(!FreeImage_FIFSupportsReading(eFileFormat))
				return nullptr;

			FIBITMAP *pBitmap = FreeImage_LoadU(eFileFormat, sNewTexturePath.c_str());

			if(!pBitmap)
				return nullptr;

			Byte *pBit = FreeImage_GetBits(pBitmap);
			uInt nWidth = FreeImage_GetWidth(pBitmap);
			uInt nHeight = FreeImage_GetHeight(pBitmap);

			if(!pBit || !nWidth || !nHeight)
			{
				FreeImage_Unload(pBitmap);
				return nullptr;
			}

			if(FreeImage_GetImageType(pBitmap) != FREE_IMAGE_TYPE::FIT_BITMAP)
			{
				FreeImage_Unload(pBitmap);
				return nullptr;
			}

			if(FreeImage_GetColorType(pBitmap) != FREE_IMAGE_COLOR_TYPE::FIC_RGB)
			{
				FreeImage_Unload(pBitmap);
				return nullptr;
			}
			
			iIndex = this->sTextureHandleMap.emplace(sNewTexturePath, TextureHandle()).first;

			iIndex->second.sTexture2D.initializeTexture();
			iIndex->second.nReferenceCount = 1u;
			Texture2D::activeTexture(iIndex->second.sTexture2D);
			Texture2D::specifyTextureTexel(nWidth, nHeight, eNewInternalFormat, Endianness::littleEndian() ? TexExtFormat::Ext_BGR : TexExtFormat::Ext_RGB, TexTexelType::TexelType_uByte, pBit);
			Texture2D::specifyTextureMinifyingFilter(this->eMinTexelFilter, this->eMinMipmapFilter);
			Texture2D::specifyTextureMagnificationFilter(this->eMagTexelFilter);
			Texture2D::specifyTextureSWrappingMode(this->eSWrappingMode);
			Texture2D::specifyTextureTWrappingMode(this->eTWrappingMode);
			Texture2D::specifyTextureAnisotropicMode(this->nAnistropicMode);

			FreeImage_Unload(pBitmap);

			return &iIndex->second.sTexture2D;
		}

		Void TextureManager::releaseTexture(const wstring &sNewTexturePath)
		{
			auto iIndex = this->sTextureHandleMap.find(sNewTexturePath);

			if(iIndex != this->sTextureHandleMap.end())
			{
				if(!--iIndex->second.nReferenceCount)
					this->sTextureHandleMap.erase(iIndex);
			}
		}
	}
}

#endif